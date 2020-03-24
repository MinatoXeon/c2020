#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define For(x,a,b) for(x=a;x<=b;x++)
int i,i1,i2;
typedef struct node{//����ṹ������ʵ������˳���Զ����������� 
	int value;
	struct node* next;
}Node; 
Node *create(Node *p,int N);//��ʼ������ 
void output(Node *p);//����������� 
Node *length(int N);//�����������������������Ľ��� 
void search(Node *p);//ֱ�Ӳ�������ֵΪ5�Ľڵ�ɣ���ʵ�ֵ㹦��Ҳûʲô���õ� 
void reverse(Node *p);//�����������нڵ㷴�� 
int main(void)
{
    int n;
    printf("��������Ҫ����������ĳ��ȣ�\n");
    scanf("%d",&n);
    Node *head=length(n);
    output(head);
    reverse(head);
    search(head);
	system("pause");
	return 0;
}
Node *create(Node *p,int N)
{
    if(N!=0) scanf("%d",&(*p).value);
    if(N==2){
        (*p).next=NULL;
        return NULL;
    }
    Node *pre=(Node *)malloc(sizeof(Node));
    (*p).next=pre;
    return pre;
}
void output(Node *p)
{
    system("CLS");
    int count=0;
    while(p!=NULL){
        if(count==0)
        {
            p=(*p).next;
            count++;
            continue;
        }
        count++;
		printf("Node%d:%5d\n",count,(*p).value);
        p=(*p).next;
    }
}
Node *length(int N)
{
    Node *head=(Node *)malloc(sizeof(Node));
    Node *a=(Node *)malloc(sizeof(Node));
    For(i,0,N){
        if(i==0) a=create(head,0);//�����׸��ڵ� 
        else if(i==N) a=create(a,2);
        else a=create(a,1);
    }
    return head;
}
void search(Node *p)
{
    system("CLS");
    int count=0;
    while(p!=NULL){
        if(count==0){
            p=(*p).next;//p���� 
            count++;
            continue;
        }
        if((*p).value==5){
            count++;
			printf("Node%d:%p\n",count,p);
            p=(*p).next;
        }
        else{
            count++;
            p=(*p).next;
        }
    }
}
void reverse(Node *p)
{
    system("CLS");
    Node *rev,*old;//��ô˵�ء���old����һ��ý��ɣ� 
    Node *head=p;
    int count=0;
    while((*p).next!=NULL){
        if(count==0){
            p=(*p).next;//p���� 
            rev=(*p).next;//rev�洢p֮��Ľڵ� 
            (*p).next=NULL;
            old=p;
            p=rev;
            count++;
            continue;
        }
        rev=(*p).next;//ͷ������дע����QAQ 
        (*p).next=old;
        old=p;
        p=rev;
    }
    (*p).next=old;
    (*head).next=p;
    output(head);
}
