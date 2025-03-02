#include <bits/stdc++.h>
using namespace std;

#include "map.h"
#include "dfs.h"

extern int dx[4], dy[4];
extern int sx, sy;

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
