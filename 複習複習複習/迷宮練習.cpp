#include <bits/stdc++.h>
using namespace std;

// 定義方向：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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



//小白作答區
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

class position{

    private:
    public:
        position* parent;
        int x;
        int y;

        position(int x = -1, int y = -1, position* parent = NULL){

            this->x = x;
            this->y = y;
            this->parent = parent;

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
void DFS2(char** maze, int height, int width, int sx, int sy, int ex, int ey){

    printf("DFS:\n");
    bool visited[height][width];
    for(int i = 0; i < height; i ++){
        for(int j = 0; j < width; j ++){
            visited[i][j] = false;
        }
    }
    
    Stack S(1000);
    position start(sx, sy);
    S.Push(start);
    visited[sy][sx] = 1;

    int nowX;
    int nowY;
    int MaxDepth = 0;
    int CurrentDepth = 0;

    //持續迴圈直到找到終點或沒有路線可走
    while((S.Top().PositionX() != ex) || (S.Top().PositionY() != ey)){
        int i;
        for(i = 0; i < 4; i ++){
            nowX = S.Top().PositionX() + dx[i];
            nowY = S.Top().PositionY() + dy[i];

            //確保在迷宮範圍內
            if(!is_valid(nowX, nowY, height, width)){
                continue;
            }

            //確保之前沒有走過
            if(visited[nowY][nowX] == 1){
                continue;
            }

            //確保不是牆壁
            if(maze[nowY][nowX] == '#'){
                continue;
            }

            break;
        }

        //如果i == 4，代表四個方向都不能走了
        if(i == 4){
            //如果i == 4，並且Top保存的是起點的位置，代表沒路可走了
            if((S.Top().PositionX() == sx) && (S.Top().PositionY() == sy)){
                printf("沒有路通向終點.\n");
                return ;
            }

            //如果Current == Max，代表這條路形不通，用X做記號
            if(CurrentDepth == MaxDepth){
                maze[S.Top().PositionY()][S.Top().PositionX()] = 'X';
            }
            S.Pop();
            CurrentDepth --;

            int tempX = S.Top().PositionX();
            int tempY = S.Top().PositionY();
            // printf("四個方向都不能走, pop.\n");
            // printf("MaxDepth = %d, CurrentDepth = %d, now (%d, %d)\n", MaxDepth, CurrentDepth, tempX, tempY);
            // PrintMaze(maze, height, width);

            continue;
        }

        //避免把起點的S符號改掉
        if((S.Top().PositionX() != sx) || (S.Top().PositionY() != sy)){
            maze[S.Top().PositionY()][S.Top().PositionX()] = 'O';
        }

        //用N來標記現在的位置
        maze[nowY][nowX] = 'N';
        visited[nowY][nowX] = 1;
        S.Push(position(nowX, nowY));
        CurrentDepth ++;

        //如果Current > Max代表這是目前最深的深度
        if(CurrentDepth > MaxDepth){
            MaxDepth = CurrentDepth;
        }

        // printf("MaxDepth = %d, CurrentDepth = %d, now (%d, %d)\n", MaxDepth, CurrentDepth, nowX, nowY);
        // PrintMaze(maze, height, width);
    }

    printf("找到終點了.\n");
    printf("MaxDepth = %d, CurrentDepth = %d, now (%d, %d)\n", MaxDepth, CurrentDepth, nowX, nowY);
    PrintMaze(maze, height, width);
    
}
void DFS(char** maze, int height, int width, int sx, int sy, int ex, int ey){

    printf("DFS:\n");
    bool visited[height][width];
    for(int i = 0; i < height; i ++){
        for(int j = 0; j < width; j ++){
            visited[i][j] = false;
        }
    }
    
    Stack S(1000);
    position start(sx, sy);
    S.Push(start);
    visited[sy][sx] = 1;

    int nowX = sx;
    int nowY = sy;
    int MaxDepth = 0;
    int CurrentDepth = 0;
    bool movable = false;

    //持續迴圈直到找到終點或沒有路線可走
    while(!((S.Top().PositionX() == ex) && (S.Top().PositionY() == ey))){
        
        nowX = S.Top().PositionX();
        nowY = S.Top().PositionY();
        S.Pop();
        movable = false;
        visited[nowY][nowX] = true;
        if(nowX != sx || nowY != sy)
            maze[nowY][nowX] = 'O';
        for(int i = 0; i < 4; i ++){
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if(is_valid(nextX, nextY, height, width) && !visited[nextY][nextX] && maze[nextY][nextX] != '#'){
                S.Push(position(nextX, nextY));
                movable = true;
            }
        }
        if (!movable && !(nowX == sx && nowY == sy)) {
            maze[nowY][nowX] = 'X';
            if(S.IsEmpty()){
                printf("No path to end\n");
                break;
            }
        }
    }

    printf("找到終點了.\n");
    printf("MaxDepth = %d, CurrentDepth = %d, now (%d, %d)\n", MaxDepth, CurrentDepth, nowX, nowY);
    PrintMaze(maze, height, width);
    
}

class Queue{

    public:
        int capacity;
        int R; //rear
        int F; //front
        position** arr;

        Queue(int capacity){

            this->capacity = capacity;
            R = -1;
            F = -1;

            arr = (position**)malloc(sizeof(position*) * capacity);
            for(int i = 0; i < capacity; i ++){
                arr[i] = NULL;
            }

        }

        void push(position* input){
            
            if(((R + 1) % capacity) == F){
                printf("Queue is full.\n");
                return ;
            }

            if(R == -1){
                F = 0;
                R = 0;
                arr[R] = input;
            }
            else if((R + 1) % capacity == 0){
                R = 0;
                arr[R] = input;
            }
            else{
                arr[++ R] = input;
            }

        }

        void pop(){
            
            if(F == -1){
                printf("Queue is empty.\n");
                return ;
            }

            if(F == R){
                arr[F] = NULL;
                F = -1;
                R = -1;
            }
            else if((F + 1) % capacity == 0){
                arr[F] = NULL;
                F = 0;
            }
            else{
                arr[F ++] = NULL;
            }

        }

        position* front(){

            if(F == -1){
                printf("Queue is empty.\n");
                return NULL;
            }

            return arr[F];

        }

        bool IsEmpty(){

            return F == -1;

        }

};
void BFS(char** maze, int height, int width, int sx, int sy, int ex, int ey){

    printf("BFS:\n");
    bool visited[height][width];
    for(int i = 0; i < height; i ++){
        for(int j = 0; j < width; j ++){
            visited[i][j] = false;
        }
    }

    position* start = new position(sx, sy);

    Queue Q(100);
    Q.push(start);
    visited[sy][sx] = 1;

    //紀錄起點
    vector<position*> path;
    path.reserve(1000);
    path.push_back(start); 

    int nowX, nowY;
    int newX, newY;
    int MaxDepth = 0;
    int CurrentDepth = 0;

    int i;
    while((!Q.IsEmpty()) && !((Q.front()->PositionX() == ex) && (Q.front()->PositionY() == ey))){

        nowX = Q.front()->PositionX();
        nowY = Q.front()->PositionY();

        //目前這一步會顯示N
        if((nowX != sx) || (nowY != sy)){
            maze[nowY][nowX] = 'N';
        }

        visited[nowY][nowX] = true;
        // printf("now (%d, %d)\n", nowX, nowY);
        // PrintMaze(maze, height, width);

        for(i = 0; i < 4; i ++){
            newX = nowX + dx[i];
            newY = nowY + dy[i];

            //確保在迷宮範圍內
            if(!is_valid(newX, newY, height, width)){
                continue;
            }

            //確保之前沒有走過
            if(visited[newY][newX] == 1){
                continue;
            }

            //確保不是牆壁
            if(maze[newY][newX] == '#'){
                continue;
            }

            position* temp = Q.front();
            position* temp2 = new position(newX, newY, temp);
            Q.push(temp2);
            path.push_back(temp2);
        }

        Q.pop();

        //走過後就把記號改成O
        if((nowX != sx) || (nowY != sy)){
            maze[nowY][nowX] = 'O';
        }

    }

    if(Q.IsEmpty()){
        printf("沒有路通向終點.\n");
        return ;
    }

    nowX = Q.front()->PositionX();
    nowY = Q.front()->PositionY();
    maze[nowY][nowX] = 'N';
    printf("找到終點了.\n");
    printf("now (%d, %d)\n", nowX, nowY);
    PrintMaze(maze, height, width);

    //找最短路徑
    if(1){

    int path_x = -1;
    int path_y = -1;
    int last = path.size() - 1; 
    position* current = Q.front();

    while(1){
        path_x = current->PositionX();
        path_y = current->PositionY();
        if(current->parent == NULL){
            break;
        }
        maze[path_y][path_x] = 'P'; 
        current = current->parent;
    }
    maze[sy][sx] = 'S';
    maze[ey][ex] = 'E';

    printf("最短路徑:\n");
    PrintMaze(maze, height, width);

    }

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