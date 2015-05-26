#ifndef _SEARCHENGINE_H_
#define _SEARCHENGINE_H_

#include "define.h"
#include "Main.h"
#include "Evaluate.h"
#include "Createmove.h"
#define  MAXMOVE    3000     //一个棋局的最大招法个数
#define  MAX_VALUE  9999999    //评估的最大值 
#define  TURNROLE   3
#define  INF        1000000000
extern    MoveType movestack[MAX_DEEP][3000];	//全局招法栈
extern MapType map;
//SearchEngine.cpp中的函数声明
int search_a_goodmove(int color, MoveType * bestMove,int alpha,int beta,int dep);
int alpha_beta(int color,int alpha,int beta,int depth);

#endif