//SJF CPU Scheduling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct process
{
	char name[10];
	int AT,BT,CT,TAT,WT,status;
};
void main()
{
	int n,i,j,temp,sum=0,k=0,k1,init_temp;
	float Waiting_time;
	char s[10];
	printf("\nEnter the number of processess : ");
	scanf("%d",&n);
	struct process p[n];
	for(i=0;i<n;i++)
	{
		printf("\nEnter name : ");
		scanf("%s",p[i].name);
		printf("\nEnter AT : ");
		scanf("%d",&p[i].AT);
		printf("\nEnter BT : ");
		scanf("%d",&p[i].BT);
		p[i].CT=0;
		p[i].status=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].BT>p[j].BT)
			{
				temp=p[i].AT;
				p[i].AT=p[j].AT;
				p[j].AT=temp;
				temp=p[i].BT;
				p[i].BT=p[j].BT;
				p[j].BT=temp;
				strcpy(s,p[i].name);
				strcpy(p[i].name,p[j].name);
				strcpy(p[j].name,s);
			}
		}
	}
	temp=0;
	while(k<n)
	{
		init_temp=temp;
		for(i=0;i<n;i++)
		{
			if(p[i].AT<=temp && p[i].status==0)
			{
				p[i].CT=temp+p[i].BT;
				temp=temp+p[i].BT;
				k=k+1;
				p[i].status=k;
				p[i].TAT=p[i].CT-p[i].AT;
				p[i].WT=p[i].TAT-p[i].BT;
				sum=sum+p[i].WT;
				break;
			}
		}
		if(temp==init_temp)
			temp=temp+1;
	}
	Waiting_time=(sum*1.0)/n;
	printf("\nprocess\tAT\tBT\tCT\tTAT\tWT");
	k1=1;
	while(k1<=k)
	{
		for(i=0;i<n;i++)
		{
			if(p[i].status==k1)
			{
				printf("\n%s\t%d\t%d\t%d\t%d\t%d",p[i].name,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT);
				k1++;
			}
		}
	}
	printf("\nAverage Waiting_time : %f",Waiting_time);
}