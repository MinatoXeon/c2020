#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define For(x,a,b) for(x=a;x<=b;x++)
int i,i1,i2;
int main(void)
{
	//�����ͼ���հ�Ϊ0����Ϊ1��|Ϊ2�����Ϊ3������Ϊ4������趨Ϊ88��
	//�趨�Ʊ������=5,��=6,��=7,��=8,��=9,��=10,��=11,��=12. 
	int maze[23][23]={
	{5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6},
	{2,0,0,0,2,0,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,0,2},
	{2,0,1,1,8,0,1,1,1,1,8,0,2,0,1,1,1,1,12,1,1,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,2},
	{9,1,6,0,5,1,1,1,1,1,1,1,11,1,1,1,6,0,2,0,1,1,10},
	{2,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,2},
	{2,0,2,0,2,0,5,1,1,1,1,1,1,1,1,0,9,1,11,1,6,0,2},
	{2,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,2},
	{2,0,7,1,6,0,2,0,2,0,5,1,12,1,1,0,9,1,1,0,2,0,2},
	{2,0,0,0,2,0,2,0,2,0,2,0,2,0,0,0,2,0,0,0,2,0,2},
	{2,0,2,0,2,0,2,0,2,0,2,0,2,0,5,1,8,0,1,1,10,0,2},
	{2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,0,0,0,0,2,0,2},
	{2,0,2,0,2,0,9,1,11,1,8,0,7,1,8,0,5,1,1,1,10,0,2},
	{2,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,2},
	{2,0,2,0,5,1,10,0,2,0,5,1,1,0,5,1,8,0,2,0,2,0,2},
	{3,0,2,0,2,0,2,0,2,0,2,0,0,0,2,0,0,0,2,0,0,0,4},//�����λ�ڴ��У���16�� 
	{5,1,8,0,2,0,2,0,2,0,7,1,1,1,10,0,2,0,7,1,1,1,6},
	{2,0,0,0,2,0,2,0,2,0,0,0,0,0,2,0,2,0,0,0,0,0,2},
	{2,0,2,0,2,0,7,1,11,1,1,1,6,0,2,0,2,0,5,1,1,0,2},
	{2,0,2,0,0,0,0,0,0,0,0,0,2,0,2,0,2,0,2,0,0,0,2},
	{2,0,7,1,1,1,6,0,1,1,6,0,2,0,2,0,2,0,7,1,1,1,10},
	{2,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,2},
	{7,1,1,1,1,1,11,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,8}
	};
	int former,x,y;
	clock_t start,finish;
	double duration;
	long int count;//��һ��������˵��һ����ɵ�����������򵥵���Ϸ���Ұ���ô�졭��?���㹻�ռ��ֹ������ʧ��ɡ� 
	char empty,direction;
	x=15;
	y=count=0;
	start=clock();
	while(x!=15||y!=22){
		system("CLS");
		printf("����һ���Թ�С��Ϸ����ʹ�÷�������������������п��ơ�\n");
		printf("��E�������λ�ã���O���ǳ���λ�ã�M������ǰ��λ�á�\n"); 
		former=maze[x][y];//former���ڴ�����λ�ô������֡� 
		maze[x][y]=88;//�趨���λ��
		For(i1,0,22){
			For(i2,0,22){
//				switch(maze[i1][i2]){//���ص��� 			//�˷���ʧ���˰������������һ����̯�ӣ�
//					case 0: printf(" "); break;				//�����Լ�¼�ҵ�ʧ�ܡ�
//					case 1: printf("-"); break;
//					case 2: printf("|"); break;
//					case 3: printf("E"); break;
//					case 4: printf("O"); break;
//					case 5: printf("��"); break;
//					case 6: printf("��"); break;
//					case 7: printf("��"); break;
//					case 8: printf("��"); break;
//					case 9: printf("��"); break;
//					case 10: printf("��"); break;
//					case 11: printf("��"); break;
//					case 12: printf("��"); break;
//					case 88: printf("��"); break;
//				}
				switch(maze[i1][i2]){//���ص���  
					case 0: printf(" "); break;	 
					case 1: printf("-"); break;
					case 2: printf("|"); break;
					case 3: printf("E"); break;
					case 4: printf("O"); break;
					case 5: printf("."); break;
					case 6: printf("."); break;
					case 7: printf("."); break;
					case 8: printf("."); break;
					case 9: printf("."); break;
					case 10: printf("."); break;
					case 11: printf("."); break;
					case 12: printf("."); break;
					case 88: printf("M"); break;
				}
			}
			printf("\n");
		}
		maze[x][y]=former;
		printf("���Ѿ�����%d����\n",count);//�������ơ�������ͳ�� 
		empty=getch(); 
		direction=getch();//�������Ҫʹ�������ַ����ܶ��롣��Ϊ��Windows�£�������������ֽ���ɣ��ֱ�Ϊ:'\244'��'\72'up,'\80'down,'\75'left,'\77'right.
		switch(direction){//��ҽ����ƶ� 
			case 72: if(maze[x-1][y]==0){x-=1; count++;} break;//up
			case 80: if(maze[x+1][y]==0){x+=1; count++;} break;//down
			case 77: if(maze[x][y+1]==0||maze[x][y+1]==4){y+=1; count++;} break;//right
			case 75: if(maze[x][y-1]==0&&y!=0){y-=1; count++;} break;//left
		}
	}
	finish=clock();
	duration=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("��ϲ���ɹ��߳��Թ���\n��һ������%d������ʱ%.4f�롣\n",count,duration);
	system("pause");
	return 0;
}
