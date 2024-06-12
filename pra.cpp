#include <stdio.h>
#define NUM 30

void mybubble(int *pArr, int num) {
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

int myfind(int *pArr, int key, int num) {
    int low = 0;
    int high = num - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (key == pArr[mid]) {
            return mid;
        } else if (key > pArr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int myinsert(int *pArr, int key, int *num) {
    int i;
    // 检查key是否已存在
    for(i = 0; i < *num; i++) {
        if(pArr[i] == key) {
            return -1; // 插入失败，因为元素已存在
        }
    }
    // 找到插入点
    for(i = *num - 1; i >= 0; i--) {
        if(pArr[i] < key) {
            // 移动元素，为新元素腾出空间
            for(int j = *num; j > i; j--) {
                pArr[j] = pArr[j - 1];
            }
            pArr[i] = key; // 插入新元素
            (*num)++; // 更新数组元素数量
            return i; // 返回插入位置的下标
        }
    }
    // 如果数组为空或者key是最小的元素
    pArr[0] = key;
    (*num)++;
    return 0;
}

int mydelete(int *pArr, int key, int *num) {
    int i, j, flag = 0;
    for(i = 0; i < *num; i++) {
        if(pArr[i] == key) {
            j = i;
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        return -1; // 删除失败，因为元素不存在
    }
    // 移动元素，填补空出的位置
    for(j = i; j < *num - 1; j++) {
        pArr[j] = pArr[j + 1];
    }
    (*num)--; // 更新数组元素数量
    return j; // 返回被删除元素的下标
}

void printarray(int *pArr, int num) {
    int i;
    for(i = 0; i < num; i++) {
        printf("\t%d", pArr[i]);
    }
    printf("\n");
}

int main() {
    int MA[NUM] = {34, 76, 23, 67, 345, 234, 21, 78, 172, 90};
    int nums = 10; // 数组元素个数
    int mkey, nkey, k;
    mybubble(MA, nums);
    scanf("%d%d", &mkey, &nkey); // 输入2个整数

    k = myinsert(MA, mkey, &nums);
    if(k < 0)
        printf("insert ERROR\n");
    else
        printf("insert SUCCESS\t%d\n", k);

    k = mydelete(MA, nkey, &nums);
    if(k < 0)
        printf("delete ERROR\n");
    else
        printf("delete SUCCESS\t%d\n", k);
        
    printarray(MA, nums);
    return 0;
}