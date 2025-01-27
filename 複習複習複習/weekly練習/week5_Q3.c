// 矩陣乘法 
// 給你矩陣A, B A的尺寸是m x n, B的尺寸是 n x p. 回傳矩陣A,B的相乘結果  並以 m x p的形式印出
// Ex:  2 3
// 	1 2 3
// 	4 5 6
// 你應該要輸出 58 64
	
// Ex:	3 2
// 	7 8
// 	9 10
// 	11 12
// 你應該要輸出 139 154
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* CreatMatrix1(int c, int r){

    int length = c * r;
    int* temp = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        temp[i] = rand() % 10;
    }
    return temp;

}
void PrintArray1(int* arr, int c, int r){

    int length = c * r;
    int cnt = 0;
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
        cnt ++;
        if(cnt == r){
            cnt = 0;
            printf("\n");
        }
    }

}
int** CreatMatrix2(int c, int r){

    int** arr = (int**)malloc(sizeof(int*) * c);
    for(int i = 0; i < c; i ++){
        arr[i] = (int*)malloc(sizeof(int) * r);
    }
    for(int i = 0; i < c; i ++){
        for(int j = 0; j < r; j ++){
            arr[i][j] = rand() % 5;
        }
    }
    return arr;

}
void PrintArray2(int** arr, int c, int r){

    for(int i = 0; i < c; i ++){
        for(int j = 0; j < r; j ++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}
void Matrix_Multiply(int** arr1, int** arr2, int** arr3, int m, int n, int p){

    //printf("Matrix1 * Matrix2 = \n");
    int r1 = 0;
    int r2 = 0;
    int r3 = 0;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int temp = 0;
    int sum = 0;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < p; j ++){
            for(int k = 0; k < n; k ++){
                temp = arr1[r1][c1] * arr2[r2][c2];
                sum += temp;
                printf("arr1[%d][%d] * arr2[%d][%d] ", r1, c1, r2, c2);
                printf("= %d * %d = %d\n", arr1[r1][c1], arr2[r2][c2], temp);
                c1 ++;
                r2 ++;
            }
            printf("\n");
            arr3[r3][c3] = sum;
            sum = 0;
            c1 = 0;
            r2 = 0;
            c3 ++;
            c2 ++;
        }
        c2 = 0;
        c3 = 0;
        r3 ++;
        r1 ++;
    }

}

int main(void){

    srand(time(0));
    int m, n, p;
    printf("m & n & p = ");
    scanf("%d%d%d", &m, &n, &p);
    // int* arr1 = CreatMatrix1(m, n); //方法1 (malloc 1-D array, 印成2-D array)
    // printf("Array1:\n");
    // PrintArray1(arr1, m, n);
    int** arr1 = CreatMatrix2(m, n); //方法2 (malloc 2-D array)
    printf("Matrix1:\n");
    PrintArray2(arr1, m, n);
    int** arr2 = CreatMatrix2(n, p);
    printf("Matrix2:\n");
    PrintArray2(arr2, n, p);

    int** arr3 = CreatMatrix2(m, p);
    Matrix_Multiply(arr1, arr2, arr3, m, n, p);
    printf("Answer:\n");
    PrintArray2(arr3, m, p);
    return 0;

}