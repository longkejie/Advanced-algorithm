/*************************************************************************
	> File Name: oj328_树状数组.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Fri 22 Jan 2021 05:15:53 PM CST
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
#define MAX_N 200000
#define lowbit(x) ((x) & (-x))
long long val[MAX_N + 5];
long long c[MAX_N + 5];
long long n;
long long ans1, ans2;

void add(long long i, long long x, long long n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}


long long query(long long i) {
    long long sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}
void solve() {
    
    for (long long i = 1; i <= n; ++i) {
        long long sum1 = query(val[i]);
        add(val[i], 1, n);
        int sum2 = val[i] - 1 - sum1;
        if (sum2 < 0) sum2 = 0;
        ans2 += sum1 * sum2;
        sum1 = i - 1 - sum1;
        if (sum1 < 0) sum1 = 0;
        sum2 = n - val[i] - sum1;
        if (sum2 < 0) sum2 = 0;
        ans1 += sum1 * sum2;
    }
    cout << ans1 << " " << ans2 << endl;
}

void read() {
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
        cin >> val[i];
    }

    
}

int main () {
    
    read();
    solve();

    return 0;
}
