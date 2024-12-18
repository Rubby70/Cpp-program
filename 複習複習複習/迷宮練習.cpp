#include <bits/stdc++.h>
using namespace std;

//宣告
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool is_valid(int x, int y, int height, int width);
void printMaze(char **maze, int rows, int cols);
int count_paths(char **maze, int height, int width, int sx, int sy, int ex, int ey);
void generate_maze(char** maze, int height, int width);
void DFS(char** maze, int rows, int cols, int start_x, int start_y, int dest_x, int dest_y);

//定義
bool is_valid(int x, int y, int height, int width) {
    return x >= 0 && x < height && y >= 0 && y < width;
}
void printMaze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}
int count_paths(char **maze, int height, int width, int sx, int sy, int ex, int ey) {
    int path_count = 0;
    
    // 創建訪問和路徑記錄陣列
    bool **visited = (bool**)malloc(height * sizeof(bool*));
    int **path_length = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        visited[i] = (bool*)calloc(width, sizeof(bool));
        path_length[i] = (int*)calloc(width, sizeof(int));
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
    visited[sx][sy] = true;
    path_length[sx][sy] = 1;
    
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
                maze[nx][ny] != '#') {
                
                // 第一次訪問
                if (!visited[nx][ny]) {
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                    visited[nx][ny] = true;
                    path_length[nx][ny] = path_length[x][y] + 1;
                }
                // 發現另一條路徑
                else if (path_length[nx][ny] == path_length[x][y] + 1) {
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
void generate_maze(char** maze, int height, int width){

    // 初始化迷宮為牆壁，確保最外圍是牆壁
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = '#';
        }
    }
    
    // 隨機生成通道（跳過最外圍）
    for (int i = 2; i < height - 1; i += 2) {
        for (int j = 2; j < width - 1; j += 2) {
            maze[i][j] = ' ';
            
            // 隨機打通相鄰的牆壁，增加多樣性
            int wall_count = rand() % 3 + 1;  // 1-3面牆
            for (int k = 0; k < wall_count; k++) {
                int wall = rand() % 4;
                int nx = i + dx[wall];
                int ny = j + dy[wall];
                
                if (is_valid(nx, ny, height, width) && 
                    nx > 0 && nx < height - 1 && 
                    ny > 0 && ny < width - 1) {
                    maze[nx][ny] = ' ';
                }
            }
        }
    }
    
    // 選擇隨機起點和終點（排除最外圍）
    int sx, sy, ex, ey;
    int max_attempts = 100;
    int path_count = 0;
    
    while (path_count < 2 && max_attempts > 0) {
        // 選擇起點和終點
        sx = rand() % (height - 2) + 1;
        sy = rand() % (width - 2) + 1;
        ex = rand() % (height - 2) + 1;
        ey = rand() % (width - 2) + 1;
        
        // 確保起點和終點不在牆上，且不在同一位置
        if (maze[sx][sy] != '#' && maze[ex][ey] != '#' && 
            (sx != ex || sy != ey)) {
            
            // 檢查路徑數量
            //path_count = count_paths(maze, height, width, sx, sy, ex, ey);
        }
        
        max_attempts--;
    }
    
    // 如果無法找到多條路徑
    while(0){
    if (path_count < 1) {
        printf("無法生成具有多條路徑的迷宮，請重新嘗試。\n");
        
        // 釋放記憶體
        for (int i = 0; i < height; i++) {
            free(maze[i]);
        }
        free(maze);
        
        return;
    }
    }
    
    // 標記起點和終點
    maze[sx][sy] = 'S';
    maze[ex][ey] = 'E';
    
    // 打印迷宮
    int rows = height;
    int cols = width;
    printf("\n完成的迷宮地圖, start:(%d, %d), end:(%d, %d)\n\n", sx, sy, ex, ey);
    printMaze(maze, rows, cols);
    printf("\n");
    DFS(maze, rows, cols, sx, sy, ex, ey);

    // 列印路徑數量
    while(0){
    printf("\n從起點到終點的路徑數量：%d\n", path_count);
    
    // 釋放記憶體
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
    }

}

//作答區
class position{

    private:
    public:
        int x;
        int y;

        position(int x = -1, int y = -1){

            this->x = x;
            this->y = y;

        }

