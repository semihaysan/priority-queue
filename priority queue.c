#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
	int data ;
	int pr;
	struct node * next;
};
struct node * start=NULL;
struct node * temp =NULL;

struct node * insert(struct node * start)
{
	int val , pri;
	struct node * ptr =(struct node *)malloc (sizeof(struct node));
	printf("girmek istediginiz sayiyi ve onceligini giriniz ");
	scanf("%d %d",&val , &pri);
	ptr->data=val;
	ptr->pr=pri;
	if(start==NULL || pri < start->pr)
	{
		ptr->next=start;
		start=ptr;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL && temp->next->pr <= pri)
		{
			temp=temp->next;
		}
		ptr->next=temp->next;
		temp->next=ptr;
	}
	return start;
}

struct node * del(struct node * start)
{
	if(start==NULL)
	{
		printf("kuyruk bos");
	}
	else
	{
		temp=start;
		printf("silinen eleman = %d \n" ,temp->data);
		start=start->next;
		free(temp);
	}
	return start;
}
void display(struct node * start)
{
	if(start==NULL)
	{
		printf("yazdirilacak eleman yok");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("deger = %d  oncelik = %d \n", temp->data , temp->pr);
			temp=temp->next;
		}
	}
}


int main()
{
	start=insert(start);
	start=insert(start);
	start=insert(start);
	start=insert(start);
	display(start);
	start=del(start);
	start=del(start);
	display(start);
}
