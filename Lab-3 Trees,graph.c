//Leetcode exercise on tree
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
}
//OUTPUT:
      1
     / \
    2   2
   / \ / \
  3  4 4  3
true

// Leetcode exercise on graph:
int dfs(int** grid, int i, int j, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0)
        return 0;
    grid[i][j] = 0;
    return 1 + dfs(grid, i+1, j, rows, cols) +
               dfs(grid, i-1, j, rows, cols) +
               dfs(grid, i, j+1, rows, cols) +
               dfs(grid, i, j-1, rows, cols);
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
int grid[5][5] = {
    {0,0,1,0,0},
    {1,1,1,0,0},
    {0,0,0,1,1},
    {0,1,0,1,1},
    {0,1,0,0,0}
};
Max area of island = 5
