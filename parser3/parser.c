// =====================================================================================
// 
//       Filename:  parser.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年01月28日 12时43分15秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Nick (LiuYongkang), liuyongkanglinux@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void parse(state *s)
{
	int len;

	if (isdigit(s->p[s->pos])) {
		sscanf(&s->p[s->pos], "%lf%n", &s->val, &len);
		s->pos += len;
		s->next = NUM;
	} else {
		switch (s->p[s->pos]) {
		case '+':
			s->next = ADD;
			break;
		case '-':
			s->next = SUB;
			break;
		case '*':
			s->next = MUL;
			break;
		case '/':
			s->next = DIV;
			break;
		case '(':
			s->next = LBR;
			break;
		case ')':
			s->next = RBR;
			break;
		case '\n':
			s->next = END;
			break;
		default:
			break;
		}
		++s->pos;
	}
}

val_t F(state *s)
{
	val_t val;

	switch (s->next) {
	case LBR:
		parse(s);
		val = E(s);

		if (s->next != RBR) {
			if (s->err == NO) {
				s->err = LACK_RBR;
				s->next = ERR;
			}
			return 0;
		}
		parse(s);
		return val;
	case NUM:
		parse(s);
		return s->val;
	case RBR:
	case ADD:
	case SUB:
	case MUL:
	case DIV:
	case END:
		s->err = LACK_OPD;
		s->next = ERR;
		break;
	}
	return 0;
}

val_t T_(state *s)
{
	val_t val = s->val;

	switch(s->next) {
	case MUL:
		parse(s);
		s->val = val * F(s);
		return T_(s);
	case DIV:
		parse(s);
		s->val = val / F(s);
		return T_(s);
	case ADD:
	case SUB:
	case RBR:
	case END:
	case ERR:
		break;
	case LBR:
		s->err = LACK_OPT;
		s->next = ERR;
		break;
	}
	return val;
}

val_t T(state *s)
{
	switch (s->next) {
	case LBR:
	case NUM:
		s->val = F(s);
		return T_(s);
	case END:
	case ERR:
		break;
	case ADD:
	case SUB:
	case MUL:
	case DIV:
	case RBR:
		s->err = LACK_OPD;
		s->next = ERR;
		break;
	}
	return 0;
}

val_t E_(state *s)
{
	val_t val = s->val;

	switch (s->next) {
	case ADD:
		parse(s);
		s->val = val + T(s);
		return E_(s);
	case SUB:
		parse(s);
		s->val = val - T(s);
		return E_(s);
	case RBR:
	case END:
	case ERR:
		break;
	case LBR:
	case NUM:
		s->err = LACK_OPT;
		s->next = ERR;
		break;
	}
	return val;
}

val_t E(state *s)
{
	switch (s->next) {
	case LBR:
	case NUM:
		s->val = T(s);
		return E_(s);
	case END:
	case ERR:
		break;
	case ADD:
	case SUB:
	case MUL:
	case DIV:
	case RBR:
		s->err = LACK_OPD;
		s->next = ERR;
		break;
	}
	return 0;
}

int main(void)
{
	char str[n];

	char *err_msg[] = {"",
			   "lack operand",
			   "lack operator",
			   "lack left bracket",
			   "lack right bracket"};

	printf(">");
	while(fgets(str, n, stdin)) {
		state s = {str, 0, 0, NO, 0};
		parse(&s);
		E(&s);
		
		if (!s.err && s.next != END) {
			s.err = LACK_LBR;
		}

		if (s.err) {
			printf("%s%*c  %s\n>", s.p, s.pos, '^', err_msg[s.err]);
		} else {
			printf("%lf\n>", s.val);
		}
	}

	return 0;
}

