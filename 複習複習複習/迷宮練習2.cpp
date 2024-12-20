#include <bits/stdc++.h>
using namespace std;

// 定義方向：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 檢查是否在迷宮範圍內
bool is_valid(int x, int y, int height, int width) {
    return x >= 0 && x < height && y >= 0 && y < width;
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

// 生成迷宮
void generate_maze(char** &maze, int height, int width, int &path_count, int &sx, int &sy, int &ex, int &ey) {
    // 分配記憶體
   
    
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
                
                if (is_valid(nx, ny, height, width) && 
                    nx > 0 && nx < height - 1 && 
                    ny > 0 && ny < width - 1) {
                    maze[nx][ny] = ' ';
                }
            }
        }
    }
    
    // 選擇隨機起點和終點（排除最外圍）
    
    int max_attempts = 100;
    
    while (path_count < 1 && max_attempts > 0) {
        // 選擇起點和終點
        sx = rand() % (height - 2) + 1;
        sy = rand() % (width - 2) + 1;
        ex = rand() % (height - 2) + 1;
        ey = rand() % (width - 2) + 1;
        
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

//小白作答區
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
void PrintMaze(char** maze, int height, int width){

    printf(" ");
    for(int i = 0; i < height; i ++){
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
void DFS(char** maze, int height, int width, int sx, int sy, int ex, int ey){

    bool visited[height][width];
    for(int i = 0; i < height; i ++){
        for(int j = 0; j < width; j ++){
            visited[i][j] = false;
        }
    }

    // for(int i = 0; i < height; i ++){
    //     for(int j = 0; j < width; j ++){
    //         printf("%d", visited[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    
    int cnt_step = 0;
    Stack S(1000);
    position start(sx, sy);
    S.Push(start);

    int nowX;
    int nowY;
    while(0){
        if((S.Top().PositionX() != ex) || (S.Top().PositionY() != ey)){
            if((cnt_step > 0) && (S.top == 0)){
                printf("沒有路通向終點.\n");
            }

            if(S.top != 0){
                maze[S.Top().PositionY()][S.Top().PositionX()] = '*';
            }

            for(int i = 0; i < 4; i ++){
                nowX = S.Top().PositionX() + dx[i];
                nowY = S.Top().PositionY() + dy[i];

                if(!is_valid(nowX, nowY, height, width)){
                    continue;
                }

                if(visited[nowX][nowY] == 1){
                    continue;
                }

                if(maze[nowY][nowX] == '#'){
                    continue;
                }
            }

            cnt_step ++;
            maze[nowY][nowX] = 'N';
            S.Push(position(nowX, nowY));
        }
    }

    nowX = S.Top().PositionX() + 1;
    nowY = S.Top().PositionY() + 0;
    maze[nowY][nowX] = 'N';
    printf("start (%d, %d)\n", S.Top().PositionY(), S.Top().PositionX());
    printf("new (%d, %d)\n", nowY, nowX);
    PrintMaze(maze, height, width);

}

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
    printf("start (%d, %d)\nend (%d, %d)\n", sy, sx, ey, ex);
    printf("從起點到終點的路徑數量：%d\n", path_count);
    PrintMaze(maze, height, width);

    DFS(maze, height, width, sx, sy, ex, ey);
    
    // 釋放記憶體
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
    return 0;
}