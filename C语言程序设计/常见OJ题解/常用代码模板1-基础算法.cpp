#include <bits/stdc++.h>

void quick_sort(int q[],int l,int r)
{
    if (l>=r) return ;
    int i = l-1,j=r+1,x = q[l+r>>1];//l+r右移一位，即除以2取整
    while (i<j)
    {
        do  i++; while (q[i]<x);
        do j--; while (q[j]>x);
        if(i<j) std::swap(q[i],q[j]);
    }
    quick_sort(q,l,j),quick_sort(q,j+1,r);
}
/*
void merge_sort(int q[], int l, int r)
{
    if(l>=r) return ;
    int mid = l+r >> 1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);

    int k=0,i=l,j=mid+1;
    while (i<=mid && j<=r)
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while (i<=mid) tmp[k++] = q[i++];
    while(j<=r) tmp[k++]= q[j++];

    for (i=l,j=0;i<=r;i++,j++)
    q[i] = tmp[j];
}
*/
bool check(int x)
{
    return x==1;
}
int bsearch_1(int l,int r)
{
    while (l<r)
    {
        int mid = l+r >> 1;
        if(check(mid))
            r = mid;
        else l =mid+1;
    }
    return l;
}

int bsearch_2(int l,int r)
{
    while(l<r)
    {
        int mid = l+r >>1 ;
        if(check(mid)) l =mid;
        else  r = mid-1;
        
    }
}

bool check(double x )
{}

double bsearch_3(double l,double r)
{
    const double eps = 1e-6;
    while (r-l > eps)
    {
        double mid = (l+r)/2;
        if(check(mid))
            r = mid;
        else l = mid;            
    }
    return 1;
}

//高精度加法
std::vector<int> add(std::vector<int> &A,std:: vector<int> &B)
{
    if (A.size() <B.size() )
    return add(B,A);
    std::vector<int> C;
    int t=0;
    for (int i=0;i<A.size();i++)
    {
        t+=A[i];
        if (i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
        //这样可以自动解决进位的问题
    }
    if(t) C.push_back(t);
    return C;
    //返回的是逆序的结果

}
//高精度减法
std::vector<int> sub(std::vector<int> &A,std:: vector<int> &B)
{
    std::vector<int> C;
    for (int i=0,t=0;i<A.size();i++)
    {
        t=A[i]-t;
        if(i<B.size())
            t-= B[i];
        C.push_back((t+10)%10);
        if (t<0) t=1;
        else t=0;
    }

    while (C.size()>1 && C.back()==0)
        C.pop_back();
    return C;
    //返回的是逆序的结果
}
//高精度乘法
std::vector<int> mul(std::vector<int> &A, int b)
{
    std::vector<int> C;

    int t=0;
    for (int i =0;i<A.size()||t;i++)
    {
        if(i<A.size())
            t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    while (C.size()>1 && C.back()==0 ) C.pop_back();
    return C;
    //得到的是逆序的结果
}
//高精度除法
std::vector<int> div(std:: vector<int> &A, int b, int &r)
{
    std:: vector<int> C;
    r=0;
    for (int i=A.size()-1;i>=0;i--)
    {
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while (C.size() >1 && C.back()==0) C.pop_back();
    return C;
}
//一维前缀和
//思路：在输入时求出前n项和，在计算时直接相减
int  totalSum()
{
     std::vector<int> num;
     std::vector<int> sum;
     int size=0,left,right,data;
     std::cin >> size;
     for (int i=0;i<size;i++)
     {
        std::cin >> data;
        num.push_back(data);
        if(i==0) sum.push_back(data);
        else sum.push_back(sum.at(i-1)+data);
     }
     std::cin >> left >>right;
    return sum.at(right)- sum.at(left);

}
/*
二维前缀和
思路：S[i,j]为第i行j格左上部分所有元素的和
那么从[x1,y1]到[x2,y2]的所有元素的和是:
S[x2,y2]-S[x1,y2]-S[x2,y1]+S[x1,y1]
(有点像二维变量的分布函数)
*/

int TwoDsum()
{
    int row,cor;
    std::cin >> row >> cor;
    int num[row][cor];
    int sum[row][cor];
    for (int i=0;i<row;i++)
        for (int j=0;j<cor;j++)
        {
            std::cin >> num[i][j];
            if(j==0)
            {
                if (i==0)
                    sum[i][j] = num[i][j];
                else 
                    sum[i][j] = num[i-1][cor-1]+num[i][j];
            }
            else 
                sum[i][j] = sum[i][j-1] + num[i][j];
        }
        int x1,y1,x2,y2;
        std:: cin >> x1 >> y1 >> x2>> y2;
        return sum[x2][y2]+sum[x1][y1]-sum[x1][y2]-sum[x2][y1];
}

//一维差分
/*
差分针对对连续区间的相同操作，这时候使用差分，记载第一个元素和后一个元素和前一个元素的
相对状态（类似数学归纳法）这样可以减少对原始数据的相关操作，最后
使用一维前缀和输出数组，时间复杂度为O(n)
*/
std::vector<int> Differencing(std::vector<int>&A, int l,int r, int c)
{

}


//模拟栈
class Stack10
{
    int stk[10],tt = 0;
    public:
    void insert(int x)
    {
        stk[tt++] = x;
    }
    int Pop_back()
    {
        return stk[--tt];
        stk[tt] = 0;
    }
    int Seek()
    {
        return stk[tt-1];
    }
    bool Is_empty()
    {
        if(tt>0)
            return true;
        else return false;
    }
};
//模拟队列
class queue
{
    int q[10], hh = 0, tt = 0;
    public:
    void Insert(int x)
    {
        q[tt++] = x;
    }
    int Pop_back()
    {
        return 
        
    }
};