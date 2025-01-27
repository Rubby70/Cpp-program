// 給你一個矩陣A，矩陣的尺寸是m x n輸出每一列跟每一行的矩陣元素的和先印出列，再印出行
//     Ex:2 3
// 		1 2 3
// 		4 5 6  
// 妳要輸出 6, 15, 5, 7, 9
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int n;

void PrintArray(int** arr, int m, int n){

    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}
void PrintSum(int** arr, int m, int n){

    int sum = 0;
    for(int i = 0; i < m; i ++){
        sum = 0;
        for(int j = 0; j < n; j ++){
            sum += arr[i][j];
        }
        printf("%d ", sum);
    }
    printf(", ");
    for(int j = 0; j < n; j ++){
        sum = 0;
        for(int i = 0; i < m; i ++){
            sum += arr[i][j];
        }
        printf("%d ", sum);
    }

}
void PrintSum2(int arr[][n], int m){

    int sum = 0;
    for(int i = 0; i < m; i ++){
        sum = 0;
        for(int j = 0; j < n; j ++){
            sum += arr[i][j];
        }
        printf("%d ", sum);
    }
    printf(", ");
    for(int j = 0; j < n; j ++){
        sum = 0;
        for(int i = 0; i < m; i ++){
            sum += arr[i][j];
        }
        printf("%d ", sum);
    }

}

int main(void){

    srand(time(0));
    int m;
    printf("m & n = ");
    scanf("%d%d", &m, &n);
    int arr1[m][n];
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            arr1[i][j] = rand() % 10;
        }
    }
    int* arr2[m];
    for(int i = 0; i < m; i ++){
        arr2[i] = (arr1[i]);
    }
    PrintArray(arr2, m, n);

    printf("sum: ");
    //PrintSum(arr2, m, n);
    PrintSum2(arr1, m);
    return 0;

}