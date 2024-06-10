#include <cstdio>

#define NUM 30

void mybubble(int* pArr, int num) {
    int i, j, t;
    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (pArr[j] > pArr[j + 1]) {
                t = pArr[j + 1];
                pArr[j + 1] = pArr[j];
                pArr[j] = t;
            }
        }
    }
}

int myfind(int* pArr, int key, int num) {
    int low = 0;
    int high = num - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (key == pArr[mid]) {
            return mid; // 返回下标
        } else if (key > pArr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // 查找失败
}

int main() {
    int MA[NUM] = { 34, 76, 23, 67, 345, 234, 21, 78, 172, 90 };
    int nums = 10; // 数组元素个数
    int mkey;
    int k;
    mybubble(MA, nums);

    scanf("%d", &mkey); // 输入一个整数
    k = myfind(MA, mkey, nums);
    if (k < 0) {
        printf("ERROR\n");
    } else {
        printf("SUCCESS\t%d\n", k); // 打印下标
    }
    return 0;
}