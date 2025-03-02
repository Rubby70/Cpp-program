#include <bits/stdc++.h>
using namespace std;

#include "map.h"
#include "bfs.h"

extern int dx[4], dy[4];
extern int sx, sy;

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
