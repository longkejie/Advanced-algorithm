/*************************************************************************
	> File Name: oj332.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Fri 22 Jan 2021 04:33:11 PM CST
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
int n;
int c[MAX_N + 5];
int a[MAX_N + 5], b[MAX_N + 5];
int ind[MAX_N + 5];
void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int binary_search(int n, int x) {
    int l = 1, r = n, mid;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (query(mid) < x) {
            l = mid + 1;
        }else {
            r = mid;
        }
    }
    return l;
}

void read() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        add(i,1,n);
        cin >> a[i] >> b[i];
    }
    for (int i = n; i >= 1; --i) {
        int temp = binary_search(n,a[i] + 1);
        add(temp, -1, n);
        ind[temp] = b[i];
    }
    return;
}

void output() {
    for (int i = 1; i <= n; ++i) {
        if (i - 1) cout << " ";
        cout << ind[i];
    }
    cout << endl;
}

int main () {
    read();
    output();

    return 0;
}
