/*一个循环根据输入菱形行数输出菱形图案*/
#include	<stdio.h>
#include	<math.h>
int	main(void)
{
	int	i,j,k,x;
	printf("请输入菱形的行数(奇数)：");
	scanf("%d",&i);
	x=i;
	for(i=-((x-1)/2);i<(x+1)/2;i++)
	{
		for(j=0;j<abs(i);j++)
			printf(" ");
		for(k=0;k<x-abs(i)*2;k++)
			printf("*");
		printf("\n");
	}
}