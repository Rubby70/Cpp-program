#ifndef BFS_H
#define BFS_H

void BFS(char** maze, int height, int width, int sx, int sy, int ex, int ey);

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

#endif