/*************************************************************************
	> File Name: oj264_单调栈.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Tue 19 Jan 2021 04:32:24 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>
using namespace std;
#define MAX_N 100000

long long h[MAX_N + 5];
long long s[MAX_N + 5], top;
long long l[MAX_N + 5];
long long r[MAX_N + 5];

long long n;

long long solve() {
    top = -1;
    h[0] = h[n + 1] = -1;
    s[++top] = 0;
    for (long long i = 1; i <= n; ++i) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for (long long i = n; i >= 1; --i) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
        ans = max(ans,h[i] * (r[i] - l[i] - 1));
    }
    return ans;
}

int main () {
    scanf("%lld",&n);
    for (long long i = 1; i <= n; ++i) {
        scanf("%lld",h + i);
    }
    printf("%lld\n",solve());
    


    return 0;
}
