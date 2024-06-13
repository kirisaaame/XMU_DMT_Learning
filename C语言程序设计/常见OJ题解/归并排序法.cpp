/*merge sort-- by dividing into smaller arrays and sorting,then combining them.*/
#include <stdlib.h>
#include <stdio.h>
int min(int x, int y) {
    return x < y ? x : y;
}
void merge_sort(int *arr, int len) {
    int* a = arr;
    int* b = (int*) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}
int main()
{
    int n;
    int num[100001];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&num[i]);
    merge_sort(num,n);
    for (int i=0;i<n-1;i++)
    printf("%d ",num[i]);
    printf("%d",num[n-1]);
}