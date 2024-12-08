#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void generateMaze(char **maze, int rows, int cols) {
    // 初始化迷宫地图为全部为 '#'
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = '#';
        }
    }
 
    // 随机选择起点和终点（位置不能在边界上）
    srand((unsigned int) time(NULL));
    int start_x, start_y, dest_x, dest_y;
    do {
        start_x = rand() % (rows - 2) + 1;
        start_y = rand() % (cols - 2) + 1;
        dest_x = rand() % (rows - 2) + 1;
        dest_y = rand() % (cols - 2) + 1;
    } while (start_x == dest_x && start_y == dest_y);
 
    // 生成迷宫
    maze[start_x][start_y] = ' ';         // 起点设为可走
    maze[dest_x][dest_y] = ' ';           // 终点设为可走
    int visited[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }
    int dx[4] = {-1, 0, 1, 0};            // 向四个方向移动
    int dy[4] = {0, 1, 0, -1};
    int stack_x[rows * cols], stack_y[rows * cols];  // 模拟栈，用于回溯
    int top = 0;
    stack_x[top] = start_x;
    stack_y[top] = start_y;
    visited[start_x][start_y] = 1;
    while (top >= 0) {
        int x = stack_x[top];
        int y = stack_y[top];
        int flag = 0;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 1 && new_x < rows - 1 && new_y >= 1 && new_y < cols - 1 &&
                maze[new_x][new_y] == '#' && visited[new_x][new_y] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            int r = rand() % 4;
            int new_x = x + dx[r];
            int new_y = y + dy[r];
            if (new_x >= 1 && new_x < rows - 1 && new_y >= 1 && new_y < cols - 1 &&
                maze[new_x][new_y] == '#' && visited[new_x][new_y] == 0) {
                maze[(x+new_x)/2][(y+new_y)/2] = ' ';  // 打通两个相邻格子之间的墙
                visited[new_x][new_y] = 1;
                stack_x[++top] = new_x;
                stack_y[top] = new_y;
            }
        } else {
            top--;
        }
    }
}
 
void printMaze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}
 
void dfs(char **maze, int rows, int cols, int x, int y, int dest_x, int dest_y, int **visited, int *path_x, int *path_y, int *path_len) {
    if (x == dest_x && y == dest_y) {
        *path_len += 1;
        path_x[*path_len] = x;
        path_y[*path_len] = y;
        return;
    }
 
    visited[x][y] = 1;
    int dx[4] = {-1, 0, 1, 0};  // 向四个方向移动
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols &&
            maze[new_x][new_y] == ' ' && visited[new_x][new_y] == 0) {
            *path_len += 1;
            path_x[*path_len] = x;
            path_y[*path_len] = y;
            dfs(maze, rows, cols, new_x, new_y, dest_x, dest_y, visited, path_x, path_y, path_len);
            *path_len -= 1;
        }
    }
}
 
int main() {
    int rows, cols;
    printf("请输入迷宫的行数和列数：");
    scanf("%d %d", &rows, &cols);
    char **maze = (char **) malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        maze[i] = (char *) malloc(cols * sizeof(char));
    }
    generateMaze(maze, rows, cols);
    printMaze(maze, rows, cols);
 
    // 求解路径
    int **visited = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        visited[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }
    int path_x[rows * cols], path_y[rows * cols], path_len = -1;
    dfs(maze, rows, cols, 1, 1, rows-2, cols-2, visited, path_x, path_y, &path_len);
 
    // 输出路径
    printf("\n正确路径：\n");
    printf("path_len = %d", path_len);
    for (int i = path_len; i >= 0; i--) {
        maze[path_x[i]][path_y[i]] = '*';
        printf("(%d, %d) -> ", path_x[i], path_y[i]);
    }
    //printMaze(maze, rows, cols);
 
    // 释放动态分配的内存
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
        free(visited[i]);
    }
    free(maze);
    free(visited);
    return 0;
}