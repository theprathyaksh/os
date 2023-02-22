#include<stdio.h>
#include<stdlib.h>

void calculatedifference(int request[], int head,int diff[][2], int n)
{
	int i;
	for( i = 0; i < n; i++)
	{
		diff[i][0] = abs(head - request[i]);
	}
}
int findMIN(int diff[][2], int n)
{
	int index = -1;
	int minimum = 1e9;
	int i;

	for(i = 0; i < n; i++)
	{
		if (!diff[i][1] && minimum > diff[i][0])
		{
			minimum = diff[i][0];
			index = i;
		}
	}
	return index;
}

void shortestSeekTimeFirst(int request[],int head, int n)
{
	if (n == 0)
	{
		return;
	}
	// Create array of objects of class node
	int diff[n][2];
	int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<2;j++){
            diff[i][j]=0;
        }
    }
	
	int seekcount = 0;
	int seeksequence[n + 1];
	
    for(i=0;i<n+1;i++)seeksequence[i]=0;
	
		for(i = 0; i < n; i++)
	{
		seeksequence[i] = head;
		calculatedifference(request, head, diff, n);
		int index = findMIN(diff, n);
		diff[index][1] = 1;
		seekcount += diff[index][0];
		head = request[index];
	}
	seeksequence[n] = head;
	printf("Total number of seek operations = %d",seekcount);
	printf("\nSeek sequence is : \n");
	for(i = 0; i <= n; i++)
	{
		printf("%d",seeksequence[i]);
        printf("\n");
	}
}
int main()
{
	int n,i,head;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&arr[i]);
    printf("Enter initial head position\n");
    scanf("%d",&head);
	shortestSeekTimeFirst(arr,head,n);
	return 0;
}
