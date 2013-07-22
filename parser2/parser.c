/*
 * =====================================================================================
 *
 *       Filename:  parser.c
 *
 *        Version:  1.0
 *        Created:  2013年07月20日 19时01分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nick (LiuYongkang), liuyongkanglinux@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char lookahead;
char s[MAX];

void expr()
{
	factor();
	while(s[lookahead]) {
		switch(s[lookahead]) {
			case '+':
				match('+');
				term();
				printf("+");
				break;
			case '-':
				match('-');
				term();
				printf("-");
				break;
			case '*':
			case '/':
				term();
				break;
			case ')':
				return;
		}
	}	
}

void term()
{
	factor();
	while (s[lookahead]) {
		switch(s[lookahead]) {
			case '*':
				match('*');
				factor();
				printf("*");
				break;
			case '/':
				match('/');
				factor();
				printf("/");
				break;
			default:
				factor();
				return;
		}
	}
}

void factor()
{
	switch(s[lookahead]) {
		case '(':
			match('(');
			expr();
			match(')');
			break;
		default:
			if (isdigit(s[lookahead])) {
				printf("%c", s[lookahead]);
				match(s[lookahead]);
			}
	}
}

void match(char t)
{
	if (s[lookahead] == t) {
		++lookahead;
	} else {
		printf("\nsyntax error\n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	scanf("%s", s);
	lookahead = 0;
	expr();
	printf("\n");

	return 0;
}
