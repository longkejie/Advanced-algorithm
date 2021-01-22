/*************************************************************************
	> File Name: oj333_线段树区间最大子段和.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Fri 22 Jan 2021 06:04:14 PM CST
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
#define MAX_N 500000
#define L(ind) (ind << 1)
#define R(ind) (ind << 1 | 1)
#define SUM(ind) tree[ind].sum
#define INMAX(ind) tree[ind].inmax
#define LMAX(ind) tree[ind].lmax
#define RMAX(ind) tree[ind].rmax

struct Data{
    int sum, inmax, lmax, rmax;
    int cl, cr, cnt; //c1左边的连续最大子段和包含的元素个数，cr右边的连续最大子段和个数,cnt是节点区间长度。
}_tree[MAX_N << 2];

Data *tree = _tree + 1;
int n, m;
int val[MAX_N + 5];
int flag;

void update(int a, int b, int c) {
    SUM(a) = SUM(b) + SUM(c);
    LMAX(a) = max(LMAX(b), SUM(b) + LMAX(c));
    RMAX(a) = max(RMAX(c), SUM(c) + RMAX(b));
    INMAX(a) = max(max(INMAX(b), INMAX(c)),RMAX(b) + LMAX(c));
    return;
} 

void build(int ind, int l, int r) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ind << 1, l , mid);
    build(ind << 1 | 1, mid + 1, r);
    update(ind, ind << 1, ind << 1 | 1);
    return ;
}

void modify(int ind, int l, int r, int x, int y) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = y;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= x) {
        modify(ind << 1, l, mid, x, y);
    }else {
        modify(ind << 1 | 1, mid + 1, r, x, y);
    }
    update(ind, ind << 1, ind << 1 | 1);
}

void query(int ind, int l, int r, int x, int y) {
    if (x <= l && y >= r) {
        if (flag) {
            tree[0] = tree[ind];
            flag = 0;
        }else {
            update(-1, 0, ind);
            tree[0] = tree[-1];
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        query(ind << 1, l, mid, x, y);
    }
    if (y > mid) {
        query(ind << 1 | 1, mid + 1, r, x, y);
    }
    return ;
}

void solve() {
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n ; ++i) {
        scanf("%d",&val[i]);
    }
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        int k, x, y;
        scanf("%d%d%d",&k,&x,&y);
        switch(k) {
            case 1:{
                if (x > y) swap(x,y);
                flag = 1;
                query(1, 1, n, x, y);
                printf("%d\n",INMAX(0));
            }break;
            case 2:{
                modify(1, 1, n, x, y);
            }break;
        }
    }
}




int main () {
    solve();
    return 0;
}
