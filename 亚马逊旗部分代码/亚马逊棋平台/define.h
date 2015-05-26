#ifdef _DEFINE_H_H_
#else
#define _DEFINE_H_H_

/*
��ע
(1)����ϵ��ԭ���������Ͻǣ�x�������꣨��x�У�y�Ǻ����꣨��y�У�
(2)���ǿ����������ɾ�����ͷ�ļ�������ݣ�ע����ĺ��Ҫ�����µ�define��֪ͨ������
(3)һЩ˽�еĳ�������ͷŵ����Ǹ��Ե�ͷ�ļ�����еķ����
*/


#define  MAXMOVE    3000     //һ����ֵ�����з�����
#define  MAX_VALUE  9999999    //���������ֵ 
#define  MAX_DEEP   4         //�������Ĵ����
#define  TURNROLE   3


//���̳�������

#define   MAXSIZE   10        //���̴�С10*10�±�0-9
#define   NOSTONE   0         //������
#define   RED       1         //�췽����
#define   WHITE     2         //�׷�����
#define   OBSTACLE  3         //�ϰ�
#define   BORAD     4         //�߽�

//�ŷ�����
typedef struct 
{
	int x[3];                 //x[0] �������x�����ꡢx[1]�������x�����ꡢx[2]�ϰ�����
    int y[3];                 //y[0] �������y�����ꡢy[1]�������y�����ꡢy[2]�ϰ�����
}MoveType;
//�����Լ���

//�з�ջ����
typedef struct
{
     MoveType chessmove[MAXMOVE];
     int top;
}StackType;

//�ѽṹ����
typedef  struct
{
	int data;                                   //�ؼ���
	int index;                                  //�ؼ�������
}HeapType;

//���̶���
typedef   int MapType[MAXSIZE][MAXSIZE];        //����

extern    int ourcolor;                         //��¼�ҷ���ɫ
extern    int posx[8];                          //��¼�˸��ӵ�λ�ã�ǰ4���Ǻ췽����4���ǰ׷�
extern    int posy[8];                          //��¼�˸��ӵ�λ�ã�ǰ4���Ǻ췽����4���ǰ׷�
extern    int step;


#endif
