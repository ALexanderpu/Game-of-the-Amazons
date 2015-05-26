#ifndef _CREATEMOVE_H_
#define _CREATEMOVE_H_

#include "define.h"
int createmove(int color,int dep);
#define INAREA(x,y) (((x)>=0) && ((y)>=0) && ((x)<10) && ((y)<10))
extern MapType map;
extern    int dir[8][2];
extern    int posy[8];
extern    int posx[8];
extern    MoveType movestack[MAX_DEEP][3000];	//全局招法栈	
#define   MAXSIZE   10        //棋盘大小10*10下标0-9
#define   NOSTONE   0         //无棋子
#define   RED       1         //红方棋子
#define   WHITE     2         //白方棋子
#define   OBSTACLE  3         //障碍
#define   BORAD     4         //边界

#endif