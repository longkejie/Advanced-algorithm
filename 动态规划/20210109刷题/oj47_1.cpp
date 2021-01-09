/*************************************************************************
	> File Name: oj47_1.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sat 09 Jan 2021 03:00:39 PM CST
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

int v[MAX_N + 5], w[MAX_N + 5];

int dp[2][10005];

int main () {
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= V; ++j) {
            dp[i%2][j] = dp[(i-1)%2][j];
            if (j >= v[i])dp[i%2][j] = max(dp[i%2][j], dp[(i - 1)%2][j - v[i]] + w[i]);
        }
    }
    
    cout << dp[n%2][V] << endl;


    return 0;
}
