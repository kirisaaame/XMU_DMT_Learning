#include <bits/stdc++.h>

using namespace std;

// m = apple; n = plate;
int apple(int m, int n)
{
	if (m < 0 ) {
		return 0;
	}
	if(m==0) return 1;
    if (n==0)
    {
        if (m==0) return 1;
        else return 0;
    }
    if (m == 1 || n == 1) {
		return 1;
	}
	return apple(m, n-1) + apple(m-n, n);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
	int m = 0, n = 0;
	
	scanf("%d", &m);
	scanf("%d", &n);
	
	printf("%d\n", apple(m, n));
	
    }
    return 0;
}

