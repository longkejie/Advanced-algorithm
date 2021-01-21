/*************************************************************************
	> File Name: oj330_两个树状数组.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Thu 21 Jan 2021 04:02:07 PM CST
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

long long c[2][MAX_N +5];

#define lowbit(x) ((x) & (-x))

void add(long long k, long  long i, long long x, int n) {
    while (i <= n) {
        c[k][i] += x;
        i += lowbit(i);
    }
    return ;
}

long long query(long long k, long long i) {
    long long sum = 0 ;
    while (i) {
        sum += c[k][i];
        i -= lowbit(i);
    }
    return sum;
}
long long S(long long i) {
    return (i + 1) * query(0, i) - query(1, i);
}

void modify(long long i, long long x, int n) {
    add(0, i, x, n);
    add(1, i, i * x, n);
    return ;
}

int main () {
    
    int n, m;
    long long a;
    scanf("%d %d",&n,&m);
    long long pre = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld",&a);
        modify(i, a - pre, n);
        pre = a;
    }
    char c[10];
    for (int i = 0; i < m; ++i) {
        scanf("%s",c);
        long long l, r, d;
        switch(c[0]) {
            case 'C':{
                scanf("%lld%lld%lld",&l,&r,&d);
                modify(l, d, n);
                modify(r + 1, -d, n);
            }break;
            case 'Q':{
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",( S(r) - S(l - 1) ));
            }break;
        }
    }

    return 0;
}
