#include <bits/stdc++.h>
using namespace std;

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

};


int main(void){

    int rows = 10;
    int cols = 10;
    char maze[rows][cols];
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j ++){
            if(i == 0 || i == (rows - 1)){
                maze[i][j] = '#';
            }
            else if(j == 0 || j == (cols - 1)){
                maze[i][j] = '#';
            }
            else{
                maze[i][j] = ' ';
            }
        }
    }

    int start_x = 1;
    int start_y = 1;
    int dest_x = rows - 2;
    int dest_y = cols - 2;
    maze[start_x][start_y] = 'S';
    maze[dest_x][dest_y] = 'E';

    printf("\n");
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j ++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /*******************************************/

    while(1){
        int max_step_count = rows * cols;
        //紀錄最終路徑
        int path_x[max_step_count];
        int path_y[max_step_count];
        for(int i = 0; i < max_step_count; i ++){
            path_x[i] = -1;
            path_y[i] = -1;
        }

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
        int newX, newY;
        int i;
        int cnt = 0;
        while(1){
            //隨機往上下左右移動一格
            for(i = 0; i < 4; i ++){
                newX = S.Top().PositionX() + dx[i];
                newY = S.Top().PositionY() + dy[i];

                printf("第%d步 (%d, %d) = '%c', ", cnt, newX, newY, maze[newX][newY]);
                switch(i){
                    case 0:
                        printf("往下走一步, ");
                        break;
                    case 1:
                        printf("往右走一步, ");
                        break;
                    case 2:
                        printf("往上走一步, ");
                        break;
                    case 3:
                        printf("往左走一步, ");
                        break;
                }

                if((newX < 1) || (newX >= cols - 1) || (newY < 1) || (newY >= rows - 1)){
                    printf("出界.\n");
                    continue;
                }

                if(visited[newX][newY] == 1){
                    printf("走過了.\n");
                    continue;
                }

                if(maze[newX][newY] == '#'){
                    printf("撞到牆.\n");
                    continue;
                }

                printf("\n");
                break;
            }

            //若上下左右都沒有可以移動的格子時，退回上一格
            if(i == 4 && maze[newX][newY] == '#'){
                S.Pop();
                cnt --;
                printf("無路可走, 退一步.\n");
                continue;
            }

            S.Push(position(newX, newY));
            cnt ++;
            visited[newX][newY] = 1;

            if((S.Top().PositionX() == dest_x) && (S.Top().PositionY() == dest_y)){
                printf("走到終點了.\n");
                break;
            }

        }

        break;
    }
    
    return 0;

}