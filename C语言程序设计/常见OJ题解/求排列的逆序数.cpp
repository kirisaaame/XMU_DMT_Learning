#include <bits/stdc++.h>
using namespace std;
//思路：先算左右两边的逆序数，再算中间的逆序数
const int N = 100007;
int n;
int numbers[N], tmp[N];
long long mergeSort(int nums[], int left, int right)
{
    if (left >=right)return 0;

    int mid = left+right >>1;
    long long result = mergeSort(nums,left,mid)+mergeSort(nums,mid+1,right);
    int k=0,p=left,q = mid+1;
    while(p<=mid && q<=right)
        if (nums[p]<=nums[q])
            tmp[k++] = nums[p++];
        else
        {
            result +=mid-p+1;
            tmp[k++]=nums[q++];
        }
    while(p<=mid)
        tmp[k++] = nums[p++];
    while(q<=right)
        tmp[k++] = nums[q++];
    for (int i=left,k=0;i<=right;i++,k++)
        nums[i] = tmp[k];
    return result; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++) 
        cin >> numbers[i];
    cout << mergeSort(numbers,0,n-1) << endl; 
}