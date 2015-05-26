#ifndef _CREATEMOVE_CPP_
#define _CREATEMOVE_CP_


#include "Createmove.h"

int createmove(int color,int depth)
{
	int stacklen=0;
	int i,ii,j,k,jj,kk;
	int tx,ty,ttx,tty;
	//�����ҷ���ɫѡ��
	if(color==RED) i=0,ii=4;
	else i=4,ii=8; 
	if (color==WHITE)
	{
		for (; i<ii; ++i) {
			map[posx[i]][posy[i]]=NOSTONE;		//���ߵĵ��ÿ�

			for (j=0; j<8; ++j) {				//8������
				for (k=1; ; ++k) {				//̽��ĳ���
					tx=posx[i] + k*dir[j][0];
					ty=posy[i] + k*dir[j][1];
					if(!INAREA(tx,ty) || (INAREA(tx,ty) && map[tx][ty]!=NOSTONE)) break; //�����ϰ���߽磬��ֹ�÷����̽��
					for (jj=0; jj<8; ++jj) {
						for (kk=1; ; ++kk) {
							ttx=tx + kk*dir[jj][0];
							tty=ty + kk*dir[jj][1];
							if(!INAREA(ttx,tty) || (INAREA(ttx,tty) && map[ttx][tty]!=NOSTONE)) break; //�����ϰ���߽磬��ֹ�÷����̽��
							movestack[depth][stacklen].x[0]=posx[i];
							movestack[depth][stacklen].y[0]=posy[i];
							movestack[depth][stacklen].x[1]=tx;
							movestack[depth][stacklen].y[1]=ty;
							movestack[depth][stacklen].x[2]=ttx;
							movestack[depth][stacklen++].y[2]=tty;
						}
					}
				}
			}
			map[posx[i]][posy[i]]=color;		//�ָ����ߵĵ�
		}
	}
	else
	{
		for (; i<ii; ++i) {
			map[posx[i]][posy[i]]=NOSTONE;		//���ߵĵ��ÿ�

			for (j=7; j>=0; --j) {				//8������
				for (k=1; ; ++k) {				//̽��ĳ���
					tx=posx[i] + k*dir[j][0];
					ty=posy[i] + k*dir[j][1];
					if(!INAREA(tx,ty) || (INAREA(tx,ty) && map[tx][ty]!=NOSTONE)) break; //�����ϰ���߽磬��ֹ�÷����̽��
					for (jj=0; jj<8; ++jj) {
						for (kk=1; ; ++kk) {
							ttx=tx + kk*dir[jj][0];
							tty=ty + kk*dir[jj][1];
							if(!INAREA(ttx,tty) || (INAREA(ttx,tty) && map[ttx][tty]!=NOSTONE)) break; //�����ϰ���߽磬��ֹ�÷����̽��
							movestack[depth][stacklen].x[0]=posx[i];
							movestack[depth][stacklen].y[0]=posy[i];
							movestack[depth][stacklen].x[1]=tx;
							movestack[depth][stacklen].y[1]=ty;
							movestack[depth][stacklen].x[2]=ttx;
							movestack[depth][stacklen++].y[2]=tty;
						}
					}
				}
			}
			map[posx[i]][posy[i]]=color;		//�ָ����ߵĵ�
		}
	}
	return stacklen;
}
#endif