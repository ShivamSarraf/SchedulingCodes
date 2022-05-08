#include<stdio.h>
#include<stdlib.h>
int k=-1,l=0,n;
typedef struct
{
    int pno;
    int bt;
    int at;
    int pri;
    int ct;
    int tat;
    int wt;
}process;
int remain(process p[])
{
    int d=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].pno>0)
            d++;
    }
    return d;
}
int ready(process p[])
{
    int d=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].pno==0)
            d++;
    }
    return d;
}
int find(process p[])
{
    int max=0,d=-1;
    for(int i=0;i<n;i++)
    {         
        if(p[i].pno==0&&p[i].pri>max)
        {
            max=p[i].pri;
            d=i;
        }
    }
    return d;
}
int main()
{
    int clock=0,d,p,z=0,b=-1;
    printf("Enter the no of processes for priority preemptive \n");
    scanf("%d",&n);
    process p1[n],p2[n];
    printf("Enter the process no, burst time, arrival time and priority for all the processes \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&p1[i].pno,&p1[i].bt,&p1[i].at,&p1[i].pri);
        p1[i].ct=p1[i].tat=p1[i].wt=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p1[i].at>p1[j].at)
            {
                d=p1[i].pno;
                p1[i].pno=p1[j].pno;
                p1[j].pno=d;
                d=p1[i].bt;
                p1[i].bt=p1[j].bt;
                p1[j].bt=d;
                d=p1[i].at;
                p1[i].at=p1[j].at;
                p1[j].at=d;
                d=p1[i].pri;
                p1[i].pri=p1[j].pri;
                p1[j].pri=d;
            } 
        }
    }
    for(int i=0;i<n;i++)
    {
        p2[i].pno=p1[i].pno;
        p2[i].at=p1[i].at;
        p2[i].bt=p1[i].bt;
        p2[i].pri=p1[i].pri;
        p2[i].ct=p1[i].ct;
        p2[i].tat=p1[i].tat;
        p2[i].wt=p1[i].wt;
    }
    clock=p1[0].at;
    for(;z<n;z++)
    {
        if(p1[z].at<=clock)
            p1[z].pno=0;
        else
            break;
    }
    while(1)
    {
        if(ready(p1)>=1)
        {
            p=find(p1);
            if(p>=0&&p<n)
            {
                if(p1[p].bt==1)
                {
                    clock++;
                    p1[p].pno=-1;
                    p1[p].bt=0;
                    p2[p].ct=clock;
                    p2[p].tat=p2[p].ct-p2[p].at;
                    p2[p].wt=p2[p].tat-p2[p].bt;
                }
                if(p1[p].bt>1)
                {
                    clock++;
                    p1[p].bt=p1[p].bt-1;
                }
            }
        }
        else
            break;
        for(;z<n;z++)
        {
            if(p1[z].at<=clock)
                p1[z].pno=0;
            else 
                break;
        }
        if(ready(p1)==0&&remain(p1)>0)
        {
            clock=p1[z].at;
            p1[z++].pno=0;
        }
    }
    printf("After Priority Preemptive Scheduling \n");
    printf("Process No.  Burst Time  Arrival Time  Priority Completion Time  Turnaround Time   Waiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("\t%d\t%d\t\t%d\t%d\t\t%d\t\t%d\t\t%d\n",p2[i].pno,p2[i].bt,p2[i].at,p2[i].pri,p2[i].ct,p2[i].tat,p2[i].wt);
    }
    return 0;
}