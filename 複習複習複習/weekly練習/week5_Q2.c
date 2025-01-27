// 螺旋矩陣 給你一個m x n的矩陣 按照順時針螺旋的順序 把矩陣中的元素印出來 
// Ex:3 3
// 	1 2 3
// 	4 5 6
// 	7 8 9
// 你應該要輸出 1 2 3 6 9 8 7 4 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int n;
void PrintArray_ver1(int arr[][n], int m){ //正常印 版本1

    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}
void PrintArray_ver2(int** arr, int m, int n){ //正常印 版本2

    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}
void PrintArray_ver3(int** arr, int m, int n){ //螺旋印出

    int boundary_top = 0;
    int boundary_down = m - 1;
    int boundary_left = 0;
    int boundary_right = n - 1;
    int direction = 1;
    int boundary;
    int i = 0;
    int j = 0;
    int cnt = 0;
    while(1){
        if(cnt == m * n)
            break;
        switch(direction){
            case 1: 
                boundary = boundary_right;
                boundary_top ++;
                direction ++;
                for(j = boundary_left; j <= boundary_right; j ++){
                    printf("%d ", arr[i][j]);
                    cnt ++;
                }
                j --;
                break;
            case 2:
                boundary = boundary_down;
                boundary_right --;
                direction ++;
                for(i = boundary_top; i <= boundary_down; i ++){
                    printf("%d ", arr[i][j]);
                    cnt ++;
                }
                i --;
                break;
            case 3:
                boundary = boundary_left;
                boundary_down --;
                direction ++;
                for(j = boundary_right; j >= boundary_left; j --){
                    printf("%d ", arr[i][j]);
                    cnt ++;
                }
                j ++;
                break;
            case 4:
                boundary = boundary_top;
                boundary_left ++;
                direction = 1;
                for(i = boundary_down; i >= boundary_top; i --){
                    printf("%d ", arr[i][j]);
                    cnt ++;
                }
                i ++;
                break;
        }
    }
    printf("\n");

}

int main(void){

    srand(time(0));
    int m;
    printf("m & n = ");
    scanf("%d%d", &m, &n);
    int arr1[m][n];
    int* arr2[m];
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            arr1[i][j] = rand() % 10;
        }
    }
    for(int i = 0; i < m; i ++){
        arr2[i] = arr1[i];
    }
    //PrintArray_ver1(arr1, m);
    PrintArray_ver2(arr2, m, n);
    PrintArray_ver3(arr2, m, n);
    return 0;

}