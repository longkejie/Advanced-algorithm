/*************************************************************************
	> File Name: oj49_1.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sat 09 Jan 2021 04:06:10 PM CST
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
int dp[100005];


int main () {
    int V, n, v, w, s;
    cin >> V >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> v >> w >> s;
        for (int k = 0; k < s; ++k) {
            for (int j = V; j >= v; --j) {
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }

    cout << dp[V] << endl;
}
