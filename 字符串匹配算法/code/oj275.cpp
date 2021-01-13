/*************************************************************************
	> File Name: oj275.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Wed 13 Jan 2021 07:00:09 PM CST
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


#define MAX_N 1000000
#define P 100007
#define base 13
int H[MAX_N + 5];
int K[MAX_N + 5];
int inv[P];
char s[MAX_N + 5];

void init() {
    inv[1] = 1;
    for (int i = 2; i < P; ++i) {
        inv[i] = ((-(P / i) * inv[P % i]) % P + P) % P;
        
    }
    K[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        K[i] = (K[i - 1] * base) % P;
    }
    H[0] = 0;
    for (int i = 1; s[i]; ++i) {
        H[i] = (H[i - 1] + K[i] * s[i]) % P;
    }
}

int getH(int l, int r) {
    return ((H[r] - H[l - 1]) % P * inv[K[l]] % P + P) % P;
}

int isSame(int i, int j, int n) {
    for (int k = 0; k < n; ++k) {
        if (s[i + k] - s[j + k]) return false;
    }
    return true;
}

int main () {
    
    scanf("%s", s + 1);
    int m, l1, l2, r1, r2;
    init();

    scanf("%d", &m);

    for (int i = 0; i < m; ++i ) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        int val1 = getH(l1,r1);
        int val2 = getH(l2, r2);
        int n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;
        if (n1 - n2 || val1 - val2) {
            printf("No\n");
        }else {
            if (isSame(l1, l2, n1)) {
                printf("Yes\n");
            }else {
                printf("No\n");
            }
        }
    }
}
