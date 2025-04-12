// 链表操作.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<malloc.h>
#define LEN sizeof(struct student)
#define NULL 0
struct student{
	int num;
	int score;
	struct student *next;
};//定义sudent 链表

int _tmain(int argc, _TCHAR* argv[])
{
	struct student *creat();//创建链表
	struct student *creat(int k);//创建指定个数的链表
	struct student *del(struct student *p,int n);//删除指定链表结构
	struct student *MySort(student *p);//排序，按num,score优先级
	struct student *insert(struct student *p,struct student *stu);//插入指定结构，按顺序
	struct student *exchange(struct student *p,int x,int y);//交换第x位和第y位的成员,x<y
	struct student *exchange2(struct student *p,int num1,int num2);//交换学号为num1,num2的成员
	int Mysearch(struct student *p,int n);//查找指定成员
	void print(struct student *p);//输出链表结构
	void mydelete(struct student *p);
	struct student *head,*stu;
	int deln,x,y,k;
	printf("Enter k:");
	scanf_s("%d",&k);
	printf("input records(%d):\n",k);
	head=creat(k);
	printf("The created structure is:\n");
	print(head);
	printf("Exchange number 1 and number2(num1<num2):\n");
	scanf_s("%d%d",&x,&y);
	head=exchange(head,x,y);
	printf("The exchaged structure is:\n");
	print(head);
	printf("Exchange num 1 and num2:\n");
	scanf_s("%d%d",&x,&y);
	head=exchange2(head,x,y);
	printf("The exchaged structure is:\n");
	print(head);
	head=MySort(head);
	printf("The sorted structure is:\n");
	print(head);
	printf("\ninput the deleted number:\n");
	scanf_s("%d",&deln);
	head=del(head,deln);
	print(head);
	printf("\ninput the inserted number:\n");
	stu=(struct student*)malloc(LEN);
	scanf_s("%d %d",&stu->num,&stu->score);
	head=insert(head,stu);
	print(head);
	printf("Which student do you want?");
	int n;
	scanf_s("%d",&n);
	Mysearch(head,n);
	mydelete(head);
	return 0;
}
int cmp(student *s1,student *s2){//比较s1,s2的大小，s1>s2,return 1,s1==s2,return 0,s1<s2,return -1
	if(s1->num>s2->num) return 1;
	else if(s1->num<s2->num) return -1;
	else{
		if(s1->score==s2->score) return 0;
		else if(s1->score>s2->score) return 1;
		else return -1;
	}
}
struct student *creat(){//创建链表，遇num==0结束
	struct student *head,*p1,*p2;
	int n=0;
	head=NULL;
	p1=(struct student*)malloc(LEN);
	p2=p1;
	scanf_s("%d%d",&p1->num,&p1->score);
	while(p1->num!=0){
		p2=p1;
		n++;
		if(n==1) head=p1;
		p1=(struct student*)malloc(LEN);
		scanf_s("%d%d",&p1->num,&p1->score);
		if(p1->num==0) p2->next=NULL;
		else p2->next=p1;
	}
	return head;
}
struct student *creat(int k){//到k位置结束。
	int x=1;
	struct student *head,*p1,*p2;
	int n=0;
	head=NULL;
	p1=(struct student*)malloc(LEN);
	p2=p1;
	scanf_s("%d%d",&p1->num,&p1->score);
	while(x<k){
		p2=p1;
		n++;
		if(n==1) head=p1;
		p1=(struct student*)malloc(LEN);
		scanf_s("%d%d",&p1->num,&p1->score);
		p2->next=p1;
		x++;
	}
	p1->next=NULL;
	return head;
}
struct student *del(struct student *p,int n){//删除指定的位置
	struct student *p1,*p2,*head;
	head=p;
	p1=p;
	p2=p;
	if(n==p->num){
		head=p->next;
		return head;
	}
	while(p1->num!=n){
		p2=p1;
		p1=p1->next;
	}
	p2->next=p1->next;
	return head;
}
struct student *insert(struct student *p,struct student *stu){//插入指定链表
	struct student *p1,*p2,*head;
	head=p;
	p1=p;
	p2=p;
	if(cmp(stu,p)<0){
		stu->next=head;
		head=stu;
		return head;
	}
	if(cmp(stu,p)==0) return head;
	while(!(cmp(p2,stu)<=0&&cmp(p1,stu)>=0)){
		p2=p1;
		p1=p1->next;
		if(p1==NULL){
			p2->next=stu;
			stu->next=p1;
			return head;
		}
	}
	p2->next=stu;
	stu->next=p1;
	return head;

}
struct student *MySort(student *p){
	student *p1,*p2;
	p1=p;
	p2=p->next;
	p->next=NULL;
	while(p1!=NULL){
		p=insert(p,p1);
		p1=p2;
		if(p2!=NULL) p2=p2->next;
	}
	return p;
}
int  Mysearch(struct student *p,int n){//查找学学号为n的成员
	struct student *p1;
	p1=p;
	while(p1->num!=n){
		p1=p1->next;
		if(p1==NULL){
			printf("Not found.\n");
			return 0;
		}
	}
	printf("Num:%d,score:%d\n",p1->num,p1->score);
}
void print(struct student *p){//输出链表
	struct student*p1;
	p1=p;
	if(p1==NULL) printf("NULL\n");
	while((p1!=NULL)){
		if(p1->num!=0)
		printf("num %d,score %d\n",p1->num,p1->score);
		p1=p1->next;
	}
}
void mydelete(struct student *p){//最后释放空间
	struct student *p1,*p2;
	p1=p2=p;
	while(p1!=NULL){
		p2=p1->next;
		free(p1);
		p1=p2;
	}
}
struct student *exchange(struct student *p,int x,int y){
	struct student *p1,*p2,*p3,*p4;
	int m,n;
	p1=p2=p3=p4=p;
	if(x==1&&y!=2){
		p2=p1->next;
		m=1;
		while(m<y-1){//给y定位
			p1=p2;
			p2=p2->next;
			m++;
		}
		p3=p2->next;
		p2->next=p->next;
		p1->next=p;
		p->next=p3;
		return p2;
	}
	if(x==1&&y==2){
		p2=p1->next;
		p3=p2->next;
		p1->next=p3;
		p2->next=p1;
		return p2;
	}
	if(x!=1){
	if(y-x==1){
		p2=p1->next;
		m=1;
		while(m<x-1){
			p1=p2;
			p2=p2->next;
			m++;
		}
		p2->next=p3;
		p2->next=p3->next;
		p3->next=p2;
		p1->next=p3;
	}
	else{
		m=n=1;
		p2=p1->next;
		p4=p3->next;
		while(m<x-1){
			p1=p2;
			p2=p2->next;
			m++;
		}
		while(n<y-1){
			p3=p4;
			p4=p4->next;
			n++;
		}
		struct student *p5,*p6;
		p5=p2->next;
		p6=p4->next;
		p2->next=p6;
		p3->next=p2;//接入p2
		p4->next=p5;
		p1->next=p4;//接入p4
	}
	return p;
	}
}
struct student *exchange2(struct student *p,int num1,int num2){
	if(num1==num2) return p;
	struct student *p1,*p2,*p3,*p4,*p5,*p6;
	p1=p2=p3=p4=p;
	if(num1==p->num){
		p2=p1->next;
		p4=p3->next;
		while(p4->num!=num2){
			p3=p4;
			p4=p3->next;
			if(p4==NULL){
				printf("Operation Failure.\n");
				return NULL;
			}
		}
		p6=p4->next;
		p1->next=p6;
		p3->next=p1;
		p4->next=p2;
		p=p4;
		return p;
	}
	if(num2==p->num){
		p2=p1->next;
		p4=p3->next;
		while(p2->num!=num1){
			p1=p2;
			p2=p1->next;
			if(p2==NULL){
				printf("Operation Failure.\n");
				return NULL;
			}
		}
		p5=p2->next;
		p3->next=p5;
		p1->next=p3;
		p2->next=p4;
		p=p2;
		return p;
	}
	else{
		p2=p1->next;
		p4=p3->next;
		while(p2->num!=num1){
			p1=p2;
			p2=p1->next;
			if(p2==NULL){
				printf("Operation Failure.\n");
				return NULL;
			}
		}
		while(p4->num!=num2){
			p3=p4;
			p4=p3->next;
			if(p4==NULL){
				printf("Operation Failure.\n");
				return NULL;
			}
		}
		p5=p2->next;
		p6=p4->next;
		p1->next=p4;
		p4->next=p5;
		p3->next=p2;
		p2->next=p6;
		return p;
	}
}