#ifndef _CREATEMOVE_H_
#define _CREATEMOVE_H_

#include "define.h"
int createmove(int color,int dep);
#define INAREA(x,y) (((x)>=0) && ((y)>=0) && ((x)<10) && ((y)<10))
extern MapType map;
extern    int dir[8][2];
extern    int posy[8];
extern    int posx[8];
extern    MoveType movestack[MAX_DEEP][3000];	//ȫ���з�ջ	
#define   MAXSIZE   10        //���̴�С10*10�±�0-9
#define   NOSTONE   0         //������
#define   RED       1         //�췽����
#define   WHITE     2         //�׷�����
#define   OBSTACLE  3         //�ϰ�
#define   BORAD     4         //�߽�

#endif