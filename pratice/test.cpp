#include <stdio.h>


int main(void){

    int x = 10;
    int y = 20;
    {
        printf("x = %d, y = %d\n", x, y);
        {
            int y = 40;
            x ++;
            y ++;
            printf("x = %d, y = %d\n", x, y);
        }
        printf("x = %d, y = %d\n", x ,y);
    }
    return 0;

}