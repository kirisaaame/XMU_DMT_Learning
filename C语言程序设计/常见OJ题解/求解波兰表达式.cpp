#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-6
//思路：n个数->n-1个数->...->2个数
bool check(double x)
{
    return abs(abs(x)-24)<=EPS;
}
bool get24(double arr[],int spacesize)
{
    if (spacesize==1)
        return check(arr[0]);//终止状态
    for (int i=0;i<spacesize-1;i++)
        for (int j=i+1;j<spacesize;j++)
        {
            double temp[spacesize-1];
            int itemp = 0;
            for (int k=0;k<spacesize;k++)
                if(k!=i&&k!=j) temp[itemp++]=arr[k];
            temp[itemp] = arr[i]+arr[j];
            return get24(temp,spacesize-1);
            temp[itemp] = arr[i]*arr[j];
            return get24(temp,spacesize-1);
            temp[itemp] = arr[i]-arr[j];
            return get24(temp,spacesize-1);
            temp[itemp] = arr[j]-arr[i];
            return get24(temp,spacesize-1);
            if(arr[j]!=0)
{            temp[itemp] = arr[i]/arr[j];
            return get24(temp,spacesize-1);
}            
            if(arr[i]!=0)
            {temp[itemp] = arr[j]/arr[i];
            return get24(temp,spacesize-1);}
        }
        return false;
}
int main()
{
    double arr[5];
    while(cin >> arr[0] >> arr[1] >>arr[2]>>arr[3]&& (check(arr[0]+24)&& check(arr[1]+24)&&check(arr[2]+24) &&check(arr[3]+24)))
       if (get24(arr,4))
        cout << "YES" <<endl;
        else cout << "NO" << endl;
}