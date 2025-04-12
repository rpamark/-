// T4.1.cpp : 定义控制台应用程序的入口点。
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
	node *end=NULL;//初始化
	for(i=0;str[i]!=0;i++){
		node *newnode=(node*)malloc(sizeof(node));
		newnode->c=str[i];
		newnode->next=NULL;//创建新的节点
		newnode->pre=NULL;
		if(*cursor==NULL){//第一个节点
			*cursor=newnode;//指向新创建的节点
			(*cursor)->pre=*head;
			(*head)->next=*cursor;
			end=newnode;
			*head2=*cursor;
		}
		else{//创建新的节点
			end->next=newnode;
			newnode->pre=end;
			*cursor=newnode;
			end=newnode;
		}
	}
	*cursor=end;
}//创建双向链表并使得cursor指向最后一个

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
	scanf("%s",str);//读取字符串
	node *cursor;
	node *head2;
	node *head=(node*)malloc(sizeof(node));
	head->c='\0';//最前面的节点
	head->pre=NULL;
	create(&cursor,&head,&head2,str);//head2为第一个
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
