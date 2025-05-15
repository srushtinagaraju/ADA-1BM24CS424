// Leetcode exercises in DFS
int dfs(int** grid, int row, int col, int rows, int cols) {
    if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0)
        return 0;

    grid[row][col] = 0; 
    int area = 1;

    area += dfs(grid, row+1, col, rows, cols);
    area += dfs(grid, row-1, col, rows, cols);
    area += dfs(grid, row, col+1, rows, cols);
    area += dfs(grid, row, col-1, rows, cols);

    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int maxArea = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                int area = dfs(grid, i, j, gridSize, gridColSize[i]);
                if (area > maxArea)
                    maxArea = area;
            }
        }
    }
    return maxArea;
}


//OUTPUT:
grid = [
  [0,0,1,0,0,0,0,1,0,0,0],
  [0,0,0,0,0,0,0,1,1,1,0],
  [0,1,1,0,1,0,0,0,0,0,0],
  [0,1,0,0,1,1,0,0,1,0,0],
  [0,1,0,0,1,1,0,0,1,1,0],
  [0,0,0,0,0,0,0,0,0,0,0]
]
  Max area of island = 6

//Leetcode exercise on BFS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x, y, dist;
} Cell;

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
    if (grid[0][0] != 0 || grid[gridSize - 1][*gridColSize - 1] != 0) return -1;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    Cell queue[gridSize * (*gridColSize)];
    int front = 0, rear = 0;
    queue[rear++] = (Cell){0, 0, 1};
    grid[0][0] = 1;

    while (front < rear) {
        Cell curr = queue[front++];
        if (curr.x == gridSize - 1 && curr.y == *gridColSize - 1)
            return curr.dist;

        for (int i = 0; i < 8; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < gridSize && ny < *gridColSize && grid[nx][ny] == 0) {
                grid[nx][ny] = 1; // mark visited
                queue[rear++] = (Cell){nx, ny, curr.dist + 1};
            }
        }
    }

    return -1;
}

//OUTPUT:
grid = [
  [0,1,0],
  [1,0,1],
  [1,1,0]
]
  Shortest path length = 4
