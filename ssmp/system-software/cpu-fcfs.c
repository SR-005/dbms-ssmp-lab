#include<stdio.h>

int main()
{
    int i,num,burst;
    float avgwt=0,avgtat=0;
    printf("Enter the Total Number of Process: ");
    scanf("%d",&num);
    int arrivaltime[num],bursttime[num],waitingtime[num],turnaroundtime[num],ganttchart[num];
    ganttchart[0]=0;        //gantt chart starts with 0
    for(i=0;i<num;i++)
    {
        printf("Enter the Arrival Time of P%d: ",i+1);
        scanf("%d",&arrivaltime[i]);
        printf("Enter the Burst Time of P%d: ",i+1);
        scanf("%d",&bursttime[i]);

        burst=burst+bursttime[i];    //calculating ending time of current process for gantt chart
        ganttchart[i+1]=burst;      //adding total burst time to ganttchart

        if(i==0)
        {
            waitingtime[i]=0;
        }
        else
        {
            waitingtime[i]=ganttchart[i]-arrivaltime[i];    //burst time of the last process - time at which current process arrives
        }
        
        turnaroundtime[i]=waitingtime[i]+bursttime[i];
    }

    printf("PI\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<num;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,arrivaltime[i],bursttime[i],waitingtime[i],turnaroundtime[i]);
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
        avgwt=avgwt+waitingtime[i];
        printf("WT: %d",waitingtime[i]);
        printf("WT: %f",avgwt);
        avgtat=avgtat+turnaroundtime[i];
        printf("TAT: %d",turnaroundtime[i]);
        printf("TAT: %f",avgtat);
    }

    avgwt=avgwt/num;
    avgtat=avgtat/num;
    printf("\nAVGWT: %f",avgwt);
    printf("\nAVGTAT: %f",avgtat);
}

