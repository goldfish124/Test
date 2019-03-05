#include <stdlib.h>
#include <stdio.h>
 
int chessboard[12][12] = {0};
 
int cnt = 0;			 
int sum = 0;			 
int move[8][2]={ {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};	 
 
typedef struct {
	int x;
	int y;
}posType;//棋盘上的位置 

typedef struct{ //栈的元素 
	int ord;
	posType seat;
	int di;
}ElemType; 
 
void PrintChess();
 
void Horse(int x,int y); 
 
int main(void){
	int i,j;
	int a,b;
	scanf("%d %d",&a,&b);
	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			if(i==0 || i==1 || i==10 || i==11 || j==0 || j==1 || j==10 || j==11){
				chessboard[i][j]=-1;//在 8 * 8 的外层再加上两层，确保 8 * 8 方格中的每一个格子都有 8 种不同的日字选择 
			}
		}
	}
	 
	chessboard[a+1][b+1] = ++cnt;
	Horse(a+1,b+1);	

	return 0; 
} 
 
void Horse(int x,int y){
	int i;		 
	if(cnt >= 64){		 
		sum++;
		PrintChess();
		exit(0);
		return;
	} 
	for(i=0;i<8;i++){
		int a = x + move[i][0];		 
		int b = y + move[i][1];		   
		if(chessboard[a][b] == 0){	 
			cnt++;					 
			chessboard[a][b]=cnt; 
			Horse(a,b);			 	 
			cnt--;					
			chessboard[a][b]=0; 	  
		}
	}
}
  
//输出 
void PrintChess(){
	int i,j;
	for(i=2;i<10;i++){
		for(j=2;j<10;j++){
			printf("%2d ", chessboard[i][j]);
			
		}
		printf("\n");
	} 
}
