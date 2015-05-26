#ifndef _SEARCHENGINE_CPP_
#define _SEARCHENGINE_CPP_

#include "SearchEngine.h"

//这里写你们搜索函数,函数的参数可以根据自己的需要增减。如果需要的话，也可以增加其他函数。
int cmp(const void *a,const void *b){
	return (((MoveType *)b)->score-((MoveType *)a)->score);
}
int alpha_beta(int color,int alpha,int beta,int depth);
int search_a_goodmove(int color, MoveType * bestMove,int alpha,int beta,int dep) ;
int search_a_goodmove(int color, MoveType * bestMove,int alpha,int beta,int dep) {		//alpha-beta根节点函数
	int i,best=-INF;
	int bestmove=-1;
	memset(history,0,sizeof(history));
	int stacklen=createmove(color,dep);
	if(stacklen==0){
		return 0;
	}
	for(i=0;i<stacklen;i++){
	movestack[dep][i].score=history[movestack[dep][i].x[0]][movestack[dep][i].y[0]][movestack[dep][i].x[1]][movestack[dep][i].y[1]][movestack[dep][i].x[2]][movestack[dep][i].y[2]];
	}
	qsort(movestack[dep],stacklen,sizeof(movestack[dep][0]),cmp);
	for(i=0;i<stacklen;i++){
		movechess(movestack[dep][i]);
		best=-alpha_beta(color^3,-beta,-alpha,dep+1);
		unmovechess(movestack[dep][i]);
		if(best>alpha){
			alpha=best;
			*bestMove=movestack[dep][i];
			bestmove=i;
		}
		if(alpha>=beta){
			bestmove=i;
			break;
		}
	}
	if(bestmove!=-1){
	history[movestack[dep][bestmove].x[0]][movestack[dep][bestmove].y[0]][movestack[dep][bestmove].x[1]][movestack[dep][bestmove].y[1]][movestack[dep][bestmove].x[2]][movestack[dep][bestmove].y[2]]+=2<<(MAX_DEEP-dep);
	}
	return 1;
}
int alpha_beta(int color,int alpha,int beta,int depth){
	int i,best=-INF;
	int bestmove=-1;
	if(depth==MAX_DEEP){  
		return evaluate(color); 
	} 
	int stacklen=createmove(color,depth);
	if(stacklen==0){
		return evaluate(color);
	}
	for(i=0;i<stacklen;i++){
		movestack[depth][i].score=history[movestack[depth][i].x[0]][movestack[depth][i].y[0]][movestack[depth][i].x[1]][movestack[depth][i].y[1]][movestack[depth][i].x[2]][movestack[depth][i].y[2]];
	}
	qsort(movestack[depth],stacklen,sizeof(movestack[depth][0]),cmp);
	for(i=0;i<stacklen;i++){
		movechess(movestack[depth][i]);
		best=-alpha_beta(color^3,-beta,-alpha,depth+1);
		unmovechess(movestack[depth][i]);
		if(best>alpha){
			alpha=best;
			bestmove=i;
		}
		if(alpha>=beta){
			bestmove=i;
			break;
		}
	}
	if(bestmove!=-1){
		history[movestack[depth][bestmove].x[0]][movestack[depth][bestmove].y[0]][movestack[depth][bestmove].x[1]][movestack[depth][bestmove].y[1]][movestack[depth][bestmove].x[2]][movestack[depth][bestmove].y[2]]+=2<<(MAX_DEEP-depth);
	}
	return alpha;
}

#endif