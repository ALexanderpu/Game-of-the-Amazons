#ifndef _DEFINE_H_
#define _DEFINE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> 
#include <time.h>
#include <queue>

using namespace std;


/*
��ע
(1)����ϵ��ԭ���������Ͻǣ�x�������꣨��x�У�y�Ǻ����꣨��y�У�
(2)���ǿ����������ɾ�����ͷ�ļ�������ݣ�ע����ĺ��Ҫ�����µ�define��֪ͨ������
(3)һЩ˽�еĳ�������ͷŵ����Ǹ��Ե�ͷ�ļ�����еķ����
*/


#define  MAXMOVE    3000     //һ����ֵ�����з�����
#define  MAX_VALUE  9999999    //���������ֵ 
#define  MAX_DEEP   3         //�������Ĵ����
#define  TURNROLE   3
#define  INF        1000000000

#define K 1
#define Q 1

#define INAREA(x,y) (((x)>=0) && ((y)>=0) && ((x)<10) && ((y)<10))

//���̳�������

#define   MAXSIZE   10        //���̴�С10*10�±�0-9
#define   NOSTONE   0         //������
#define   RED       1         //�췽����
#define   WHITE     2         //�׷�����
#define   OBSTACLE  3         //�ϰ�
#define   BORAD     4         //�߽�

struct queuenode {			//bfs���нڵ�
	int x,y;				//����
};			

//�ŷ�����


typedef struct 
{
	int x[3];                 //x[0] �������x�����ꡢx[1]�������x�����ꡢx[2]�ϰ�����
    int y[3];                 //y[0] �������y�����ꡢy[1]�������y�����ꡢy[2]�ϰ�����	
	int score;
}MoveType;
//�����Լ���
extern int maxdeep;							//������				
extern MoveType movestack[MAX_DEEP][3000];	//ȫ���з�ջ
//���̶���
typedef   int MapType[MAXSIZE][MAXSIZE];        //����
extern    int dir[8][2];
extern    int history[10][10][10][10][10][10];  //��¼��ʷ�÷�
extern    int ourcolor;                         //��¼�ҷ���ɫ
extern    int posx[8];                          //��¼�˸��ӵ�λ�ã�ǰ4���Ǻ췽����4���ǰ׷�
extern    int posy[8];                          //��¼�˸��ӵ�λ�ã�ǰ4���Ǻ췽����4���ǰ׷�
extern    int step;
extern    MapType map;
extern    int ourmap[MAXSIZE][MAXSIZE];				//�ҷ���������ͼ����¼kingmove��queenmove�Ľ����
extern    int enemymap[MAXSIZE][MAXSIZE];             //�з���������ͼ����¼kingmove��queenmove�Ľ����		
extern    queuenode que[MAXMOVE];  //����bfs����
extern    queuenode start;
extern    queuenode q;
extern    queuenode n ;
extern FILE *engine_output;		//�������
extern char filename[100];
extern FILE *fperror;
extern FILE *fp;

#endif
