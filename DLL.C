#include<stdio.h>
#include<conio.h>
struct DLL
{
	int info;
		struct DLL *next;
};
void menu()
{
	printf("\n1.Insert At First "); //mandatory
	printf("\n2.Insert At Last ");
	printf("\n3.Insert At Given Pos ");
	printf("\n4.Delete At First ");
	printf("\n5.Delete At Last ");
	printf("\n6.Delete At Given Pos ");
	printf("\n7.Count No.of Nodes ");
	printf("\n8.Search Node ");
	printf("\n9.Copy Link DLL ");
	printf("\n10.Reverse Link DLL ");
	printf("\n11.Display ");        //mandatory
}
//return type func name(argDLL)
struct DLL *createNode(int x)
{
	struct DLL *temp;
	temp=(struct DLL *)malloc(sizeof(struct DLL));
	temp->info=x;
	temp->next=NULL;
	return temp;
}
struct DLL *insAtFirst(struct DLL *first,int x)
{
	struct DLL *temp;
	temp=createNode(x);
	if(first==NULL)
		first=temp;
	else
	{

		temp->next=first;
		first=temp;
	}
	return first;
}
struct DLL *insAtLast(struct DLL *first,int x)
{
	struct DLL *temp,*p;
	temp=createNode(x);
	if(first==NULL)
		first=temp;
	else
	{
		p=first;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prv=NULL;
	}
	return first;
}
struct DLL *insAtPos(struct DLL *first,int x,int pos)
{    	struct DLL *temp,*p,*q; int i=1; 	temp=createNode(x);
	if(first==NULL && pos >1)
		printf("\nInvalid Postion");
	else if(pos==1)
	{	temp->next=first; 	first=temp; 	}
	else
	{       p=first;
		while(i<pos && p!=NULL)
		{	q=p; 	p=p->next; 		i++; 		}
		if(i==pos)
		{
			q->next=temp;  		temp->next=p;
		}
		else
		{
			printf("\nInvalid position");
		}

	}
	return first;
}

struct DLL *delAtFirst(struct DLL *first)
{
	struct DLL *p;
	p=first;
	if(first==NULL)
	{
		printf("\nNo data");
	}
	else if(first->next == NULL)
	{
		printf("\nDeleted value is %d",first->info);
		free(first);
		first=NULL;
	}
	else
	{
		p=first;
		printf("\nDeleted value is %d",p->info);
		first=first->next;
		free(p);
		p=NULL;
	}
	return first;
}
struct DLL *delAtLast(struct DLL *first)
{
	struct DLL *p,*q;
	p=first;
	if(first==NULL)
		printf("\nNo data");
	else if(first->next == NULL)
	{
		printf("\nDeleted value is %d",p->info);
		free(first);
		first=NULL;
	}
	else
	{
		p=first;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		printf("\nDeleted value is %d",p->info);
		q->next=NULL;
		free(p);
		p=NULL;
	}
	return first;
}
struct DLL *delAtPos(struct DLL *first,int pos)
{
	struct DLL *p,*q,*r;
	int i;
	p=first;
	q=p;
	if(first==NULL)
		printf("\nNo data");
	else if(pos>1 && first->next == NULL)
	{
		printf("\nPostion is Invalid");
	}
	else if(pos==1)
	{
		p=first;
		first=first->next;
		free(p);
		p=NULL;
	}
	else
	{       i=1;
		while(i<=pos && p!=NULL)
		{
			r=q;
			q=p;
			p=p->next;
			i++;
		}
		if(i>pos)
		{
			r->next=p;
			printf("\nDeleted value is %d",q->info);
			free(q);
			q=NULL;
		}
		else
			printf("\nPosition is invalid");
	}
	return first;
}

void Display(struct DLL *first)
{
	struct DLL *p;
	if(first==NULL)
		printf("\nDLL is not available ");
	else
	{
		p=first;
		printf("\nDLL Data are :- ");
		while(p!=NULL)
		{
			printf("%d->",p->info);
			p=p->next;
		}
	}
}
void Count(struct DLL *first)
{
	struct DLL *p;
	int cnt=0;
	if(first==NULL)
		printf("\nDLL is not available ");
	else
	{
		p=first;

		while(p!=NULL)
		{
			p=p->next;
			cnt++;
		}
		printf("\nTotal nodes are  :- %d",cnt);
	}
}
void Search(struct DLL *first,int x)
{
	struct DLL *p;
	int flag=0;
	if(first==NULL)
		printf("\nDLL is not available ");
	else
	{
		p=first;
		while(p!=NULL)
		{
			if(p->info == x)
			{
				flag=1;
				break;
			}
			p=p->next;
		}
		if(flag==1)
			printf("\nValue is found");
		else
			printf("\nValue is not found");
	}
}
struct DLL *Copy(struct DLL *first,struct DLL *second)
{	struct DLL *temp,*p,*q;
	if(first==NULL)
		printf("\nList is not available");
	else
	{       p=first;
		while(p!=NULL)
		{	temp=createNode(p->info);
			if(second==NULL)
				second=temp;
			else
			{	q=second;
				while(q->next!=NULL)
					q=q->next;
				q->next=temp;
			}
			p=p->next;
		}
	}
	Display(second);
	return second;
}
struct DLL *Reverse(struct DLL *first,struct DLL *second)
{	struct DLL *temp,*p,*q;
	if(first==NULL)
		printf("\nList is not available");
	else
	{       p=first;
		while(p!=NULL)
		{	temp=createNode(p->info);
			if(second==NULL)
				second=temp;
			else
			{	temp->next=second;
				second=temp;
			}
			p=p->next;
		}
	}
	Display(second);
	return second;
}

void main()
{
	struct DLL *first=NULL,*second=NULL;
	int x,choice,pos;
	clrscr();
	while(1)
	{
		clrscr();
		menu();
		printf("\nEnter Ur Choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter x :- ");
				scanf("%d",&x);
				first=insAtFirst(first,x);
				break;
			case 2:
				printf("\nEnter x :- ");
				scanf("%d",&x);
				first=insAtLast(first,x);
				break;
			case 3:
				printf("\nEnter x :- ");
				scanf("%d",&x);
				printf("\nEnter Postion :- ");
				scanf("%d",&pos);

				first=insAtPos(first,x,pos);

				break;
			case 4:
				first=delAtFirst(first);
				break;
			case 5:
				first=delAtLast(first);
				break;
			case 6:
				printf("\nEnter Postion :- ");
				scanf("%d",&pos);
				first=delAtPos(first,pos);
				break;
			case 7:
				Count(first);
				break;
			case 8:
				printf("\nEnter x :- ");
				scanf("%d",&x);
				Search(first,x);
				break;
			case 9:
				free(second);
				second=NULL;
				second=Copy(first,second);
				break;
			case 10:
				free(second);
				second=NULL;
				second=Reverse(first,second);
				break;
			case 11:
				Display(first);
				break;

			default:
				exit(0);
		}//switch
		getch();
	} //while
}