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

#ifndef PARSER_H_
#define PARSER_H_

/*判断表达式*/
void expr();

/*剩余部分*/
void rest();

/*判断词法单元*/
void term();

/*匹配词法单元*/
void match(char t);

#endif // PARSER_H_

