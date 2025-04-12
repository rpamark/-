// T4.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#pragma warning(disable:4996)


#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct node{
	char c;
	struct node *next;
	struct node *pre;
};
void create(node **cursor,node **head,node**head2,char *str){
	int i;
	*cursor=NULL;
	node *end=NULL;//��ʼ��
	for(i=0;str[i]!=0;i++){
		node *newnode=(node*)malloc(sizeof(node));
		newnode->c=str[i];
		newnode->next=NULL;//�����µĽڵ�
		newnode->pre=NULL;
		if(*cursor==NULL){//��һ���ڵ�
			*cursor=newnode;//ָ���´����Ľڵ�
			(*cursor)->pre=*head;
			(*head)->next=*cursor;
			end=newnode;
			*head2=*cursor;
		}
		else{//�����µĽڵ�
			end->next=newnode;
			newnode->pre=end;
			*cursor=newnode;
			end=newnode;
		}
	}
	*cursor=end;
}//����˫������ʹ��cursorָ�����һ��

void left(node **cursor,node*head){
	if(*cursor==head||*cursor==NULL) printf("F\n");
	else{
		*cursor=(*cursor)->pre;
		printf("T\n");
	}

}
void right(node **cursor){
	if(*cursor==NULL||((*cursor)->next)==NULL){
		printf("F\n");
	}
	else{
		*cursor=((*cursor)->next);
		printf("T\n");
	}
}
void rightinsert(node **cursor,char c){
	node *k=*cursor;
	node *target=(node*)malloc(sizeof(node));
	target->c=c;
	if(k->next==NULL){
		(*cursor)->next=target;
		target->pre=(*cursor);
		target->next=NULL;
		*cursor=target;
	}
	else{
		node *q=(*cursor)->next;
		(*cursor)->next=target;
		target->pre=(*cursor);
		target->next=q;
		q->pre=target;
		*cursor=target;
	}
	printf("T\n");
}
void del(node**cursor,node**head){
	if(*cursor==NULL||(*cursor)->c=='\0'){
		printf("F\n");
	}
	else{
		if((*cursor)->next!=NULL){
		((*cursor)->pre)->next=(*cursor)->next;
		((*cursor)->next)->pre=(*cursor)->pre;
		*cursor=((*cursor)->pre);
		}
		else{
			((*cursor)->pre)->next=NULL;
			*cursor=((*cursor)->pre);
		}
		printf("T\n");
	}


}

void show(node **head){
	node *p=(*head)->next;
	while (p!=NULL){
		printf("%c",p->c);
		p=p->next;
	}
	printf("\n");
}
int main(){
	char str[1001];
	scanf("%s",str);//��ȡ�ַ���
	node *cursor;
	node *head2;
	node *head=(node*)malloc(sizeof(node));
	head->c='\0';//��ǰ��Ľڵ�
	head->pre=NULL;
	create(&cursor,&head,&head2,str);//head2Ϊ��һ��
	int n,i;
	scanf("%d",&n);
	char x,c;
	for(i=0;i<n;i++){
		scanf(" %c",&x);
		if(x=='<'){
			left(&cursor,head);
		}
		else if(x=='>'){
			right(&cursor);
		}
		else if(x=='I'){
			scanf("%c",&c);
			scanf("%c",&c);
			rightinsert(&cursor,c);
		}
		else if(x=='D'){
			del(&cursor,&head);
		}
		else if(x=='S'){
			show(&head);
		}
		else{
		}
	}
	return 0;
}
