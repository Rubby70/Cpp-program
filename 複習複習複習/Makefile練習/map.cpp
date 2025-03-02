#include <bits/stdc++.h>
using namespace std;

extern int dx[4];
extern int dy[4];

#include "map.h"

void test(){}

// 檢查是否在迷宮範圍內
bool is_valid(int x, int y, int height, int width) {
    return (y >= 0) && (y < height) && (x >= 0) && (x < width);
}

// 廣度優先搜索，計算所有路徑
int count_paths(char **maze, int height, int width, int sx, int sy, int ex, int ey) {
    int path_count = 0;
    
    // 創建訪問和路徑記錄陣列
    bool **visited = (bool**)malloc(height * sizeof(bool*));
    int **path_length = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        visited[i] = (bool*)malloc(width * sizeof(bool));
        path_length[i] = (int*)malloc(width * sizeof(int));
    }
    
    // 創建隊列
    int **queue = (int**)malloc(height * width * sizeof(int*));
    for (int i = 0; i < height * width; i++) {
        queue[i] = (int*)malloc(2 * sizeof(int));
    }
    
    int front = 0, rear = 0;
    
    // 將起點加入隊列
    queue[rear][0] = sx;
    queue[rear][1] = sy;
    rear++;
    visited[sy][sx] = true;
    path_length[sy][sx] = 1;
    
    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;
        
        // 如果到達終點，增加路徑計數
        if (x == ex && y == ey) {
            path_count++;
        }
        
        // 嘗試四個方向
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 檢查是否可移動
            if (is_valid(nx, ny, height, width) && 
                maze[ny][nx] != '#') {
                
                // 第一次訪問
                if (!visited[ny][nx]) {
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                    visited[ny][nx] = true;
                    path_length[ny][nx] = path_length[y][x] + 1;
                }
                // 發現另一條路徑
                else if (path_length[ny][nx] == path_length[y][x] + 1) {
                    path_count++;
                }
            }
        }
    }
    
    // 釋放記憶體
    for (int i = 0; i < height; i++) {
        free(visited[i]);
        free(path_length[i]);
    }
    free(visited);
    free(path_length);
    
    for (int i = 0; i < height * width; i++) {
        free(queue[i]);
    }
    free(queue);
    
    return path_count;
}

// 生成迷宮
void generate_maze(char** &maze, int height, int width, int &path_count, int &sx, int &sy, int &ex, int &ey) {
    
    // 初始化迷宮為牆壁，確保最外圍是牆壁
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = '#';
        }
    }
    
    // 隨機生成通道（跳過最外圍）
    for (int i = 2; i < height - 2; i += 2) {
        for (int j = 2; j < width - 2; j += 2) {
            maze[i][j] = ' ';
            
            // 隨機打通相鄰的牆壁，增加多樣性
            int wall_count = rand() % 3 + 1;  // 1-3面牆
            for (int k = 0; k < wall_count; k++) {
                int wall = rand() % 4;
                int nx = i + dx[wall];
                int ny = j + dy[wall];
                
                if(is_valid(nx, ny, height, width) && 
                    ny > 0 && ny < (height - 1) &&
                    nx > 0 && nx < (width - 1)){
                    maze[ny][nx] = ' ';
                }
            }
        }
    }
    
    // 選擇隨機起點和終點（排除最外圍）
    int max_attempts = 100;

    while (path_count < 1 && max_attempts > 0) {
        // 選擇起點和終點
        sy = rand() % (height - 2) + 1;
        sx = rand() % (width - 2) + 1;
        ey = rand() % (height - 2) + 1;
        ex = rand() % (width - 2) + 1;
        
        // 確保起點和終點不在牆上，且不在同一位置
        if (maze[sy][sx] != '#' && maze[ey][ex] != '#' && 
            (sx != ex || sy != ey)) {
            
            // 檢查路徑數量
            path_count = count_paths(maze, height, width, sx, sy, ex, ey);
        }
        
        max_attempts--;
    }
    
    // 如果無法找到多條路徑
    if (path_count <= 0) {
        printf("無法生成具有路徑的迷宮，請重新嘗試。\n");
        
        // 釋放記憶體
        for (int i = 0; i < height; i++) {
            free(maze[i]);
        }
        free(maze);
        
        return;
    }
    
    // 標記起點和終點
    maze[sy][sx] = 'S';
    maze[ey][ex] = 'E';
    
}

//印出迷宮
void PrintMaze(char** maze, int height, int width){

    printf(" ");
    for(int i = 0; i < width; i ++){
        printf("%d", i);
    }
    printf("\n");

    for (int i = 0; i < height; i++) {
        printf("%d", i);
        for (int j = 0; j < width; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

