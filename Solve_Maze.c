#include <stdio.h>
#include <stdlib.h>
#define R 7
#define C 8

//挂链节点
typedef struct ppnode{
	int x;
	int y;
	ppnode * pre;
	ppnode * next;
}ppnode;

//主链表节点 
typedef struct spnode{
	int sum; //路线长度 
	spnode * next;
	ppnode * line;
}spnode;  

//Maze_map 
int M[R+2][C+2]={{1,1,1,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1,1,1},{1,0,0,0,1,1,1,1,1,1},{1,0,1,0,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,1,1},{1,1,1,1,1,1,1,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
//Maze_mark
int t[R+2][C+2]={{1,1,1,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1,1,1},{1,0,0,0,1,1,1,1,1,1},{1,0,1,0,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,1,1},{1,1,1,1,1,1,1,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
//方向路径 
int move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
/*
	迷宫 
	0 1 1 1 1 1 1 1
	0 1 1 1 1 1 1 1
	0 0 0 1 1 1 1 1
	0 1 0 1 1 1 1 1 
	0 0 0 1 1 1 1 1
	0 0 0 0 0 0 0 1
	1 1 1 1 1 1 0 0
*/
int path[56][2],top=0;//记录每条路径的栈

//初始化记录所有路线的数组 ,sp为最终头结点指针，p为可移动指针 
spnode * sp=*p=(spnode *)malloc(sizeof(spnode));
sp->sum=-1;
sp->next=sp->line=NULL;

 
//求解路径 
int Maze(int x, int y)
{
	
	if(x==7 && y==8){
		int i;
		ppnode * pp=*pp1=NULL;
		p->line=pp;//挂链 
		
		for(i=1 ; i<=top ; i++)
		{
			//写入链表
			pp=(ppnode *)malloc(sizeof(ppnode));
			pp->x=path[i][0];
			pp->y=path[i][1];
			pp->pre=pp1;
			pp1=pp;
			pp=pp->next=NULL;
		}
	}
	else{
		//跑路径 
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
				//Stack Pop  抹除标记 
				top--;
				t[a][b]=0; 
			} 
			 
		}
	}
}
int main(main)
{
	
	//运行迷宫求解函数 
	int tag=Maze(1,1);
	//输出所有路径并求出最优解
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
