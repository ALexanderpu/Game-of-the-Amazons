#ifndef _EVALUATE_H_
#define _EVALUATE_H_

#include "define.h"
int evaluate(int color);
int  QueenMove();
int  KingMove();
int sum(int color);
bool legal(int x,int y);
//extern    queue<queuenode> que;  //����bfs����
extern    queuenode n;
extern    queuenode temp;
extern    int ourmap[MAXSIZE][MAXSIZE];				//�ҷ���������ͼ����¼kingmove��queenmove�Ľ����
extern    int enemymap[MAXSIZE][MAXSIZE]; 
extern    int posy[8];
extern    int posx[8];
#define   MAXSIZE   10        //���̴�С10*10�±�0-9
#define   NOSTONE   0         //������
#define   RED       1         //�췽����
#define   WHITE     2         //�׷�����
#define   OBSTACLE  3         //�ϰ�
#define   BORAD     4         //�߽�
#endif