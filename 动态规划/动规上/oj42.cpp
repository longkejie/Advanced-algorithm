/*************************************************************************
	> File Name: oj42.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Mon 28 Dec 2020 02:41:25 PM CST
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

int num[25];

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(25,vector<int>(10005));
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for (int i = 0; i <= m; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= m; ++j) {
            if (j >= num[i]) {
                dp[i][j] += dp[i][j - num[i]];
            }
            if (i > 0) dp[i][j] += dp[i - 1][j];
            dp[i][j] %= 9973;
        }
    }


    cout << dp[n - 1][m] << endl;
    return 0;
}
