#include <stdio.h>

// 遞迴函式：反向列印字串
void stringReverse(const char *str) {
    if (*str == '\0') { // 遇到終止符號時停止
        return;
    }
    stringReverse(str + 1); // 遞迴到下一個字元
    putchar(*str);          // 列印當前字元
}

int main() {
    const char str[] = "Hello, World!";
    printf("原字串: %s\n", str);
    printf("反向列印: ");
    stringReverse(str); // 呼叫遞迴函式
    printf("\n");
    return 0;
}
