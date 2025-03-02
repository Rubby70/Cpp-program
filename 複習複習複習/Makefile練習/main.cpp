#include <bits/stdc++.h>
using namespace std;

#include "map.h"
#include "bfs.h"
#include "dfs.h"

// 定義方向：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    srand(time(NULL));
    int height, width;
    printf("請輸入迷宮的高度和寬度(最小為4x4): ");
    scanf("%d %d", &height, &width);
    
    // 確保高度和寬度至少為4
    if (height < 4) height = 4;
    if (width < 4) width = 4;
    
    char **maze = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        maze[i] = (char*)malloc(width * sizeof(char));
    }
    int sx = -1;
    int sy = -1;
    int ex = -1;
    int ey = -1;
    int path_count = 0;
    generate_maze(maze, height, width, path_count, sx, sy, ex, ey);
    
    if(path_count == 0){
        return 0;
    }

    // 打印迷宮
    printf("start (%d, %d)\nend (%d, %d)\n", sx, sy, ex, ey);
    printf("從起點到終點的路徑數量：%d\n", path_count);
    PrintMaze(maze, height, width);

    //DFS(maze, height, width, sx, sy, ex, ey);
    BFS(maze, height, width, sx, sy, ex, ey);

    // 釋放記憶體
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
    return 0;
}