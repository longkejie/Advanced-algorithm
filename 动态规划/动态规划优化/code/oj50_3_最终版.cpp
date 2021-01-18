/*************************************************************************
	> File Name: oj50_3_最终版.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Mon 18 Jan 2021 08:58:33 PM CST
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

#define MAX_N 100
#define MAX_K 50000

long long dp[3][MAX_K + 5];

int solve(int n, int m) {
    if (n == 1) return m;
    for (int i = 1; i <= MAX_K; ++i) dp[1][i] = i;
    for (int i = 2; i <= n; ++i) {
        for (int k = 1; k <= MAX_K; ++k) {
            dp[i % 2][k] = dp[(i - 1) % 2 ][k - 1 ] + dp[i % 2 ][k - 1] + 1;
        }
    }
    int k = 1;
    while (dp[n % 2][k] < m) k++;
    
    return k;
}

int main () {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;

    

    return 0;
}
