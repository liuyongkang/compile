// =====================================================================================
// 
//       Filename:  parser.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年01月28日 12时02分09秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Nick (LiuYongkang), liuyongkanglinux@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef PARSER_H_
#define PARSER_H_

const int n = 256;

typedef double val_t;

typedef enum {
	ADD,
	SUB,
	MUL,
	DIV,
	LBR,
	RBR,
	NUM,
	END,
	ERR
} SYMBOL;

typedef enum {
	NO,
} ERROR;

typedef struct {
	const char *p;
	int pos;
	SYMBOL next;
	ERROR err;
	val_t val;
} state;

val_t E(state *s);
val_t T(state *s);
val_t F(state *s);

#endif // PARSER_H_

