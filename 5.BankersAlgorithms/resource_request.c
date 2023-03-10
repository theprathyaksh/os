// 3 5 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 3 3 2
// 3 5 0 1 0 3 0 2 3 0 2 2 1 1 0 0 2 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 2 3 0
#include <stdio.h>
#include <stdbool.h>
int finish[20] = {0};
int process[20] = {0};
int alloc[10][10];
int max[10][10];
int need[10][10];
int work[10];
int count = 0;
bool allvisit(int n)
{
	int i;
    for (i = 0; i < n; i++)
    {
        if (finish[i] != 1)
            return false;
    }
    return true;
}
bool issafe(int n, int t)
{
	int i;
    for (i = 0; i < t; i++)
    {
        if (work[i] < need[n][i])
            return false;
    }
    return true;
}

void print(int n)
{
	int i;
    for (i = 0; i < n; i++)
    {
        printf(" P%d ", process[i]);
    }
    count++;
    printf("\n");
}

int bankers(int n, int t, int pos)
{
    if (pos >= n)
    {
        return 0;
    }

    int current[t];
    int i;
    for (i = 0; i < t; i++)
    {
        current[i] = work[i];
    }

    for (i = 0; i < n; i++)
    {
        if (issafe(i, t))
        {
            if (finish[i] == 0)
            {
                process[pos] = i;
                finish[i] = 1;
                int j;
                for (j = 0; j < t; j++)
                {
                    work[j] = work[j] + alloc[i][j];
                }
                if (allvisit(n))
                {
                    print(n);
                    bankers(n, t, pos + 1);
                }
                else
                {
                    bankers(n, t, pos + 1);
                }
                finish[i] = 0;
                for (j = 0; j < t; j++)
                {
                    work[j] = current[j];
                }
            }
        }
    }
}

int main()
{
    printf("enter no of sharable resources");
    int t,i,j;
    scanf("%d", &t);

    printf("enter no of processes");
    int n;
    scanf("%d", &n);
    printf("enter alloc matrix");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < t; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    // 3 5 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 3 3 2
    printf("enter max matrix");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < t; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("enter work array");
    for (i = 0; i < t; i++)
    {
        scanf("%d", &work[i]);
    }

    int option, P, rr[t];

    while (true)
    {
        printf("\nIf there is a resource request enter 1 else 0 :");
        scanf("%d", &option);
        if (option == 0)
        {
            break;
        }
        printf("\nEnter the process to make resource request:");
        scanf("%d", &P);

        printf("\nEnter the resource request of process %d:", P);
        for (i = 0; i < t; i++)
        {
            scanf("%d", &rr[i]);
            work[i] -= rr[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < t; j++)
        {
            if (i == P)
            {
                alloc[i][j] += rr[j];
            }

            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\n");
    printf("alloc matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < t; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\n");
    }

    printf("max matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < t; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("need matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < t; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("the possible safe sequences are \n");
    bankers(n, t, 0);

    if (count == 0)
    {
        printf("NO SAFE SEQUENCE IS POSSIBLE");
        return 0;
    }

    printf("the no of possible safe sequences is %d", count);
    return 0;
}
