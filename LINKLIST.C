#include<stdio.h>
#include<conio.h>
struct sll
{
	int info;
	struct sll *next;
};
void menu()
{
	printf("\n1.Insert At First");
	printf("\n2.Insert At Last");
	printf("\n3.Insert At Given Pos");
	printf("\n4.Delete At First");
	printf("\n5.Delete At Last");
	printf("\n6.Delete At Given Pos");
	printf("\n7.Count No Of Nodes");
	printf("\n8.Serach Node");
	printf("\n9.Copy Link List");
	printf("\n10.Reverse Link List");
	printf("\n11.Display");

}
struct sll *createnode(int x)
{
	struct sll *temp;
	temp=(struct sll *)malloc(sizeof(struct sll));
	temp->info=x;
	temp->next=NULL;
	return temp;
}
struct sll *insertatfirst(struct sll *first,int x)
{
	struct sll *temp;
	temp = createnode(x);
	if(first == NULL)
	{
		first= temp;
	}
	else
	{
		temp->next=first;
		first=temp;
	}
	return first;
}
void display(struct sll *first)
{
	struct sll *p;
	if(first == NULL)
	{
		printf("List Is Not Available");
	}
	else
	{
		p=first;
		printf("\n List Data Are->");
		while(p!=NULL)
		{
			printf("%d,",p->info);
			p=p->next;
		}
	}
}
void count(struct sll *first)
{
	struct sll *p;
	int cnt=0;
	if(first == NULL)
	{
		printf("List Is Not Available");
	}
	else
	{
		p=first;

		while(p!=NULL)
		{
			cnt++;
			p=p->next;
		}
		printf("\nTotal Nodes Are->> %d",cnt);
	}
}
void search(struct sll *first,int x)
{
	struct sll *p;
	int flag=0;
	if(first == NULL)
	{
		printf("List Is Not Available");
	}
	else
	{
		p=first;

		while(p!=NULL)
		{
			if(p->info==x)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
		printf("\n Value Is Found");
		}
		else
		{
		printf("\n Value Is Not Found");
		}

	}
}
void main()
{
	struct sll *first=NULL;
	int x,choice;
	clrscr();
	while(1)
	{
		clrscr();
		menu();
		printf("\nInsert Your Choice->> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter X :- ");
				scanf("%d",&x);
				first=insertatfirst(first,x);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				count(first);
				break;
			case 8:
				printf("\n enter x->");
				scanf("%d",&x);
				search(first,x);
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				display(first);
				break;
			default:
				exit();
		}//switch
		getch();
	}//while

}
