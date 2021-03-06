/*************************************************************************
	> File Name: oj329_树状数组.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Thu 21 Jan 2021 03:07:11 PM CST
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
#define MAX_N 100000
int c[MAX_N + 5];
#define lowbit(x) ((x) & (-x))

void add (int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
}

int query(int i ) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main () {
    
    int m, n, pre = 0, a;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        add(i, a - pre, n);
        pre = a;
    }
    cin >> m;
    char s;
    int l, r, x;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        switch(s) {
            case 'C':{
                cin >> l >> r >> x;
                add(l, x, n);
                add(r + 1, -x, n);
            }break;
            case 'Q':{
                cin >> x;
                cout << query(x) << endl;
            }break;

        }
    }
    return 0;
}
