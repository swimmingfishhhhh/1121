#include <stdio.h>

// 遞迴函式：找到陣列中的最大值
int recursiveMaximum(int arr[], int size) {
    if (size == 1) { // 當陣列只剩一個元素時，直接返回該元素
        return arr[0];
    }
    // 找出剩餘部分的最大值
    int max_in_rest = recursiveMaximum(arr, size - 1);
    // 返回當前值與剩餘部分最大值中的較大者
    return (arr[size - 1] > max_in_rest) ? arr[size - 1] : max_in_rest;
}

int main() {
    int arr[] = {1, 23, 45, 12, 67, 34, 89, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("陣列中的元素: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int max_value = recursiveMaximum(arr, size); // 呼叫遞迴函式
    printf("最大值: %d\n", max_value);

    return 0;
}

