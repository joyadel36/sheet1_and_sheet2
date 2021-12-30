// Round Robin Scheduling Algorithm(Pre-emptive)

#include<stdio.h>
#include<malloc.h>

void main()
{
    int n, i, tempn, count, terminaltime=0, initialtime, qt, flag=0, *bt, *wt, *tat, *tempbt,*at,*p;
    float avgwt = 0, avgtat = 0;
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);
    tempn = n;

    tempbt = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int)); //burst time
    at = (int*)malloc(n*sizeof(int));//arrivaltime
    p = (int*)malloc(n*sizeof(int));//process number
    wt = (int*)malloc(n*sizeof(int));//wait time
    tat = (int*)malloc(n*sizeof(int));//Turnaround Time

    printf("\n Enter the Quantum Time : ");
    scanf("%d", &qt);

    printf("\n Enter the burst time for each process \n\n");
    for(i=0; i<n; i++)
    {
        printf(" Burst time of P%d : ", i);
        scanf("%d", &bt[i]);
        tempbt[i] = bt[i];
        //terminaltime += bt[i];
    }

    //take arrival time
   printf("\n Enter the arrival time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" arrival time for P%d : ", i);
        scanf("%d", &at[i]);
         p[i]=i;
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

    temp=tempbt[x];
     tempbt[x]= tempbt[y];
     tempbt[y]=temp;
     }
    }
    }

    wt[0] = 0;
    printf("\n\t GAANT CHART \n");
    printf("\n----------------------------\n");

    for(terminaltime=0, count=0; tempn!=0;) {
        initialtime = terminaltime;
        if(tempbt[count] <= qt && tempbt[count] > 0) {
            terminaltime += tempbt[count];
            tempbt[count] = 0;
            wt[count] = terminaltime - bt[count]-at[count];
            tat[count] = wt[count] + bt[count];
            flag = 1;
        }
        else if(tempbt[count] > qt) {
            tempbt[count] -= qt;
            terminaltime += qt;
        }
        if(tempbt[count] == 0 && flag == 1) {
            tempn--;
            flag=0;
        }
        if(initialtime != terminaltime) {
            printf(" %d\t|| P%d ||\t%d\n", initialtime, count, terminaltime);
        }
        if(count == n-1)
            count = 0;
        else
            ++count;
    }

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("-----------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", p[i], bt[i], wt[i], tat[i]);
         avgwt += wt[i];
        avgtat += tat[i];
    }


    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);
}
