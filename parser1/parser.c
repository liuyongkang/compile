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
		if (isdigit(lookahead)) {
			printf("\n只支持一位数\n");
			exit(1);
		}
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
		case '\n':
			return;
		default:
			printf("\n语法错误，含有非法字符\n");
			exit(1);
		}
	}
}

void term()
{
	if (isdigit(lookahead)) {
		printf("%c", lookahead);
		match(lookahead);
	} else {
		printf("\n语法错误，缺少操作数\n");
		exit(1);
	}
}

void match(char t)
{
	if (lookahead == t) {
		scanf("%c", &lookahead);
	} else {
		printf("\n只支持一位数\n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	scanf("%c", &lookahead);
	expr();
	printf("\n");

	return 0;
}
