/*************************************************************************
	> File Name: oj52_单调队列斜率优化_动态规划.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Wed 20 Jan 2021 02:11:21 PM CST
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
#define MAX_N 1000000
#define S(A) ((A) * (A))
long long dp[MAX_N + 5];
long long n, M, s[MAX_N + 5];
long long f[MAX_N + 5];
long long q[MAX_N + 5], head, tail;



double slope(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (s[i] - s[j]);
    
}

void read() {
    cin >> n >> M;
    for (long long i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = s[i - 1] + s[i];
    }
    return ;
}

void set_dp(int i, int j ) {
    dp[i] = dp[j] + S(s[i] - s[j]) + M;
    f[i] = dp[i] + S(s[i]);
    return ;
}

long long solve() {
    head = tail = 0;
    q[tail++] = 0;

    for (long long i = 1; i <= n; ++i) {
        while (tail - head >= 2 && slope(q[head + 1], q[head]) < 2 * s[i]) head++;
        set_dp(i, q[head]);
        while (tail - head >= 2 && slope(i, q[tail - 1]) < slope(q[tail - 2], q[tail - 1])) --tail;
        q[tail++] = i;
    }

    return dp[n];
}


int main () {
    read();
    cout << solve() << endl;
    return 0;
}
