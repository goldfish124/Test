#include <stdio.h>
#include <stdlib.h>
#define R 7
#define C 8

//�����ڵ�
typedef struct ppnode{
	int x;
	int y;
	ppnode * pre;
	ppnode * next;
}ppnode;

//������ڵ� 
typedef struct spnode{
	int sum; //·�߳��� 
	spnode * next;
	ppnode * line;
}spnode;  

//Maze_map 
int M[R+2][C+2]={{1,1,1,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1,1,1},{1,0,0,0,1,1,1,1,1,1},{1,0,1,0,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,1,1},{1,1,1,1,1,1,1,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
//Maze_mark
int t[R+2][C+2]={{1,1,1,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1,1,1},{1,0,0,0,1,1,1,1,1,1},{1,0,1,0,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,1,1},{1,1,1,1,1,1,1,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
//����·�� 
int move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
/*
	�Թ� 
	0 1 1 1 1 1 1 1
	0 1 1 1 1 1 1 1
	0 0 0 1 1 1 1 1
	0 1 0 1 1 1 1 1 
	0 0 0 1 1 1 1 1
	0 0 0 0 0 0 0 1
	1 1 1 1 1 1 0 0
*/
int path[56][2],top=0;//��¼ÿ��·����ջ

//��ʼ����¼����·�ߵ����� ,spΪ����ͷ���ָ�룬pΪ���ƶ�ָ�� 
spnode * sp=*p=(spnode *)malloc(sizeof(spnode));
sp->sum=-1;
sp->next=sp->line=NULL;

 
//���·�� 
int Maze(int x, int y)
{
	
	if(x==7 && y==8){
		int i;
		ppnode * pp=*pp1=NULL;
		p->line=pp;//���� 
		
		for(i=1 ; i<=top ; i++)
		{
			//д������
			pp=(ppnode *)malloc(sizeof(ppnode));
			pp->x=path[i][0];
			pp->y=path[i][1];
			pp->pre=pp1;
			pp1=pp;
			pp=pp->next=NULL;
		}
	}
	else{
		//��·�� 
		int i,a,b;
		for(i=0; i<4; i++){
			a=x+move[i][0];
			b=y+move[i][1];
			if(!M[a][b] && !t[a][b]){
				
				t[a][b]=1;
				//Stack push
				path[++top][0]=a;
				path[top][1]=b;
				Maze(a,b);
				//Stack Pop  Ĩ����� 
				top--;
				t[a][b]=0; 
			} 
			 
		}
	}
}
int main(main)
{
	
	//�����Թ���⺯�� 
	int tag=Maze(1,1);
	//�������·����������Ž�
	spnode * sp1=sp->next;
	ppnode * pp1;
	while(sp1++){
		pp1=sp->line;
		while(pp1++){
			printf("-(%d,%d)-",pp1->x,pp1->y);
		}
		pp1=NULL;
	}
	 
} 
