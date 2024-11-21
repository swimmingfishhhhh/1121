#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 36000
#define SIDES 6

int main(void)
{
    srand(time(NULL));

    int frequencies[11] = {0};

    // 模擬骰子擲骰
    for (int i = 0; i < ROLLS; i++) {
        int die1 = rand() % SIDES + 1;  // 骰子1
        int die2 = rand() % SIDES + 1;  // 骰子2
        int sum = die1 + die2;         // 骰子點數和
        frequencies[sum - 2]++;        // 更新次數
    }

    // 輸出表頭
    printf("Point\tFrequency\tReasonable?\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < 11; i++) {
        int point = i + 2;

        // 計算理論期望次數
        int expected_count = (point <= 7 ? (point - 1) : (13 - point)) * ROLLS / 36;

        // 判斷是否合理
        int reasonable = abs(frequencies[i] - expected_count) <= expected_count * 0.1;

        // 輸出結果
        printf("%2d\t%8d\t%s\n", point, frequencies[i], reasonable ? "Yes" : "No");
    }

    return 0;
}

