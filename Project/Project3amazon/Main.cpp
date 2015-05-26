#ifndef _MAIN_CPP_
#define _MAIN_CPP_

#include "define.h"
#include "SearchEngine.h"
#include "Createmove.h"

//ȫ�ֱ���
queuenode     que[MAXMOVE];
queuenode     start;
queuenode     temp;
queuenode     n ;
int         ourmap[MAXSIZE][MAXSIZE];
int         enemymap[MAXSIZE][MAXSIZE]; 
MoveType	  movestack[MAX_DEEP][3000];				//ȫ���з�ջ
MapType       map;                        //��¼������Ϣ
//queuenode     queue[1000];					//����bfs����
MoveType      bestMove;	 				   //���ص�����з�
int           ourcolor;                    //��¼�ҷ�������ɫ
int           posx[8] = {0,0,3,3,6,6,9,9}; //��¼�˸��ӵ�λ�ã�ǰ4���Ǻ췽����4���ǰ׷�
int           posy[8] = {3,6,0,9,0,9,3,6}; //��¼�˸��ӵ�λ�ã�ǰ4���Ǻ췽����4���ǰ׷�
int           dir[8][2]={{-1,0},{-1,-1},{-1,1},{0,1},{0,-1},{1,-1},{1,1},{1,0}};
int           history[10][10][10][10][10][10];    //��¼��ʷ�÷�
//��ʼ������ 
void  init_map()
{
	int i;
	memset(map,NOSTONE,sizeof(map));
	for (i = 0; i<4; i++)
	{
		map[posx[i]][posy[i]] = RED;
		map[posx[i+4]][posy[i+4]] = WHITE;
	}
}

void load_map()
{
	int whitechess,redchess,i,j;
	
	for (i = 0; i<MAXSIZE; i++)
		for (j = 0; j<MAXSIZE; j++)
			scanf("%d",map[i][j]);
	whitechess = 4;
	redchess = 0;
	for (i = 0; i<MAXSIZE; i++)
		for (j = 0; j<MAXSIZE; j++)
			if (map[i][j] == RED)
			{
				posx[redchess] = i;
				posy[redchess] = j;
				redchess++;
			}
			else if (map[i][j] == WHITE)
			{
				posx[whitechess] = i;
				posy[whitechess] = j;
				whitechess++;
			}
}

//�ƶ����Ӹ�������
void movechess(MoveType nowmove)
{
	for (int i = 0; i<8; i++)
		if (posx[i] == nowmove.x[0] && posy[i] == nowmove.y[0])
		{
			posx[i] = nowmove.x[1];
			posy[i] = nowmove.y[1];
		}
	map[nowmove.x[1]][nowmove.y[1]] = map[nowmove.x[0]][nowmove.y[0]];
	map[nowmove.x[0]][nowmove.y[0]] = NOSTONE;
	map[nowmove.x[2]][nowmove.y[2]] = OBSTACLE;

}

void unmovechess(MoveType nowmove)
{
	for (int i = 0; i<8; i++)
		if (posx[i] == nowmove.x[1] && posy[i] == nowmove.y[1])
		{
			posx[i] = nowmove.x[0];
			posy[i] = nowmove.y[0];
		}
	map[nowmove.x[2]][nowmove.y[2]] = NOSTONE;
	map[nowmove.x[0]][nowmove.y[0]] = NOSTONE;
	map[nowmove.x[0]][nowmove.y[0]] = map[nowmove.x[1]][nowmove.y[1]];
	map[nowmove.x[1]][nowmove.y[1]] = NOSTONE;

}



//����move ����
void cmd_move()
{
	char move[] = "move AAAAAA\n";	//�߷�
    if (search_a_goodmove(ourcolor,&bestMove,-INF-1,INF,0))
	{
		//���ŷ���¼��������
		movechess(bestMove);

		//���ŷ�ת����Ҫ���͵��ַ���ʽ
		move[5]  = bestMove.x[0] + 'A';
		move[6]  = bestMove.y[0] + 'A';
		move[7]  = bestMove.x[1] + 'A';
		move[8]  = bestMove.y[1] + 'A';
		move[9]  = bestMove.x[2] + 'A';
		move[10] = bestMove.y[2] + 'A';

		//������Ϣ
		printf ("%s",move);

		fflush(stdout);

	}
}
   
int main() {

	char Msg[500] = {0};		//������յ�����Ϣ
	char name[] = "name stdAmazon(1.0)\n";	//������Ϣ
	
    init_map();

	while (1)
	{
		//ѭ�����ղ���ƽ̨���͵���Ϣ
		//ע����Ҫ���͵��ַ���Ӧ����'\n'����������ƽ̨�Ż���Ϊ��һ������������
		//��������Ҫ����fflush(stdout)��������������ʹ�ַ����������������ƽ̨

		memset(Msg,0,500);
		scanf("%s",Msg);
		
		if (strcmp(Msg,"name?") == 0)
		{
			//name?
			printf("%s",name);
			fflush(stdout);	
			continue;
		}
		if (strcmp(Msg,"stop") == 0)
		{

			fflush(stdout);	
			return 0;
		}


		if (strcmp(Msg,"new") == 0)
		{			
			init_map();//��ʼ������

			scanf("%s",Msg);
			
			if (strcmp(Msg,"white") == 0)
			{
				//new white
				ourcolor = WHITE;
				cmd_move(); //�׷����ߣ�����������һ���߷�
				continue;
			}
			else
			{
				//new red
				ourcolor = RED;
				continue;
			}

			continue;
		}

		if (strcmp(Msg,"move") == 0)
		{
		    //move
			scanf("%s",Msg);
			if (Msg[6] == '\0')
			{
				//move XX\n
				bestMove.x[0] = Msg[0] - 'A';
				bestMove.y[0] = Msg[1] - 'A';
				bestMove.x[1] = Msg[2] - 'A';
				bestMove.y[1] = Msg[3] - 'A';
				bestMove.x[2] = Msg[4] - 'A';
				bestMove.y[2] = Msg[5] - 'A';	
				//ִ�жԷ��з�
				movechess(bestMove);
			}
			cmd_move();
			continue;
		}

		if (strcmp(Msg,"load") == 0)
			load_map();

	}

	return 0;
}
#endif