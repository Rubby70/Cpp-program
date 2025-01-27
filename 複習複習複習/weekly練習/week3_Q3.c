// 猜數字遊戲 首先要先輸入 猜數字的範圍  (0~輸入的數字N)
// 接著就開始猜數字   每次使用者輸入數字之後  
// 如果猜對了就結束程式 並印出猜對了!
// 猜錯了的話 如果猜錯的字數還不到5次 就要更新猜數字的範圍  
// 如果已經5次了  那就要說 很可惜  小笨蛋你沒機會囉   然後結束程式
// Ex: 輸入 100 表示從0~100 隨機生成一個目標數字
// 假設生成了68
// 使用者輸入50 --> 猜錯囉 再試試看吧 數字範圍50~100
// 使用者輸入51 --> 猜錯囉 再試試看吧 數字範圍51~100
// 使用者輸入71 --> 猜錯囉 再試試看吧 數字範圍51~71
// 使用者輸入61 --> 猜錯囉 再試試看吧 數字範圍61~71
// 使用者輸入62 --> 又猜錯了 很可惜 小笨蛋你沒機會囉
// 使用者輸入68 -->  賓果!  不愧是我的小可愛呢 答對囉!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){

    srand(time(0));
    printf("請先指定範圍: 0 ~ ");
    int min = 0;
    int max;
    scanf("%d", &max);
    int guess;
    int target = rand() % (max + 1);
    int cnt = 1;
    printf("洩題,答案是 %d\n", target);
    do{
        printf("猜猜答案是多少: ");
        scanf("%d", &guess);
        cnt ++;
        if(guess == target){
            printf("bingo\n");
            break;
        }
        if((guess > target) && (max > guess)){
            max = guess;
        }
        else if((guess < target) && (min < guess)){
            min = guess;
        }
        if(cnt > 5){
            printf("很可惜 小笨蛋你沒機會囉");
            break;
        }
        printf("猜錯了,數字範圍: %d ~ %d\n", min, max);
    }while(guess != target);
    return 0;

}