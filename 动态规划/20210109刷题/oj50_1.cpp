/*************************************************************************
	> File Name: oj50_1.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sat 09 Jan 2021 04:47:36 PM CST
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

#define MAX_N 32
#define MAX_M 1000000

int dp[MAX_N +5][MAX_M];

int main () {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) dp[1][i] = i;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = j;
            for (int k = 1; k <= j; ++k) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
