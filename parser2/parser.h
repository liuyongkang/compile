/*
 * =====================================================================================
 *
 *       Filename:  parser.h
 *
 *        Version:  1.0
 *        Created:  2013年07月20日 18时52分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nick (LiuYongkang), liuyongkanglinux@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */

#define MAX 256

extern char lookahead;

/*匹配expr*/
void expr();

/*匹配term*/
void term();

/*匹配unary*/
void unary();

/*匹配factor*/
void factor();

/*匹配词法单元*/
void match(char t);
