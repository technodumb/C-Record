// Create a graph using adjascency matrix and traverse using Breadth First Scan and Depth First Scan.


#include<stdio.h>

int Graph[20][20], visited[20], n;

void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    for(j=1; j<=n; j++)
        if(!visited[j] && Graph[i][j]==1)
            DFS(j);
}

void DFS_main(){
    for(int i=1; i<=n; i++)
        visited[i] = 0;

    DFS(1);
}

int queue[20], front=0, rear=-1;

void BFS(int v){
    visited[v] = 1;
    printf("\n%d", v);
    for(int i=1; i<=n; i++){
        if(Graph[v][i] && !visited[i]){
            queue[++rear] = i;
            visited[i] = 1;
        }
    }
    if(front<=rear){
        BFS(queue[front++]);
    }
}

void BFS_main(){
    for(int i=1; i<=n; i++){
        visited[i] = 0;
    }
    BFS(1);
}

void main() {
    int choice=0;
    do {
        printf("\n\n\nMENU \n");
        printf("1. Enter Graph details\n");
        printf("2. DFS \n");
        printf("3. BFS \n");
        printf("4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &n);
                printf("Enter the adjacency matrix of the graph: \n");
                for(int i=1; i<=n; i++)
                    for(int j=1; j<=n; j++)
                        scanf("%d", &Graph[i][j]);
                break;
            case 2:
                DFS_main();
                break;
            case 3:
                BFS_main();
                break;
            case 4:
                printf("Exiting");
                break;
            default:
                printf("Invalid choice");
        }
    } while(choice!=4);
}