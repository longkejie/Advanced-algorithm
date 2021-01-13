/*************************************************************************
	> File Name: 604.cpp
	> Author: xiaox
	> Mail: buaa_xiaox@live.com
	> Created Time: Mon 28 Dec 2020 09:52:18 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include "./common/segmentTree.h"
using namespace std;

struct Data
{
    int tag; // 0, 1, 2
    int sum;
    static int x, y, ord, val;
};
int Data::x, Data::y, Data::ord, Data::val;

template<> void SgTreeNode<Data>::down()
{
    if (data.tag == 0) return;
    lch->data.tag = rch->data.tag = data.tag;
    if (data.tag == 1) {
        lch->data.sum == max(0, data.sum - rch->len);
        rch->data.sum == min(data.sum, rch->len);
    }else{
        lch->data.sum == min(data.sum, lch->len);
        rch->data.sum == max(0, data.sum - lch->len);
    }
    data.tag = 0;
}
template<> void SgTreeNode<Data>::update()
{
    data.sum = lch->data.sum + rch->data.sum;
    data.tag = 0;
}
template<> void SgTreeNode<Data>::cover()
{
    data.tag = data.ord;
    if (data.ord == 1) data.sum = data.val - (data.y - r);
    if (data.ord == 2) data.sum = data.val - (l - data.x);
    if (data.sum < 0) data.sum = 0;
    if (data.sum > len) data.sum = len;
}
template<> auto SgTreeNode<Data>::query() 
{
    if (data.x <= l && r <= data.y) return data.sum;
    down();
    int ans = 0;
    if (lch->r >= data.x) ans += lch->query();
    if (rch->l <= data.y) ans += rch->query();
    return ans;
}

int main()
{
    char *s = (char *)malloc(1000005);
    scanf("%s\n", s);
    int n = strlen(s);
    vector<Data> init_data(n+1);
    for (int i = 1; i <= n; i++){
        init_data[i].sum = s[i-1] == '0' ? 0:1;
        init_data[i].tag = 1;
    }
    SegmentTree<Data> tree;
    tree.buildtree(init_data);
    int m, a, b, c;
    Data OP;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &a, &b, &c);
        OP.val = tree.getval(b, c);
        OP.ord = a;
        tree.modify(b, c);
    }
    for (int i = 1; i <= n; i++){
        printf("%d",tree.getval(i));
    }
    free(s);
    return 0;
}
