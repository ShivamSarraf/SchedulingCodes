#include<stdio.h>
int q=-1;
int main()
{
    int a[5][3],b[5][6],c[5][2],d,l;
    printf("Enter the process no. CPU burst time followed by the arrival time of 5 processes\n");
    for(int i=0;i<5;i++)
    {
        printf("Enter for %d process \n",i+1);
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    }
    for(int i=0;i<5;i++)
    {
        b[i][0]=a[i][0];
        b[i][1]=a[i][1];
        b[i][2]=a[i][2];
    }
    int clock=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[j][2]<=clock&&a[j][0]!=-1)
            {
                q++;
                c[q][0]=a[j][0];
                c[q][1]=a[j][1];
            }
        }
        if(q!=-1)
        {
            int min=c[0][1],pno=c[0][0];
            for(int k=0;k<=q;k++)
            {
                if(min>c[k][1])
                {
                    min=c[k][1];
                    pno=c[k][0];
                }
            }
            for(int k=0;k<5;k++)
            {
                if(pno==a[k][0])
                    l=k;
            }
            clock=clock+a[l][1];
            b[l][3]=clock;
            b[l][4]=b[l][3]-b[l][2];
            b[l][5]=b[l][4]-b[l][1];
            a[l][0]=-1;
        }
        else
        {
            clock++;
            i--;
        }
        q=-1;
    }
    printf("After SJF Scheduling \n");
    printf("Process No. Burst Time Arrival Time Completion Time Turnaround Time Waiting Time\n");
    for(int i=0;i<5;i++)
    {
        printf("\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",b[i][0],b[i][1],b[i][2],b[i][3],b[i][4],b[i][5]);
    }
    return 0;
}