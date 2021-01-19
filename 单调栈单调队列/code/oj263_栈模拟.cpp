/*************************************************************************
	> File Name: oj263_栈模拟.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Tue 19 Jan 2021 01:21:28 PM CST
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

int a[30], s[30], top;

bool is_vaild(int *a, int n) {
    int j = 0;
    top = -1;
    for (int i = 0; i < n; ++i) {
        while (j < a[i]) {
            s[++top] = (++j);
        }
        if (top == -1 || s[top] - a[i]) return false;
        --top;
    }
    return true;
}

int main () {
    
    int n;
    cin >> n;
    int b = 0;
    for (int i = 0; i < n; ++i) a[i] = i + 1;
    do{
        if (!is_vaild(a, n)) continue;
        for (int i = 0; i < n; ++i) {
            cout << a[i];
        }
        b++;
        cout << endl;
    }while (b < 20 && next_permutation(a, a + n));
    
    return 0;
}
