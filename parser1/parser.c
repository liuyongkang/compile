/*
 * =====================================================================================
 *
 *       Filename:  parser.c
 *
 *        Version:  1.0
 *        Created:  2013年07月20日 17时12分20秒
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

void expr()
{
	term();
	while (1) {
		switch(lookahead) {
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
		default:
			return;
		}
	}
}

void term()
{
	if (isdigit(lookahead)) {
		printf("%c", lookahead);
		match(lookahead);
	} else {
		printf("syntax error");
		exit(1);
	}
}

void match(char t)
{
	if (lookahead == t) {
		scanf("%c", &lookahead);
	} else {
		printf("syntax error");
		exit(2);
	}
}

int main(int argc, char *argv[])
{
	scanf("%c", &lookahead);
	expr();
	printf("\n");

	return 0;
}

