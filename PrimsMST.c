// Prim's Algorithm in C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define INF 9999999

int ** createGraph(int n){
  int **G, i, j;
  G = (int **)malloc(n*sizeof(int));
  for(i = 0; i < n; i++){
    G[i] = (int *)malloc(n*sizeof(int));
  }
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("Enter Weight of %d - %d(0 if Not Connected):", i, j);
      scanf("%d", &G[i][j]);
    }
  }
  return G;
}

void disp(int n, int **G){
  int i, j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }
}

void Prims(int **G, int V, int r){
  int i, j, x, y;
  int *selected;
  int no_edge;
  selected = (int *)calloc(V, sizeof(int));
  memset(selected, 0, sizeof(selected));
  no_edge = 0;
  selected[r] = 1;
  
  printf("Edge : Weight\n");
  while (no_edge < V - 1) {
    unsigned long int min = INF;
    x = 0;
    y = 0;
    for (i = 0; i < V; i++) {
      if (selected[i]) {
        for (j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]){
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = 1;
    no_edge++;
  }
}

int main() {
  int V, **G, root;
  printf("Enter Number of Vertices:");
  scanf("%d", &V);
  G = createGraph(V);
  printf("Enter Root Vertex:");
  scanf("%d", &root);
  Prims(G, V, root);
  getch();
  clrscr();
  return 0;
}