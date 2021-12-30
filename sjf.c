//// Shortest Job First(SJF) Scheduling Algorithm(Non Pre-emptive)
#include<stdio.h>
#include<malloc.h>

void main()
{
    int i, n,pars=0, *bt, *wt, *tat,*at,*p;
    float avgtat, avgwt;
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    bt = (int*)malloc(n*sizeof(int)); //burst time
    at = (int*)malloc(n*sizeof(int));//arrivaltime
    p = (int*)malloc(n*sizeof(int));//process number
    wt = (int*)malloc(n*sizeof(int));//wait time
    tat = (int*)malloc(n*sizeof(int));//Turnaround Time

//take burst time
    printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        p[i]=i;
    }

//take arrival time
   printf("\n Enter the arrival time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" arrival time for P%d : ", i);
        scanf("%d", &at[i]);

    }

//rearrange the process accorting to arrival time
   for(int x = 0; x < n ; x++ )
    {
    for (int y = x; y < n ; y++ )
    {
    if(at[y]<at[x])
    {
    int temp;

    temp=at[x];
    at[x]=at[y];
    at[y]=temp;

     temp=bt[x];
    bt[x]=bt[y];
     bt[y]=temp;

    temp=p[x];
    p[x]=p[y];
    p[y]=temp;
     }
    }
    }

//calc waiting time and turnaround time
    wt[0] = 0;
    tat[0] = bt[0];
    avgwt = wt[0];
    avgtat = tat[0];
    pars=bt[0];
    for(i=1; i<n; i++)
    {
//rearrange the process accorting to short burst time
    for(int x = i; x < n ; x++ )
    {
    for (int y = x; y < n ; y++ )
    {
    if(at[y]<pars)
    {
    if(bt[y]<bt[x])
    {
    int temp;

    temp=at[x];
    at[x]=at[y];
    at[y]=temp;

     temp=bt[x];
    bt[x]=bt[y];
     bt[y]=temp;

    temp=p[x];
    p[x]=p[y];
    p[y]=temp;
    } }
    }
    }
     //waiting time
    if((pars - at[i])<0)
       {
       wt[i] = 0;
       }
        else
        {
        wt[i] = pars - at[i];
        }
        tat[i] = wt[i] + bt[i];     //Turnaround Time = Waiting Time + Burst Time
        avgwt += wt[i];
        avgtat += tat[i];
    pars+=bt[i];
    }

    avgwt = avgwt/n;    // average waiting time
    avgtat = avgtat/n;  //average turnaround time.

//print table
    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", p[i], bt[i], wt[i], tat[i]);
    }

//print average waiting time and average turnaround time.
    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

//print gaant
    printf("\n \tGAANT CHART \n");
    printf("---------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}



