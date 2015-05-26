#ifndef _EVALUATE_H_
#define _EVALUATE_H_

#include "define.h"
int evaluate(int color);
int  QueenMove();
int  KingMove();
int sum(int color);
bool legal(int x,int y);
//extern    queue<queuenode> que;  //公用bfs队列
extern    queuenode n;
extern    queuenode temp;
extern    int ourmap[MAXSIZE][MAXSIZE];				//我方的搜索地图（记录kingmove、queenmove的结果）
extern    int enemymap[MAXSIZE][MAXSIZE]; 
extern    int posy[8];
extern    int posx[8];
#define   MAXSIZE   10        //棋盘大小10*10下标0-9
#define   NOSTONE   0         //无棋子
#define   RED       1         //红方棋子
#define   WHITE     2         //白方棋子
#define   OBSTACLE  3         //障碍
#define   BORAD     4         //边界
#endif