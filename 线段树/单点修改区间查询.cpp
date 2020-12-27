/*************************************************************************
	> File Name: oj222_lkj.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sat 26 Dec 2020 09:20:28 PM CST
 ************************************************************************/
#include<inttypes.h>
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
    int max_val;
}tree[MAX_N << 2];

int arr[MAX_N + 5];


void update(int ind) {
    tree[ind].max_val = max(tree[ind << 1].max_val, tree[ind << 1 | 1].max_val);
}

void build_tree(int ind, int l, int r) {
    if (l == r) {
        tree[ind].max_val = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(ind << 1, l, mid);
    build_tree(ind << 1 | 1, mid + 1, r);
    update(ind);
    return; 
}

void modtify(int ind, int l, int r, int b, int val) {
    if (l == r) {
        tree[ind].max_val = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= b) {
        modtify(ind << 1, l, mid, b, val);
    }else {
        modtify(ind << 1 | 1, mid + 1, r, b, val);
    }
    update(ind);
    return;
}

int query(int ind, int l, int r, int x, int y) {
    if (l >= x && r <= y) {
        return tree[ind].max_val;
    }
    int ans = INT32_MIN;
    int mid = (l + r) >> 1;
    if (mid >= x) {
        ans = max(ans, query(ind << 1, l, mid, x, y));
    }
    if (mid < y) {
        ans = max(ans, query(ind << 1 | 1, mid + 1, r, x, y));
    }

    return ans;
}

int main () {
    int n, m;
    scanf("%d %d",&n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",arr + i);
    }
    build_tree(1, 1, n);
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        switch(a) {
            case 1:{
                modtify(1, 1, n, b, c);
            }break;
            case 2:{
                if (b > c) {
                    printf("-2147483648\n");
                    break;
                }
                printf("%d\n",query(1, 1, n, b, c));
            };break;
        }
    }

    return 0;
}
