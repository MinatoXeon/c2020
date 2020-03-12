#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define For(x,a,b) for(x=a;x<=b;x++)
void encrypt(char content[]);
void decrypt(char content[]); 
long long int i,i1,i2;
int main(void)
{
	char content[10980];                                                          //�����㹻�ַ���Χ��˳���¾�Intel Core i9-10980XE
	int setting;
	char container;
	i=0;
	printf("����һ������������ݸ���Base64������м��ܻ���ܵĳ���\n");
	printf("���������ѡ�\n");
	printf("1. ����      2. ����      0. �˳�\n");
	scanf("%d",&setting);
	if(setting==0) exit(0);
	else if(setting!=0&&setting!=1&&setting!=2){
		printf("����ѡ��������Ժ����ԡ�\n");
		exit(0);
	}
	scanf("%c",&container);                         //���������ͦ��ֵģ���ȫ���Ǹ���������Ϊ���������Ժ�Ļس���ֱ�ӱ���Ϊ��content��������ˣ�����Ҫ�Ҹ�������������س� 
	printf("����������������,�Իس����������룺\n");
	while((content[i]=getchar())!='\n') i++;
	content[i]='\0';
	if(setting==1) encrypt(content);
	else if(setting==2) decrypt(content);
	system("pause");
	return 0;
}
void encrypt(char content[])                                     //���ܲ��� 
{
	long long int oldlen,newlen,j;                                 //oldlen������ĳ��ȣ�newlen������ĳ��� 
	char base64[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";     //Base64��������������ASCII���
	char *encode;
	j=0;
	oldlen=strlen(content);
	if(oldlen%3==0) newlen=oldlen/3*4;
	else newlen=(oldlen/3+1)*4;
	if((encode=(char *)malloc((newlen*sizeof(char)+1)))==NULL){       //��̬����ռ䣬�������÷�������⡣����һ��Ҫ��һ����һ����ι��Ҫ��'\0'����û�ط����ˣ� 
		printf("�����ڴ�ʧ�ܡ������쳣�˳���");//�˴�ʹ��callocҲ���ԣ�����Ҳ����sizeof(char)�����1��������'\0'�� 
		exit(1);//newlen*sizeof(char)+1��newlen*(sizeof(char)+1)��һ���ģ���Ϊsizeof(char)=1����charֻռһ���ֽڣ�8��������λ����intɶ�ľͲ�һ���ˣ� 
	}
	//ÿ3��8λ����������Ϊ4��6λ������aaaaaa\aabbbb\bbbbcc\cccccc��Ȼ����Base64���ܷ�����ʮ���ƶ�Ӧ�����γ�6���ַ� 
	for(i1=0,i2=0;i1<newlen-2;i1+=4,i2+=3){                     //Ϊʲôʹ��i1<newlen-2��������i1<newlen ? ���ͷ���������ĩβ1�� 
		encode[i1]=base64[content[i2]>>2];
		encode[i1+1]=base64[(content[i2]&0x3)<<4 | (content[i2+1]>>4)];
		encode[i1+2]=base64[(content[i2+1]&0xf)<<2 | (content[i2+2]>>6)];
		encode[i1+3]=base64[(content[i2+2])&0x3f];
	}
	switch(oldlen%3){
		case 1: encode[i1-2]=encode[i-1]='=';  break;          //Base64�����λ��һ����4�ı���������4λҪ��ĩβ�õ��ںŲ��� 
		case 2: encode[i1-1]='=';  break;                      //Ϊʲô�����3�����ںţ���2 
	}
	encode[newlen]='\0';
	printf("���Ǽ��ܺ���ַ���\n");
	while(encode[j]!='\0'){
		printf("%c",encode[j]);
		j++;
	}
	printf("\n");
	free(encode);
}
void decrypt(char content[])										//���ܲ��� 
{
    int base[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,	//��Base64������ASCII����һһ��Ӧ����base[]�еġ�51��Ԫ����base[122]������Base64�е�51��Ԫ�أ�ASCII�е�122��Ԫ�ء�z�� 
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,62,0,0,0,		//ǰ���һ��0����ΪASCII���������Щ�ַ�û�ж�Ӧ��Base64���룬�޷������� 
				63,52,53,54,55,56,57,58,59,60,61,0,0,0,0,0,0,0,0,
				1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,
				22,23,24,25,0,0,0,0,0,0,26,27,28,29,30,31,32,33,34,35,
				36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51
    };
    long long int oldlen,newlen,j;                              //oldlen������ĳ��ȣ�newlen������ĳ��� 
    char *decode;
    j=0;
    oldlen=strlen(content);
    if(strstr(content,"==")) newlen=oldlen/4*3-2; 
	else if(strstr(content,"=")) newlen=oldlen/4*3-1;
	else newlen=oldlen/4*3;
	if((decode=(char*)calloc(newlen+1,sizeof(char)))==NULL){       //��̬����ռ䣬�������÷��������
		printf("�����ڴ�ʧ�ܡ������쳣�˳���");
		exit(1);
	}
	for(i1=0,i2=0;i2<oldlen-2;i1+=3,i2+=4){
		decode[i1]=((char)base[content[i2]]<<2)|((char)base[content[i2+1]]>>4);
		decode[i1+1]=((char)base[(content[i2+1])]<<4)|((char)base[content[i2+2]]>>2);//���ﲻ��Ҫ&0x0f��ԭ���3 
		decode[i1+2]=((char)base[(content[i2+2])]<<6)|(char)base[content[i2+3]];
	}
	decode[newlen]='\0';
	printf("���ǽ��ܺ���ַ���\n");
	while(decode[j]!='\0'){
		printf("%c",decode[j]);
		j++;
	}
	printf("\n");
	free(decode);
}
//1. 47�� Ϊʲôʹ��i1<newlen-2��������i1<newlen ?
// �������Ǳ�������Base64�ı������Base64�ǽ�3���ַ���ASCII��ת��Ϊ8λ���������֣�Ȼ��ϲ���������������ÿ��������Ϊһ����нضϣ���aaaaaa\aabbbb\bbbbcc\cccccc��Ȼ��
// �����ĸ�������������ת��ʮ�������֣�����Base64�����ͨ������һһ�ҳ���Ӧ���ַ���Ҳ���ǵ������λ����3�ı���ʱ��λ������������1/3�ĳ��ȡ�
// ������������λ������3�ı����أ�
// λ��Ϊ3n+1ʱ,���һ�����ְ��չ�����ȡ�õ���������,�������Ķ��������ֱ���6λ��2λ����������λ���ֻ��ں��油�ĸ�0�õ�һ����λ�ַ�,Ȼ���ٷֱ�õ�����Base64�ַ���
// ����һ��,Base64���ܺ�λ��������4�ı���,������λҪ�ں��油"="�š���ô��ʱ,��Ҫ�ں��油����"="�š� 
// ���絥�ַ�"M",��ASCII��Ϊ77,��������Ϊ01001101,��ȡ��010011��01,Ȼ��ȫ��010011��010000,���߷ֱ��Ӧ19��16,���ǵõ�Base64����TQ==�� 
// λ��Ϊ3n+2ʱ��Ȼ,���ǻ�õ������ַ���Base64����,Ȼ���"="��Ϊ��λ��������"DL",���ܺ��õ�"REw="��
// �������ش�������Ǹ����⡣���Կ���,������������ÿ��λһ����,���ܳ������һ��ֻʣһ���ַ������,Ȼ��ת��ΪBase64�����δ�ӵȺ�ǰ��Ϊ�����ַ����������һ��ֻʣ�����ַ�,
// ת�����Ϊ�����ַ���Ҳ�������ٿ���ֻ������Base64�ַ������ʹ��i1<newlen����ô����?���һ�ִ�ѭ�����ܻ��ж�Ϊ��ѭ��û�����ꡪ����Ϊ���һ��ֻ������Base64�ַ�,ȷʵС��
// newlen���ĸ���Ȼ��ѭ��������һ��...�ⲻ�Ǻ������?û�з�����ô���ڴ�,Ҫ������һ��,˭֪�������ʲô��ֵĴ���QAQ��
//2. 55�� Ϊʲô�����3�����ںţ�
// ���潲��,δ�ӵȺ�ǰ���һ�������������ַ�����,Ҫ������λ,Ҳ�����ֻ��Ҫ����"="������Ҳ����i1-2,i1-1��ԭ��,��Ϊ��λ��û���갡,�ټӾͱ��ڴ��ˡ�
//3. 88��89�� Ϊʲô����Ҫ&0x֮��ģ�
// ��Ϊcharֻ��8��������λ������4λ�������ǰ4λ�����������12λ�Ķ���������Ҳ����˵�������<<�����λ��ȡ��λ�����ã�������һ����ר��ȡλ�� 
//4. ���⻰,Ϊʲô��Ҫд��ô��ֵĶ���?��������Ҫ��,�ѵ�����ֻ��Ҫһ��ʲôstr[i] += i;����str[i] -= i;֮��ľ�������?�α����ֿ��,�������ֺ�? 
// ��ʵ�ܼ򵥹�,���˲���(MinatoXeon.github.io)������һ��ѱ�ת��Base64���ֻ����ʹ���(����Ȥ�Ļ���ӭȥ����),�Լ�дһ��Base64���ܽ��ܵĳ���Ͼ��������û�к��֮���˳��
// �����������ѧһ��Base64��������4*6ת3*8���Ƶ�ת������,��������һ�����ð���
// NEVER SETTLE. 
