//fcfs.c
#include <stdio.h>
void main()
{
    int n, a[10], b[10], w[10], t[10], g[10], i, m;
    float awt=0, att=0;
    for(i=0; i<10; i++){
        a[i]=0;
        b[i]=0;
        w[i]=0;
        g[i]=0;
    }
    printf("Enter no. of processes:");
    scanf("%d",&n);
    printf("Enter arrival times:");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    printf("Enter burst times:");
    for(i=0; i<n; i++)
        scanf("%d", &b[i]);
    g[0]=0;
    for(i=0; i<10; i++)
        g[i+1]=g[i]+b[i];
    for(i=0; i<n; i++){
        w[i]=g[i]-a[i];
        t[i]=g[i+1]-a[i];
        awt=awt+w[i];
        att=att+t[i];
    }
    awt=awt/n;
    att=att/n;
    printf("\nProcess\tArrival_time\tBurst_time\tCompletion_time\tWaiting_time\tTurn-around_time\n");
    for(i=0; i<n; i++){
        printf("\n%d\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", i, a[i], b[i], g[i+1], w[i], t[i]);
    }
    printf("The average waiting time is %f:\n", awt);
    printf("The average turn-around time is %f:\n", att);
}