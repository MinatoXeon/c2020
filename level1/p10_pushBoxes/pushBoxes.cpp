#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define For(x,a,b) for(x=a;x<=b;x++)
int i,i1,i2;
int main(void)
{
	start://��goto�����ڴˣ��Խ�����Ϸ�����¿�ʼ�Լ��ؿ�����ѡ�� 
	int map[251][251],mapbackup[251][251];//����һ�����ͼ����ʱ���������ļ������ͼ������ʹ�ö���û��Ҫʹ�ö�̬�����ˣ��˷Ѿ��˷Ѱ�QAQ�� 
	int choice,width,length,number,former,x,y,flag,k,min;
	int xx[30],yy[30],type[30];//type���������ͣ�����Բ�Ļ��Ƿ��ġ�2��Բ�Σ�3�������Σ�4�ǵ����ǡ�xx��yy�����ӹ��޵�λ�á� 
	long int count,hour;//��һ��������˵��һ����ɵ���������Ϸ�����Ұ���ô�졭��?���㹻�ռ��ֹ������ʧ��ɡ�
	char xeon,direction,next,container;
	char user[865];//���Ӽ�¼�û������ܣ�˳���¾�Qualcomm Snapdragon 865 
	clock_t start,finish;
	double duration;
	duration=0.0;//���ĺ��Ѽ�ʱ�������� 
	count=k=min=hour=0;//���ĺ��ѳ���׼ȷ�ļ����������ߣ�Сʱ�ͷ��Ӿ���װ������ 
	FILE *fp, *grd;//���ļ�ר�� 
	printf("����һ����ؿ�����������Ϸ����ѡ����Ҫ����Ĺؿ����˳���\n");
	printf("0.�˳�   1.���⺺   2.����   3.ƽ��   4.������   5.����   6.ר��   7.רҵ   8.��������\n");
	scanf("%d",&choice);
	scanf("%c",&container);//���������ͦ��ֵģ���ȫ���Ǹ���������Ϊ���������Ժ�Ļس���ֱ�ӱ���Ϊ��user��������ˣ�����Ҫ�Ҹ�������������س�
	switch(choice){//������µ�д����һ��ѡ�������ͬʱ���ü���ֹ�����ļ��򿪴��������� 
		case 0: printf("��ӭ��ʱ������ս��\nNever Settle.\n"); exit(0);
		case 1: if((fp=fopen("map-1.txt","r"))==NULL){printf("����Ϸ��ͼ�����ļ����������ԡ�\n"); exit(0);} break;
		case 2: if((fp=fopen("map-2.txt","r"))==NULL){printf("����Ϸ��ͼ�����ļ����������ԡ�\n"); exit(0);} break;
		case 3: if((fp=fopen("map-3.txt","r"))==NULL){printf("����Ϸ��ͼ�����ļ����������ԡ�\n"); exit(0);} break;
		case 4: if((fp=fopen("map-4.txt","r"))==NULL){printf("����Ϸ��ͼ�����ļ����������ԡ�\n"); exit(0);} break;
		case 5: if((fp=fopen("map-5.txt","r"))==NULL){printf("����Ϸ��ͼ�����ļ����������ԡ�\n"); exit(0);} break;
		case 6: if((fp=fopen("map-6.txt","r"))==NULL){printf("����Ϸ��ͼ�����ļ����������ԡ�\n"); exit(0);} break;
		case 7: if((fp=fopen("map-7.txt","r"))==NULL){printf("����Ϸ��ͼ�����ļ����������ԡ�\n"); exit(0);} break;
		case 8: if((fp=fopen("map-8.txt","r"))==NULL){printf("����Ϸ��ͼ�����ļ����������ԡ�\n"); exit(0);} break;
		default: printf("ѡ����ִ��������ԡ�\n"); exit(0);
	}
	printf("�����������û�����\n");
	while((user[k]=getchar())!='\n')k++;
	user[k]='\0';
	fscanf(fp,"%d  %d  %d  %d  %d",&width,&length,&number,&x,&y);//width�ǵ�ͼ�Ŀ�ȣ�length�ǵ�ͼ�ĳ��ȣ�number�����ӵĸ�����x��y��������������ꡣ
	For(i,1,number){
		fscanf(fp,"%d  %d  %d",&xx[i+1],&yy[i+1],&type[i+1]);//��ȡ���ӵ����������� 
	}
	for(i1=0;i1<width;i1++){
		for(i2=0;i2<length;i2++){
			fscanf(fp,"%d",&map[i1][i2]);
		}
	}
	for(i1=0;i1<width;i1++){
		for(i2=0;i2<length;i2++){//��ͼ�������ӱ��ݰ� 
			if(map[i1][i2]==52||map[i1][i2]==53||map[i1][i2]==54) mapbackup[i1][i2]=0;
			else mapbackup[i1][i2]=map[i1][i2];
		}
	}
	if(fclose(fp)){//�رյ�ͼ�ļ���ͬʱ���ü���ֹ�����ļ��رմ���������
		printf("�ر��ļ����ִ�����Ϸ�����˳���\n");
		exit(0);
	}
	start=clock();
	flag=0;
	while(flag==0){
		system("CLS");
		printf("���������ǰ��λ�ã���������ǽ������֮���ʵ��ͼ��Ϊ��Ҫ�ƶ������ӣ���Ӧ����ͼ��Ϊ��Ҫ�Ƶ���λ�á�\n");
		printf("��ʹ�÷�������������������п��ơ�\n");
		former=map[x][y];//former���ڴ�����λ�ô������֡�
		map[x][y]=88;//�趨���λ��
		for(i1=0;i1<width;i1++){//���ص���
			for(i2=0;i2<length;i2++){
				switch(map[i1][i2]){
					case 0: printf("  "); break;//�յ� 
					case 1: printf("��"); break;//ǽ 
					case 2: printf("��"); break;//����һ�����Ӧ���ޣ���������λ����������һλ���� 
					case 52: printf("��"); break;
					case 3: printf("��"); break;//���Ӷ������Ӧ����
					case 53: printf("��"); break;
					case 4: printf("��"); break;//�����������Ӧ����
					case 54: printf("��"); break;
					case 88: printf("��"); break;//���ȵ����ɣ 
				}
			}
			printf("\n");
		}
		map[x][y]=former;
		printf("���Ѿ�����%d����\n",count);//�������ơ�������ͳ��
		printf("���ϣ�����¿�ʼ���밴��Backspace���������ϣ���˳���Ϸ���밴��ESC������\n");
		xeon=getch();//���շ�����ĵ�һ���ַ���ͬʱ�ж��Ƿ������¿�ʼ�����˳���Ϸ����Ը�� 
		if(xeon==8){//Backspace����Ӧ��ASCII��Ϊ8 
			printf("�������������������\n���Ȱ������ȡ�\n");//��������¼ 
			Sleep(2000);
			system("CLS");
			goto start;//�������� 
		}else if(xeon==27){//ESC����Ӧ��ASCII��Ϊ27 
			printf("��ӭ��ʱ������ս��\n����������ľ��ʡ�\n");//��������¼ 
			Sleep(3000);
			exit(0);
		}
		direction=getch();//�������Ҫʹ�������ַ����ܶ��롣��Ϊ��Windows�£�������������ֽ���ɣ��ֱ�Ϊ:'\244'��'\72'up,'\80'down,'\75'left,'\77'right.
		switch(direction){//��ҽ����ƶ� 
			case 72: if(map[x-1][y]==52||map[x-1][y]==53||map[x-1][y]==54){//�ж�����Ϸ��Ƿ������� 
					if(map[x-2][y]==0||map[x-2][y]==2||map[x-2][y]==3||map[x-2][y]==4){//��������ӣ��ж����������ǲ���ǽ�������ӵĹ���
						map[x-2][y]=map[x-1][y];//��������
						map[x-1][y]=mapbackup[x-1][y];
						map[x][y]=mapbackup[x][y];
						x-=1;//������ҵ�λ�� 
						count++;//���������������� 
					}
				}else{
					if(map[x-1][y]==0||map[x-1][y]==2||map[x-1][y]==3||map[x-1][y]==4){
						x-=1;//������� 
						count++;//������������໣� 
					}
				}
				break;
			case 80: if(map[x+1][y]==52||map[x+1][y]==53||map[x+1][y]==54){//�ж�����·��Ƿ������� 
					if(map[x+2][y]==0||map[x+2][y]==2||map[x+2][y]==3||map[x+2][y]==4){//��������ӣ��ж����������ǲ���ǽ�������ӵĹ��� 
						map[x+2][y]=map[x+1][y];//��������
						map[x][y]=mapbackup[x][y];
						map[x+1][y]=mapbackup[x+1][y];
						x+=1;//������ҵ�λ�� 
						count++;//������
					}
				}else{
					if(map[x+1][y]==0||map[x+1][y]==2||map[x+1][y]==3||map[x+1][y]==4){
						x+=1;//������� 
						count++;//������
					}
				}
				break;
			case 77: if(map[x][y+1]==52||map[x][y+1]==53||map[x][y+1]==54){//�ж�����ҷ��Ƿ������� 
					if(map[x][y+2]==0||map[x][y+2]==2||map[x][y+2]==3||map[x][y+2]==4){//��������ӣ��ж����������ǲ���ǽ 
						map[x][y+2]=map[x][y+1];//�������� 
						map[x][y]=mapbackup[x][y];
						map[x][y+1]=mapbackup[x][y+1];
						y+=1;//������ҵ�λ�� 
						count++;//������
					}
				}else{
					if(map[x][y+1]==0||map[x][y+1]==2||map[x][y+1]==3||map[x][y+1]==4){
						y+=1;//������� 
						count++;//������
					}
				}
				break;
			case 75: if(map[x][y-1]==52||map[x][y-1]==53||map[x][y-1]==54){//�ж�������Ƿ������� 
					if(map[x][y-2]==0||map[x][y-2]==2||map[x][y-2]==3||map[x][y-2]==4){//��������ӣ��ж����������ǲ���ǽ 
						map[x][y-2]=map[x][y-1];//�������� 
						map[x][y]=mapbackup[x][y];
						map[x][y-1]=mapbackup[x][y-1];
						y-=1;//������ҵ�λ�� 
						count++;//������
					}
				}else{
					if(map[x][y-1]==0||map[x][y-1]==2||map[x][y-1]==3||map[x][y-1]==4){
						y-=1;//������� 
						count++;//������ 
					}
				}
				break;
		}
		flag=1;
		For(i,1,number){
			if(map[xx[i+1]][yy[i+1]]!=(50+type[i+1])) flag=0;
		}
	}
	finish=clock();
	duration=(double)(finish-start)/CLOCKS_PER_SEC;//������˶����� 
	while(duration>=60.0){//�����һ���ӵĻ���ת���ɷ��� 
		duration-=60.0;
		min++;
	}
	while(min>=60){//�����һСʱ�Ļ���ת����Сʱ
		min-=60;
		hour++;
	}
	if(min==0&&hour==0){
		printf("��ϲ���ɹ���ɱ��ؿ���\n��һ������%d������ʱ%.2f�롣\n",count,duration);
	}else if(hour==0&&min!=0){
		printf("��ϲ���ɹ���ɱ��ؿ���\n��һ������%d������ʱ%d����%.2f�롣\n",count,min,duration);
	}else if(hour!=0&&min!=0){
		printf("��ϲ���ɹ���ɱ��ؿ���\n��һ������%d������ʱ%dСʱ%d����%.2f�롣\n",count,hour,min,duration);
	}
	grd=fopen("grade.txt","a+");//�򿪼Ʒְ�
	if(min==0&&hour==0){
		fprintf(grd,"���%s����%d�صĲ���Ϊ%d����ʱ%.2f�롣\n",user,choice,count,duration);
	}else if(hour==0&&min!=0){
		fprintf(grd,"���%s����%d�صĲ���Ϊ%d����ʱ%d����%.2f�롣\n",user,choice,count,min,duration);
	}else if(hour!=0&&min!=0){
		fprintf(grd,"���%s����%d�صĲ���Ϊ%d����ʱ%dСʱ%d����%.2f�롣\n",user,choice,count,hour,min,duration);
	}
	if(fclose(grd)){//�رռƷְ壬ͬʱ���ü���ֹ�����ļ��رմ���������
		printf("�ر��ļ����ִ�����Ϸ�����˳���\n");
		exit(0);
	}
	printf("���ķ������Զ�����¼����������������ؿ���\n������Y���ǣ���N����\n");
	scanf("%c",&next);
	if(next=='Y'){
		printf("Hello,δ����");
		Sleep(2000);
		system("CLS");
		goto start;
	}else if(next=='N'){
		printf("��л���棬���������һ��\nNever Settle.\n");
	}
	system("pause");
	return 0;
}
