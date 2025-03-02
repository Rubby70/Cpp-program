#ifndef MAP_H
#define MAP_H

bool is_valid(int x, int y, int height, int width);
int count_paths(char **maze, int height, int width, int sx, int sy, int ex, int ey);
void generate_maze(char** &maze, int height, int width, int &path_count, int &sx, int &sy, int &ex, int &ey);
void PrintMaze(char** maze, int height, int width);

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

#endif