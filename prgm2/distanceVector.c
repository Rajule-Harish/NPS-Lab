#include <stdio.h>
#include <stdlib.h>

int n, A[100][100], p[100], d[100];

void bellmanFord()
{
    for (int i = 1; i < n; i++)   //number of iterations for n nodes n-1 iterations
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
        {
            if (d[u] + A[u][v] < d[v])
            {
                d[v] = d[u] + A[u][v];
                p[v] = u;
            }
        }
     }
    }
    
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
    {
        if (d[u] + A
            [u][v] < d[v])
        {
            printf("Negative edge weight exists!!\n");
            exit(0);
        }
    }
    }
}

int main()
{
    printf("Enter the number of nodes.\n");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix.\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    
    for (int source = 0; source < n; source++)
    {
        for (int i = 0; i < n; i++)
        {
        d[i] = 999;
        p[i] = -1;
        }
    
        d[source] = 0;
    
        bellmanFord();
    
    printf("Router: %d\n", source);
    for (int i = 0; i < n; i++)
    {
        if (i != source)
        {
            int j = i;
            while (p[j] != -1)
            {
                printf("%d <- ", j);
                j = p[j];
            }
        }
        printf("%d\t Cost: %d\n", source, d[i]);
     }
    }
    
    return 0;
}