        int PositionX(){

                return this->x;

        }

        int PositionY(){

                return this->y;

        }

};
class Stack{

    private:
    public:
        int capacity;
        int top;
        position* arr;

        Stack(int capacity){
            this->capacity = capacity;
            this->top = -1;
            arr = new position[this->capacity];
        }

        int Capacity(){
            
            return this->capacity;

        }

        position Top(){

            if(top == -1){
                printf("stack is empty.\n");
                return position();
            }

            return arr[top];

        }

        void Push(position input){

            if(top + 1 == capacity){
                printf("stack is full.\n");
                return ;
            }

            if(top == -1){
                top = 0;
                arr[top] = input;
            }
            else{
                arr[++ top] = input;
            }

        }

        void Pop(){

            if(top == -1){
                printf("stack is empty.\n");
                return ;
            }

            if(top == 0){
                arr[top] = position();
                top = -1;
            }
            else{
                arr[top --] = position();
            }

        }

        void ShowAll(){

            if(top == -1){
                printf("stack is empty.\n");
            }

            printf("[ ");
            for(int i = top; i >= 0; i --){
                printf("(%d, %d), ", arr[top].PositionX(), arr[top].PositionY());
            }
            printf("]\n");

        }

        bool IsEmpty(){

            return top == -1;

        }

};
void DFS(char** maze, int rows, int cols, int start_x, int start_y, int dest_x, int dest_y){

    int max_step_count = rows * cols;
    
    //記錄走過的路徑
    int visited[rows][cols];
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j ++){
            visited[i][j] = 0;
        }
    }
    visited[start_x][start_y] = 1;

    //找路
    Stack S(max_step_count);
    S.Push(position(start_x, start_y));
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int nowX, nowY;
    int i;
    while(1){
        //從上一輪的位置往上下左右移動一格
        for(i = 0; i < 4; i ++){
            nowX = S.Top().PositionX() + dx[i];
            nowY = S.Top().PositionY() + dy[i];

            //判定是否超出邊界
            if((nowX < 1) || (nowX >= cols - 1) || (nowY < 1) || (nowY >= rows - 1))
                continue;

            //判定是否已經走過
            if(visited[nowX][nowY] == 1)
                continue;

            //判定是否是牆
            if(maze[nowX][nowY] == '#')
                continue;

            //不符合上述三個條件時才前進一步
            // maze[nowX][nowY] = 'O'; //紀錄目前的位置
            // printMaze(maze, rows, cols);
            // printf("\n");
            break;
        }

        //若上下左右都沒有可以移動的格子時，退回上一步
        if(i == 4){
            if((S.Top().PositionX() == start_x) && (S.Top().PositionY() == start_y)){
                printf("無法走到終點.\n");
                return ;
            }
            
            //標記為死路
            nowX = S.Top().PositionX();
            nowY = S.Top().PositionY();
            if((nowX >= 1) && (nowX < cols - 1) && (nowY >= 1) && (nowY < rows - 1)){
                maze[nowX][nowY] = 'X';
            }

            S.Pop();
            // printf("倒退一步\n");
            // printMaze(maze, rows, cols);
            // printf("\n");
            continue;
        }

        //若不符合上一個if的條件時，代表這一步可以走
        if((S.Top().PositionX() != start_x) && (S.Top().PositionY() != start_y)){
            maze[S.Top().PositionX()][S.Top().PositionY()] = 'O';
        }

        S.Push(position(nowX, nowY));
        visited[nowX][nowY] = 1;
        maze[nowX][nowY] = 'N';
        printMaze(maze, rows, cols);
        printf("\n");

        if((S.Top().PositionX() == dest_x) && (S.Top().PositionY() == dest_y)){
            printf("走到終點了.\n");
            break;
        }

    }

}

int main() {

    srand(time(NULL));
    int height, width;
    printf("請輸入迷宮的高度和寬度（最小為4x4）：");
    scanf("%d %d", &height, &width);
    
    // 確保高度和寬度至少為4
    if (height < 4) height = 4;
    if (width < 4) width = 4;

    char** maze = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        maze[i] = (char*)malloc(width * sizeof(char));
    }
    
    generate_maze(maze, height, width);
    return 0;

}