#ifndef _SEARCHENGINE_H_
#define _SEARCHENGINE_H_

#include "define.h"

extern int stacklen;
extern MapType map;

//SearchEngine.cpp�еĺ�������
int search_a_goodmove(int ourcolor, MoveType * bestMove,int alpha,int beta);
int alpha_beta(int color,int alpha,int beta,int depth);

#endif