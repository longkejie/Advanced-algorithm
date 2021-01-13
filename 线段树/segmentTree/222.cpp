/*************************************************************************
	> File Name: 222.cpp
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
    int max;
    static int x, y;
    static int val;
};
int Data::x, Data::y;
int Data::val;

template<> void SgTreeNode<Data>::down(){}

template<> void SgTreeNode<Data>::update()
{ 
    data.max = max(lch->data.max, rch->data.max);
}
template<> void SgTreeNode<Data>::cover()       
{ 
    data.max = data.val;
}
template<> auto SgTreeNode<Data>::query()
{
    if (data.y < l || r < data.x) return 1 << 31;
    if (data.x <= l && r <= data.y) return data.max;
    return max(lch->query(), rch->query());
}

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    vector<Data> init_data(n + 1);
    for (int i = 1; i <= n; i++){
        scanf("%d", &init_data[i].max);
    }
    SegmentTree<Data> tree;
    tree.buildtree(init_data);
    Data OP;
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d",&a,&b,&c);
        switch(a){
            case 1:
            {
                OP.val = c;
                tree.modify(b);
                break;
            }
            case 2:
            {
                if (b > c) {
                    printf("-2147483648\n");
                    break;
                }
                printf("%d\n", tree.getval(b, c));
                break;
            }   
        }
    }
    return 0;
}
