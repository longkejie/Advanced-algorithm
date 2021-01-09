/*************************************************************************
	> File Name: oj46_1.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sat 09 Jan 2021 02:31:44 PM CST
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
#define MAX_N 500005
int dp[MAX_N];

bool is_palindrome(string &s, int i, int j ) {
    while (i < j) {
        if (s[i++] - s[j--]) return false;
    }
    return true;
}

int main () {
    string s;
    cin >> s;
    dp[0] = 0;

    for (int i = 1; i <= s.size(); ++i) {
        dp[i] = dp[i - 1] + 1;
        
        for (int j = 0; j < i; ++j) {
            if (is_palindrome(s, j, i - 1)) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[s.size()]  - 1<< endl;
    return 0;
}
