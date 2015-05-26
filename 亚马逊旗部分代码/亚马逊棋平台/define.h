#ifdef _DEFINE_H_H_
#else
#define _DEFINE_H_H_

/*
备注
(1)坐标系：原点棋盘左上角，x是纵坐标（第x行）y是横坐标（第y行）
(2)你们可以自行填加删除这个头文件里的内容，注意更改后就要发更新的define并通知其他人
(3)一些私有的常量定义就放到你们各自的头文件里，共有的放这里。
*/


#define  MAXMOVE    3000     //一个棋局的最大招法个数
#define  MAX_VALUE  9999999    //评估的最大值 
#define  MAX_DEEP   4         //搜索最大的大深度
#define  TURNROLE   3


//棋盘常量定义

#define   MAXSIZE   10        //棋盘大小10*10下标0-9
#define   NOSTONE   0         //无棋子
#define   RED       1         //红方棋子
#define   WHITE     2         //白方棋子
#define   OBSTACLE  3         //障碍
#define   BORAD     4         //边界

//着法定义
typedef struct 
{
	int x[3];                 //x[0] 棋子起点x轴坐标、x[1]棋子落点x轴坐标、x[2]障碍坐标
    int y[3];                 //y[0] 棋子起点y轴坐标、y[1]棋子落点y轴坐标、y[2]障碍坐标
}MoveType;
//定义自己方

//招法栈定义
typedef struct
{
     MoveType chessmove[MAXMOVE];
     int top;
}StackType;

//堆结构定义
typedef  struct
{
	int data;                                   //关键字
	int index;                                  //关键字索引
}HeapType;

//棋盘定义
typedef   int MapType[MAXSIZE][MAXSIZE];        //棋盘

extern    int ourcolor;                         //记录我方颜色
extern    int posx[8];                          //记录八个子的位置，前4个是红方，后4个是白方
extern    int posy[8];                          //记录八个子的位置，前4个是红方，后4个是白方
extern    int step;


#endif
