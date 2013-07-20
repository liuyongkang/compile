/*
 * =====================================================================================
 *
 *       Filename:  parser.h
 *
 *        Version:  1.0
 *        Created:  2013年07月20日 17时12分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nick (LiuYongkang), liuyongkanglinux@gmail.com
 *        Company:  Class 1107 of Computer Science and Technology
 *
 * =====================================================================================
 */


extern char lookahead; 	//向前看符号

/*判断表达式*/
void expr();

/*判断词法单元*/
void term();

/*匹配词法单元*/
void match(char t);
