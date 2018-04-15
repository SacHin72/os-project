#include<stdio.h>
#include<stdlib.h>
int bur_time=0,n;
int min,k=1,process[20];
float avg_wttime=0,avg_turntime=0,turntime_sum=0,wttime_sum=0;

void enterprocess(void)
{
	for(int i=0;i<20;i++)
	{
		process[i]=i;
	}
}

int burst_time[10],temp,arr_time[10],wait_time[10],turn_time[10],turn1=0,sum=0;
int priority[10];

void set_priority()
{
	for(int i=0;i<n;i++)
	{
		priority[i]=1;
	}
}

void sort()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr_time[i]<arr_time[j])
			{
				temp=process[j];
				process[j]=process[i];
				process[i]=temp;
				
				temp=arr_time[j];
				arr_time[j]=arr_time[i];
				arr_time[i]=temp;
				
				temp=burst_time[j];
				burst_time[j]=burst_time[i];
				burst_time[i]=temp;
			}
		}
	}
}

void sort_bursttime()
{
	for(int j=0;j<n;j++)
	{
		bur_time=bur_time+burst_time[j];
		min=burst_time[k];
		for(int i=k;i<n;i++)
		{
			if(bur_time>=arr_time[i] && burst_time[i]<min)
			{
				temp=process[k];
				process[k]=process[i];
				process[i]=temp;
				
				temp=arr_time[k];
				arr_time[k]=arr_time[i];
				arr_time[i]=temp;
				
				temp=burst_time[k];
				burst_time[k]=burst_time[i];
				burst_time[i]=temp;
			}
		}
		k++;
	}
}
void sort_priority()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(priority[i]>priority[j])
			{
				temp=process[j];
				process[j]=process[i];
				process[i]=temp;
				
				temp=arr_time[j];
				arr_time[j]=arr_time[i];
				arr_time[i]=temp;
				
				temp=burst_time[j];
				burst_time[j]=burst_time[i];
				burst_time[i]=temp;
			}
		}
	}
}
int main()// Main function.
{
	enterprocess();
	set_priority();
	printf("NOTE : If the burst time of process will more then 20, Then priority will increase\n");
	printf("For saving a process from starvation\n\n");
	printf("enter the number of process you want to enter\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter the burst time of %d process\n",i+1);
		scanf("%d",&burst_time[i]);
		printf("enter the arrival time of %dprocess \n",i+1);
		scanf("%d",&arr_time[i]);
	}
	sort();
	sort_bursttime();;
	wait_time[0]=0;
	for(int i=1;i<n;i++)
	{
		sum=sum+burst_time[i-1];
		wait_time[i]=sum-arr_time[i];
		if(burst_time[i]>20)
		{
			priority[i]=1+(wait_time[i]/burst_time[i]);
		}
		wttime_sum=wttime_sum+wait_time[i];
	}
	sort_priority();
	
	avg_wttime=(wttime_sum/n);
	

	for(int i=0;i<n;i++)
	{
		turn1=turn1+burst_time[i];
		turn_time[i]=turn1-arr_time[i];
		turntime_sum=turntime_sum+turn_time[i];
	}
	avg_turntime=(turntime_sum/n);
	printf("process burst arrival waiting turn-ar\n");
	for(int i=0;i<n;i++)
	{
		printf("%d         %d       %d      %d      %d \n",process[i]+1,burst_time[i],arr_time[i],wait_time[i],turn_time[i]);
	}
	printf("average waiting time:%f\n",avg_wttime);
	printf("average turn aroundtime :%f\n",avg_turntime);
}
