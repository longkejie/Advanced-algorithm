/*************************************************************************
	> File Name: 604.cpp
	> Author: xiaox
	> Mail: buaa_xiaox@live.com
	> Created Time: Mon 28 Dec 2020 09:52:18 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include "./common/segmentTree.h"
using namespace std;

struct Data
{
    long long tag;
    long long sum;
    static int x, y;
    static long long val;
};
int Data::x, Data::y;
long long Data::val;

#define push(ch) ch->data.sum += data.tag * ch->len;  ch->data.tag += data.tag
template<> void SgTreeNode<Data>::down()    
{ 
    push(lch);  push(rch);  
    data.tag = 0;
}
template<> void SgTreeNode<Data>::update()  
{ 
    data.tag = 0; 
    data.sum = lch->data.sum + rch->data.sum;
}
template<> void SgTreeNode<Data>::cover()   
{ 
    data.tag += data.val; data.sum += data.val * len;
}
template<> auto SgTreeNode<Data>::query()
{
    if (data.x <= l && r <= data.y) return data.sum;
    down();
    long long ans = 0;
    if (lch->r >= data.x) ans += lch->query();
    if (rch->l <= data.y) ans += rch->query();
    return ans;
}

int main()
{
    int n, m, a, b, c, d;
    scanf("%d%d", &n, &m);
    vector<Data> init_data(n+1);
    for (int i = 1; i <= n; i++){
        int tmp;
        scanf("%d", &tmp);
        init_data[i].tag = 0;
        init_data[i].sum = tmp;
    }
    SegmentTree<Data> tree;
    tree.buildtree(init_data);
    Data OP;
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &a, &b, &c);
        switch (a){
            case 1:{
                scanf("%d", &d);
                OP.val = d;
                tree.modify(b, c);
            }break;
            case 2:{
                printf("%lld\n", tree.getval(b, c));
            }break;
        }
    }
    return 0;
}

