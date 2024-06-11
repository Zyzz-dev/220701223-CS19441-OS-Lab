//Best Fit
#include<stdio.h>
#include<string.h>
void bestFit(int blockSize[], int m, int ProcessSize[], int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for(int i=0; i<n; i++)
    {
        int bestIdx=-1;
        for(int j=0; j<m; j++)
        {
            if(blockSize[j]>=ProcessSize[i])
            {
                if(bestIdx==-1)
                    bestIdx=j;
                if(blockSize[bestIdx]>blockSize[j])
                    bestIdx=j;
            }
        }
        if(bestIdx!=-1)
        {
            allocation[i]=bestIdx;
            blockSize[bestIdx]-=ProcessSize[i];
        }
    }
    printf("\nProcess_no.\tProcess_Size\tBlock_no.\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t\t%d", i+1, ProcessSize[i]);
        if(allocation[i]!=-1)
            printf("\t\t%d", allocation[i]+1);
        else
            printf("\nNot allocated");
        printf("\n");
    }
}

int main()
{
    int b_Size[]={100, 500, 200, 300, 600};
    int p_Size[]={212, 417, 112, 426};
    int m=sizeof(b_Size)/sizeof(b_Size[0]);
    int n=sizeof(p_Size)/sizeof(p_Size[0]);
    bestFit(b_Size, m, p_Size, n);
    return 0;
}