//Sequential file allocation
#include<stdio.h>
#include<stdlib.h>
int disk[16];
struct table
{
	int id,size,start;
	struct table* next;
}*root,*temp,*q;
int ispossible(int size)
{
	int i=0,j,set=-1,temp;
	while(1)
	{
		while(i<16)
		{
			printf("8");
			if(disk[i]==0)
			{
				i++;			
				break;
			}
			i++;
		}
		j=i-1;
		while(j<16 && temp!=0)
		{
			if(disk[j]==0)
			{
				temp--;
				j++;
				continue;
			}
			else
			{
				break;
			}
		}
		if(temp==0)
		{
			set=i-1;
			break;
		}
		else if(i==16)
			break;
		else
		{
			temp=size;
			//i=i+1;
			continue;
		}
	}
	return(set);
}
void add(int id,int size,int start)
{
	struct table* p=(struct table*)malloc(sizeof(struct table));
	p->id=id;
	p->size=size;
	p->start=start;
	p->next=NULL;
	if(root==NULL)
		root=p;
	else
	{
		temp=root;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=p;
	}
}
void rem(int id)
{
	temp=root;
	q=temp;
	while(temp->next!=NULL)
	{
		if(temp->id==id)
		{
			if(temp==root)
			{
				root=root->next;
				free(temp);
				temp=root;
			}
			else
			{
				q=temp->next;
				free(temp);
				temp=q->next;
			}
		}
		q=temp;
		temp=temp->next;
	}
	if(temp->id==id)
	{
		q->next=NULL;
		free(temp);
	}
}
void add_file(int id,int size)
{
	int ct=ispossible(size),i;
	if(ct!=-1)
	{
		add(id,size,ct);
		for(i=ct;i<16 && size>0;i++)
		{
			disk[i]=id;
			size--;
		}
	}
	else
	{
		printf("\nNot possible");
	}
}
void rem_file(int id)
{
	int i;
	for(i=0;i<16;i++)
	{
		if(disk[i]==id)
		{
			disk[i]=0;
		}
	}
	rem(id);
}
void display_table()
{
	temp=root;
	printf("\nid\tsize\tstart");
	while(temp!=NULL)
	{
		printf("\n%d\t%d\t%d",temp->id,temp->size,temp->start);
		temp=temp->next;
	}
}
void display()
{
	int i;
	printf("\nDisk is : ");	
	for(i=0;i<16;i++)
	{
		printf("\t%d",disk[i]);
	}
}
void main()
{
	int ch,id,size,i;
	for(i=0;i<16;i++)
		disk[i]=0;
	while(1)
	{
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	
			{
				printf("\nEnter file id : ");
				scanf("%d",&id);
				printf("\nEnter size : ");
				scanf("%d",&size);
				add_file(id,size);
				break;
			}
			case 2:
			{
				printf("\nEnter file id : ");
				scanf("%d",&id);
				rem_file(id);
				break;
			}
			case 3:
			{
				display_table();
				break;
			}
			case 4:
			{
				display();
				break;
			}
			default:
			{
				exit(0);
				break;
			}
		}
	}
}