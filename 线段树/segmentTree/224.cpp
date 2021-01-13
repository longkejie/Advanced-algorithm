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
#include "./common/segmentTree.h"
using namespace std;
struct Data
{
    long long tag_mult, tag_plus;
    void tag_init()         { tag_mult = 1;  tag_plus = 0;}
    long long sum;
    long long keyvalue()    { return sum;}
    static int x,y;
    static int ifmultiply; // 1:multiply; 0:plus;
    static long long val;
    static long long p;
};
int Data::x, Data::y, Data::ifmultiply;
long long Data::val, Data::p;

//step1: multiply;  step2: plus;  eg: new_sum = sum * tag_mult + tag_plus;
#define push(child) {\
    child->data.sum = (child->data.sum * data.tag_mult + data.tag_plus * child->len) % data.p;\
    child->data.tag_mult = (child->data.tag_mult * data.tag_mult) % data.p;\
    child->data.tag_plus = (child->data.tag_plus * data.tag_mult + data.tag_plus) % data.p;\
}  
template<> void SgTreeNode<Data>::down()      
{ 
    push(lch);  push(rch);  
    data.tag_init();
}
template<> void SgTreeNode<Data>::update()    
{ 
    data.tag_init(); 
    data.sum = (lch->data.sum + rch->data.sum) % data.p;
}
template<> void SgTreeNode<Data>::cover()
{
    if (data.ifmultiply) {
        data.sum = (data.sum * data.val) % data.p;
        data.tag_mult = (data.tag_mult * data.val) % data.p;
        data.tag_plus = (data.tag_plus * data.val) % data.p;
    }else{
        data.sum = (data.sum + data.val * len) % data.p;
        data.tag_plus = (data.tag_plus + data.val) % data.p;
    }
}
template<> auto SgTreeNode<Data>::query()
{
    if (data.x <= l && r <= data.y) return data.sum;
    down();
    long long ans = 0;
    if (lch->r >= data.x) ans += lch->query();
    if (rch->l <= data.y) ans += rch->query();
    return ans % data.p;
}

int main()
{
    int n, m, a, b, c, d;
    cin >> n >> m >> Data::p;
    vector<Data> init_data(n+1);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &init_data[i].sum);
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
                OP.ifmultiply = 1;
                tree.modify(b, c);
            }break;
            case 2:{
                scanf("%d", &d);
                OP.val = d;
                OP.ifmultiply = 0;
                tree.modify(b, c);
            }break;
            case 3:{
                printf("%lld\n", tree.getval(b, c));
            }break;
        }
    }
    return 0;
}
