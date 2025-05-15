#include <stdio.h>
#include <conio.h>

void main() {
    int i, j, n, v, k, min, u, c[20][20], s[20], d[20];
    
    clrscr();
    
    printf("\n Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("\n Enter the cost adjacency matrix: ");
    printf("\n Enter 999 for no edge\n");
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\n Enter the source vertex: ");
    scanf("%d", &v);

    for (i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = c[v][i];
    }
    d[v] = 0;
    s[v] = 1;

    for (k = 2; k <= n; k++) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if ((s[i] == 0) && (d[i] < min)) {
                min = d[i];
                u = i;
            }
        }
        s[u] = 1;

        for (i = 1; i <= n; i++) {
            if (s[i] == 0) {
                if (d[i] > (d[u] + c[u][i])) {
                    d[i] = d[u] + c[u][i];
                }
            }
        }
    }

    printf("\n The shortest distance from %d is: ", v);
    for (i = 1; i <= n; i++) {
        printf("\n %d --> %d = %d", v, i, d[i]);
    }

    getch();
}

//OUTPUT:
Enter the number of vertices: 5
Enter the cost adjacency matrix:
Enter 999 for no edge
0 10 999 30 100
10 0 50 999 999
999 50 0 20 10
30 999 20 0 60
100 999 10 60 0
Enter the source vertex: 1
The shortest distance from 1 is:
1 --> 1 = 0
1 --> 2 = 10
1 --> 3 = 60
1 --> 4 = 30
1 --> 5 = 70
