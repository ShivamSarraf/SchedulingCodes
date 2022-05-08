#include<stdio.h>
int main()
{
    int a[5][3],b[5][6],d;
    printf("Enter the process no. CPU burst time followed by the arrival time of 5 processes\n");
    for(int i=0;i<5;i++)
    {
        printf("Enter for %d process \n",i+1);
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]); 
    }
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(a[i][2]>a[j][2])
            {
                d=a[i][0];
                a[i][0]=a[j][0];
                a[j][0]=d;
                d=a[i][1];
                a[i][1]=a[j][1];
                a[j][1]=d;
                d=a[i][2];
                a[i][2]=a[j][2];
                a[j][2]=d;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        b[i][0]=a[i][0];
        b[i][1]=a[i][1];
        b[i][2]=a[i][2];
    }
    int clock=a[0][2];
    for(int i=0;i<5;i++)
    {
        if(clock>=a[i][2])
        {
            clock=clock+a[i][1];
            b[i][3]=clock;
            b[i][4]=b[i][3]-b[i][2];
            b[i][5]=b[i][4]-b[i][1];
        }
        else
        {
            clock++;
            i--;
        }
    }
    printf("After FCFS Scheduling \n");
    printf("Process No. Burst Time Arrival Time Completion Time Turnaround Time Waiting Time\n");
    for(int i=0;i<5;i++)
    {
        printf("\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",b[i][0],b[i][1],b[i][2],b[i][3],b[i][4],b[i][5]);
    }
    return 0;
}