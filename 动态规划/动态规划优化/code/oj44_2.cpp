/*************************************************************************
	> File Name: oj44_2.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Mon 18 Jan 2021 10:11:57 PM CST
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

int len[MAX_N + 5];
int dp[MAX_N + 5];
int val[MAX_N + 5];

int binary_search(int *arr, int n, int x) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (arr[mid] >= x) {
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return l;
}

int main () {
    int n, ans = 0, a;
    memset(len , 0x3f, sizeof(len));
    len[0] = 0; 
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        dp[i] = binary_search(len, ans + 1, a);
        len[dp[i]] = a;
        ans = max(dp[i], ans);
    }

    
    cout << ans << endl;
    return 0;
}
