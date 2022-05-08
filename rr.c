#include<stdio.h>
#include<stdlib.h>
int k=-1,l=0,n;
typedef struct
{
    int pno;
    int bt;
    int at;
    int ct;
    int tat;
    int wt;
}process;
int find(int x,process p[])
{
    for(int i=0;i<n;i++)
    {         
        if(p[i].pno==x)
            return i;
    }
    return n;
}
int pcounter(process p[])
{
    int d=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].pno==-1)
            d++;
    }
    if(d==n)
        return 1;
    else 
    return 0;
}
int main()
{
    int t,clock=0,d,p,z=1,b=-1;
    printf("Enter the no of processes and time slice for round robin \n");
    scanf("%d%d",&n,&t);
    process p1[n],p2[n];
    int a[100];
    printf("Enter the process no, burst time and arrival for all the processes \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&p1[i].pno,&p1[i].bt,&p1[i].at);
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
            } 
        }
    }
    for(int i=0;i<n;i++)
    {
        p2[i].pno=p1[i].pno;
        p2[i].at=p1[i].at;
        p2[i].bt=p1[i].bt;
        p2[i].ct=p1[i].ct;
        p2[i].tat=p1[i].tat;
        p2[i].wt=p1[i].wt;
    }
    clock=p1[0].at;
    a[++k]=p1[0].pno;
    p1[0].pno=-1;
    while(l<=k)
    {
        p=find(a[l],p2);
        if(p>=0&&p<n)
        {
            if((p1[p].bt>0)&&(p1[p].bt<=t))
            {
                l++;
                clock=clock+p1[p].bt;
                p1[p].bt=0; 
                p2[p].ct=clock;
                p2[p].tat=p2[p].ct-p2[p].at;
                p2[p].wt=p2[p].tat-p2[p].bt;
            }
            if(p1[p].bt>t)
            {
                l++;
                p1[p].bt=p1[p].bt-t;
                clock=clock+t;
            }
            for(;z<n;z++)
            {
                if((p1[z].at<=clock)&&(p1[z].pno!=-1))
                {
                    a[++k]=p1[z].pno;
                    p1[z].pno=-1;
                }
                else    
                    break;
            }
            if(p1[p].bt>0)
            {
                a[++k]=p2[p].pno;
            }
        }
        if(l>k&&pcounter(p1)==0)
        {
            k++;
            a[l]=n+1;
            clock=p1[z].at;
            for(;z<n;z++)
                {
                    if((p1[z].at<=clock)&&(p1[z].pno!=-1))
                    {
                        a[++k]=p1[z].pno;
                        p1[z].pno=-1;
                        l++;
                    }
                    else    
                        break;
                }
        }
    }
    printf("After RR Scheduling \n");
    printf("Process No.  Burst Time  Arrival Time  Completion Time  Turnaround Time   Waiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p2[i].pno,p2[i].bt,p2[i].at,p2[i].ct,p2[i].tat,p2[i].wt);
    }
    return 0;
}