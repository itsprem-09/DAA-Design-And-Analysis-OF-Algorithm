#include<stdio.h>
#include<limits.h>
#define V 5

void main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    int visited[V] = {0};
    visited[0] = 1;

    int edges = 0;

    int minCost = 0;

    while (edges < V - 1)
    {
        int starNode, endNode = 0;
        int minWeight = INT_MAX;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 1 )
            {
                for (int j = 0; j < V; j++)
                {
                    if (visited[j] == 0 && graph[i][j] != 0)
                    {
                        if (graph[i][j] < minWeight)
                        {
                            minWeight = graph[i][j];
                            starNode = i;
                            endNode = j;
                        }
                    }
                }
            }
        }
        
        visited[endNode] = 1;
        edges++;
        minCost += minWeight; 
        printf("Edge : %d -- %d == %d\n", starNode, endNode, graph[starNode][endNode]);
    }
    

}