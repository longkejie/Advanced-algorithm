/*************************************************************************
	> File Name: oj271_单调队列.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Tue 19 Jan 2021 02:31:48 PM CST
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
#define MAX_N 300000
int n, k;

int num[MAX_N + 5];

int mmin[MAX_N + 5];
int mmax[MAX_N + 5];
int cnt1;
int cnt2;
int main () {    

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    deque<int> que1, que2;
    for (int i = 0; i < k; ++i) {
        while (que1.size() && num[i] < que1.back()) {
            que1.pop_back();
        }
        que1.push_back(num[i]);
        while (que2.size() && num[i] > que2.back()) {
            que2.pop_back();
        }
        que2.push_back(num[i]); 
    }
    mmin[cnt1++] = que1.front();
    mmax[cnt2++] = que2.front();

    for (int i = k; i < n; ++i) {
        if (num[i - k] == que1.front()) que1.pop_front();
        while (que1.size() && num[i] < que1.back()) {
            que1.pop_back();
        }
        
        que1.push_back(num[i]);
        if (num[i - k] == que2.front()) que2.pop_front();
        while (que2.size() && num[i] > que2.back()) {
            que2.pop_back();
        }
        que2.push_back(num[i]); 
        mmin[cnt1++] = que1.front();
        mmax[cnt2++] = que2.front();
    }
    for (int i = 0 ; i < cnt1; ++i) {
        if (i) cout << " ";
        cout << mmin[i];
    }
    cout << endl;
    for (int i = 0; i < cnt2; ++i) {
        if (i) cout << " ";
        cout << mmax[i];
    }
    cout << endl;
    return 0;
}
