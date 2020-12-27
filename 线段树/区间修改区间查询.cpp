/*************************************************************************
	> File Name: oj223_lkj.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sun 27 Dec 2020 12:24:10 PM CST
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

#define MAX_N 10000

struct {
    long long  sum, tag;

}tree[MAX_N << 2];

long long arr[MAX_N + 5];

void update(long long ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
}

void down(long long ind, long long l, long long r) {
    long long mid = (l + r) >> 1;
    long long temp = tree[ind].tag;
    tree[ind << 1].tag += temp;
    tree[ind << 1].sum += temp * (mid - l + 1);
    tree[ind << 1 | 1].sum += temp *(r - mid);
    tree[ind << 1 | 1].tag += temp;
    tree[ind].tag = 0;
    return;
}

void build_tree(long long ind, long long l, long long r) {
    if (l == r) {
        tree[ind].sum = arr[l];
        return;
    }
    long long mid = (l + r) >> 1;
    build_tree(ind << 1, l, mid);
    build_tree(ind << 1 | 1, mid + 1, r);
    update(ind);
    return;
}


void modify(long long ind, long long l, long long r, long long x, long long y, long long d) {
    if (l >= x && r <= y) {
        tree[ind].tag += d;
        tree[ind].sum += d * (r - l + 1);
        return;
    }
    down(ind, l, r);
    long long mid = (l + r) >> 1;
    if (mid >= x) {
        modify(ind << 1, l, mid, x, y, d);
    }
    if (mid < y) {
        modify(ind << 1 | 1, mid + 1, r, x, y, d);
    }
    update(ind);
    return;
}

long long query(long long ind, long long l, long long r, long long x, long long y) {
    if (l >= x && r <= y ) {
        return tree[ind].sum;
    }
    down(ind, l , r);
    long long mid = (l + r) >> 1;
    long long ans = 0;
    if (mid >= x) {
        ans += query(ind << 1, l , mid, x, y);
    }
    if (mid < y) {
        ans += query(ind << 1 | 1, mid + 1, r, x, y);
    }
    update(ind);
    return ans;
}

int main () {
    long long n, m;
    scanf("%lld %lld",&n, &m);
    for (long long i = 1; i <= n; ++i) {
        scanf("%lld", arr + i);
    }
    build_tree(1, 1, n);
    long long a, b, c, d;
    for (long long i = 0; i < m; ++i) {
        scanf("%lld %lld %lld",&a, &b, &c);
        switch(a) {
            case 1:{
                scanf("%lld",&d);
                modify(1, 1, n, b, c, d);
            }break;
            case 2:{
                if (b > c) {
                    printf("0\n");
                    break;
                }
                printf("%lld\n",query(1, 1, n, b, c));
            }break;
        }
    }
    return 0;
}
