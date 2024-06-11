//fifo.c
#include<stdio.h>
int main()
{
    int n, p[50], m, f[10], i, j, k, avail, count=0;
    printf("Enter no. of pages:\n");
    scanf("%d", &n);
    printf("Enter page numbers:\n");
    for(i=0; i<n; i++)
        scanf("%d", &p[i]);
    printf("Enter no. of frames:");
    scanf("%d", &m);
    printf("Enter page numbers:");
    for(i=0; i<m; i++)
        f[i]=-1;
    j=0;
    printf("\n\tref_string\t\tpage\t\tframes\n");
    for(i=0; i<n; i++){
        printf("%d\t\t", p[i]);
        avail=0;
        for(k=0; k<m; k++){
            if(f[k]==p[i])
                avail=1;
            if(avail==0){
                f[j]=p[i];
                j=(j+1)%m;
                count++;
                for(k=0; k<m; k++)
                    printf("%d\t\t", f[k]);
            }
            printf("\n");
        }
    }
    printf("Total page faults:%d", count);
    return 0;
}