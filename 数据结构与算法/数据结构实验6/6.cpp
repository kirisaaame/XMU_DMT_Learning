#include <bits/stdc++.h>
using namespace std;
//6-1 荷兰国旗问题
void dutchFlagSort(int arr[], int n) {
    int low = 0;  // 红色区域的右边界
    int mid = 0;  // 白色区域的右边界
    int high = n - 1;  // 蓝色区域的左边界

    while (mid <= high) {
        if (arr[mid] == 1) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 2) {
            mid++;
        } else if (arr[mid] == 3) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
//6-2 起泡排序算法
const int N = 20;  // 字符数组的最大容量
// 起泡排序函数
void bubbleSort(char name[][31], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(name[j], name[j + 1]) > 0) {
                swap(name[j], name[j + 1]);
            }
        }
    }
}
//6-3树形选择排序
const int MAX_SIZE = 100;  // 顺序表的最大容量
// 树形选择排序函数
void treeSelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // 记录最小元素的索引

        // 构建树形结构，选择最小元素的索引
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 将最小元素与当前位置交换
        swap(arr[i], arr[minIndex]);
    }
}

//主函数

int main() {
    //荷兰国旗问题
   int arr[] = {2, 3, 1, 1, 3, 2, 1, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    dutchFlagSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    //起泡排序
    char names[N][31] = {"John", "Alice", "Bob", "David", "Cindy"};
    bubbleSort(names, N);

    cout << "Sorted names: ";
    for (int i = 0; i < N; i++) {
        cout << names[i] << " ";
    }
    cout << endl;

    //树形选择排序
    int arr1[] = {9, 5, 2, 7, 1, 8, 3, 6, 4};
     n = sizeof(arr) / sizeof(arr[0]);

    treeSelectionSort(arr1, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
    return 0;
}

