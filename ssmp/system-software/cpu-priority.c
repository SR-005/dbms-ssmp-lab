#include<stdio.h>

struct process
{
    int id;
    int arrivaltime;
    int bursttime;
    int priority;
    int waitingtime;
    int turnaroundtime;
};

int main()
{
    int i,j,num;
    float avgwt=0,avgtat=0;
    printf("Enter the Total Number of Process: ");
    scanf("%d",&num);
    struct process p[num],temp;
    int ganttchart[num];

    for(i=0;i<num;i++)
    {
        p[i].id=i+1;
        printf("Enter the Arrival Time of P%d",p[i].id);
        scanf("%d",&p[i].arrivaltime);
        printf("Enter the Burst Time of P%d",p[i].id);
        scanf("%d",&p[i].bursttime);
        printf("Enter the Priority of P%d",p[i].id);
        scanf("%d",&p[i].priority);
    }

    for(i=0;i<num;i++)
    {
        for(j=0;j<num-i-1;j++)
        {
            if(p[j].priority>p[j+1].priority)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    ganttchart[0]=0;
    for(i=0;i<num;i++)
    {   
        p[i].waitingtime=ganttchart[i];
        ganttchart[i+1]=ganttchart[i]+p[i].bursttime;
        p[i].turnaroundtime=p[i].waitingtime+p[i].bursttime;
    }

    printf("PI\tAT\tBT\tPR\tWT\tTAT\n");
    for(i=0;i<num;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,p[i].arrivaltime,p[i].bursttime,p[i].priority,p[i].waitingtime,p[i].turnaroundtime);
    }

    printf("\nGANTT CHART\n");
    for(i=0;i<num;i++)
    {
        printf("P%d\t",i+1);
    }
    printf("\n");
    for(i=0;i<num;i++)
    {
        printf("\t%d",ganttchart[i+1]);
    }

    for(i=0;i<num;i++)
    {
        avgwt=avgwt+p[i].waitingtime;
        avgtat=avgtat+p[i].turnaroundtime;

    }

    avgwt=avgwt/num;
    avgtat=avgtat/num;
    printf("\nAVGWT: %f",avgwt);
    printf("\nAVGTAT: %f",avgtat);

}