#ifndef _EVALUATE_CPP_
#define _EVALUATE_CPP_

#include "Evaluate.h"

//初始化改成和ANDY一样才能这么用。
//初始化时，起始点为0，其余的为无穷。
int qhead,qrear;
int sum1,sum2;
int KingMove()
{
	int i,j;
	for (i=0; i<MAXSIZE; ++i) 
	{
		for (j=0; j<MAXSIZE; ++j) 
		{
			if(map[i][j]==2) ourmap[i][j]=0;
			else ourmap[i][j]=INF;
			if(map[i][j]==1) enemymap[i][j]=0;
			else enemymap[i][j]=INF;
		}
	}
	qhead=qrear=0;
	for (i=4;i<8;i++)//处理白方
	{
		que[qrear].x=posx[i];
		que[qrear].y=posy[i];
		qrear=(qrear+1);
	}
	while (qrear!=qhead)
	{
		n=que[qhead];
		qhead=(qhead+1);
		for (i=0;i<8;i++)
		{
			temp.x=n.x+dir[i][0];
			temp.y=n.y+dir[i][1];
			if (temp.x>=0&&temp.y>=0&&temp.x<=9&&temp.y<=9&&map[temp.x][temp.y]==NOSTONE&&ourmap[n.x][n.y] + 1 < ourmap[temp.x][temp.y])//在边界内，没有障碍，而且可以更新。
			{
				ourmap[temp.x][temp.y] = ourmap[n.x][n.y] + 1;
				que[qrear]=temp;
				qrear=(qrear+1);
			}
		}

	}
	qhead=qrear=0;
	for (i=0;i<4;i++)//处理红方
	{
		que[qrear].x=posx[i];
		que[qrear].y=posy[i];
		qrear=(qrear+1);
	}
	while (qrear!=qhead)
	{
		n=que[qhead];
		qhead=(qhead+1);
		for (i=0;i<8;i++)
		{
			temp.x=n.x+dir[i][0];
			temp.y=n.y+dir[i][1];
			if (temp.x>=0&&temp.y>=0&&temp.x<=9&&temp.y<=9&&map[temp.x][temp.y]==NOSTONE&&enemymap[n.x][n.y] + 1 < enemymap[temp.x][temp.y])//在边界内，没有障碍，而且可以更新。
			{
				enemymap[temp.x][temp.y] = enemymap[n.x][n.y] + 1;
				que[qrear]=temp;
				qrear=(qrear+1);
			}
		}

	}
	//计算结果
	sum1=0;
	for (i=0; i<MAXSIZE; ++i)
		for (j=0; j<MAXSIZE; ++j) {
			if(enemymap[i][j] > ourmap[i][j]) sum1+=1;
			if(enemymap[i][j] < ourmap[i][j]) sum1-=1;
		}
	return sum1;

}

int QueenMove()
{
	int i,j;//初始化
	for (i=0; i<MAXSIZE; ++i) 
	{
		for (j=0; j<MAXSIZE; ++j) 
		{
			if(map[i][j]==2) ourmap[i][j]=0;
			else ourmap[i][j]=INF;
			if(map[i][j]==1) enemymap[i][j]=0;
			else enemymap[i][j]=INF;
		}
	}
	qhead=qrear=0;
	for (i=4;i<8;i++)//处理白方
	{
		que[qrear].x=posx[i];
		que[qrear].y=posy[i];
		qrear=(qrear+1);
	}
	while (qrear!=qhead)
	{
		n=que[qhead];
		qhead=(qhead+1);
		for (i=0; i<8; ++i) 
		{		//八个方向探测
			for (j=1;j<=9;j++) 
			{
				temp.x=n.x + j*dir[i][0];
				temp.y=n.y + j*dir[i][1];
				if (temp.x>=0&&temp.y>=0&&temp.x<=9&&temp.y<=9&&map[temp.x][temp.y]==NOSTONE)
				{
					if (ourmap[n.x][n.y] + 1 < ourmap[temp.x][temp.y])
					{
					ourmap[temp.x][temp.y] = ourmap[n.x][n.y] + 1;
						que[qrear]=temp;
						qrear=(qrear+1);
					}
				}
				else break;
			}
		}
	}
	qhead=qrear=0;
	for (i=0;i<4;i++)//处理红方
	{
		que[qrear].x=posx[i];
		que[qrear].y=posy[i];
		qrear=(qrear+1);
	}
	while (qrear!=qhead)
	{
		n=que[qhead];
		qhead=(qhead+1);
		for (i=0; i<8; ++i) 
		{		//八个方向探测
			for (j=1;j<=9;j++) 
			{
				temp.x=n.x + j*dir[i][0];
				temp.y=n.y + j*dir[i][1];
				if (temp.x>=0&&temp.y>=0&&temp.x<=9&&temp.y<=9&&map[temp.x][temp.y]==NOSTONE)
				{
					if (enemymap[n.x][n.y] + 1 < enemymap[temp.x][temp.y])
					{
						enemymap[temp.x][temp.y] = enemymap[n.x][n.y] + 1;
						que[qrear]=temp;
						qrear=(qrear+1);
					}
				}
				else break;
			}
		}
	}
	//计算和
	sum2=0;
	for (i=0; i<MAXSIZE; ++i)
		for (j=0; j<MAXSIZE; ++j) {
			if(enemymap[i][j] > ourmap[i][j]) sum2+=1;
			if(enemymap[i][j] < ourmap[i][j]) sum2-=1;
		}
	return sum2;
}


int evaluate(int color)
{
	memset(que,0,sizeof(que));

	sum2=QueenMove();
	sum1=KingMove();
	if (color==1) return -(sum1+sum2);
	else return (sum1+sum2);
}



#endif