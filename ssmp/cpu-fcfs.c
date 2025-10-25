#include<stdio.h>

int main()
{
    int i,num,burst;
    printf("Enter the Total Number of Process: ");
    scanf("%d",&num);
    int arrivaltime[num],bursttime[num],waitingtime[num],turnaroundtime[num],ganttchart[num];
    ganttchart[0]=0;        //gantt chart starts with 0
    for(i=0;i<num;i++)
    {
        printf("Enter the Arrival Time of P%d: ",i+1);
        scanf("%d",arrivaltime[i]);
        printf("Enter the Burst Time of P%d: ",i+1);
        scanf("%d",bursttime[i]);

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
}