/*************************************************************************
	> File Name: oj261_对顶栈.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Tue 19 Jan 2021 11:20:30 AM CST
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

class NewStruct {
public:
    NewStruct() {
        sum[0] = 0;
        ans[0] = INT64_MIN;
    }
    void insert(long long x) {
        s1.push(x);
        int ind = s1.size();
        long long val = x + sum[ind - 1];
        sum[ind] = val;
        ans[ind] = max(ans[ind - 1],val);
        return ; 
    }
    void del() {
        if (s1.empty()) return;
        s1.pop();
        return ;
    }
    void move_left() {
        if (s1.empty()) return;
        s2.push(s1.top());
        s1.pop();
        return;
    }
    void move_right() {
        if (s2.empty()) return;
        insert(s2.top());
        s2.pop();
        return;
    }
    long long query(long long k) {
        return ans[k];
    }
private:
    stack<long long> s1, s2;
    long long ans[1005];
    long long sum[1005];
};


int main () {
    long long n;
    cin >> n;
    string op;
    int val;
    NewStruct s;
    for (int i = 0; i < n; ++i) {
        cin >> op;
        switch(op[0]) {
            case 'I':cin >> val;s.insert(val);break;
            case 'D':s.del();break;
            case 'L':s.move_left();break;
            case 'R':s.move_right();break;
            case 'Q':cin >> val;cout << s.query(val) << endl;break;

        }
    }

    return 0;
}
