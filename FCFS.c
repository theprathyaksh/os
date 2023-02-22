#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,start,head_moments = 0;
    printf("\nEnter the head pointer starting position:");
    scanf("%d",&start);
    printf("\nEnter the no. of sector locations:");
    scanf("%d",&n);
    int sec_loc[n+1];
    sec_loc[0] = start;
    printf("\nEnter the sector locations:");

	int i;
    for (i = 1; i <= n; i++)
    {
        scanf("%d",&sec_loc[i]);
    }

    for (i = 0; i < n; i++)
    {
        head_moments += abs(sec_loc[i] - sec_loc[i+1]); 
        printf("%d\n",head_moments);
    }

    printf("Total no. of head moments: %d",head_moments);
    
//53 8 98 183 41 122 14 124 65 67
    
    return 0;
}
