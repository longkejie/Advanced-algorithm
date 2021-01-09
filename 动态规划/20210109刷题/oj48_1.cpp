/*************************************************************************
	> File Name: oj48_1.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sat 09 Jan 2021 03:50:38 PM CST
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

int dp[10005];

int main () {
    int V, n, v, w;
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> v >> w;
        for (int j = v; j <= V; ++j) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }

    cout << dp[V] << endl;
    return 0;
}
