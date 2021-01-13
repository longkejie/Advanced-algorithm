/*************************************************************************
	> File Name: string_match.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Wed 13 Jan 2021 12:11:29 PM CST
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

int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; ++i) {
        int flag = 1;
        for (int j = 0; t[j]; ++j) {
            if (t[j] == s[i + j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int getNext(const char *t, int &j, char input, int *next) {
    while (j != -1 && t[j + 1] != input) j = next[j];
    if (t[j + 1] == input) j = j + 1;
    return j;
}

int kmp(const char *s, const char *t) {
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * (n + 1));
    memset(next, -1, sizeof(next));
    next[0] = -1;
    for (int i = 1, j = -1; t[i]; ++i) next[i] = getNext(t, j, t[i], next);
    for (int i = 0, j = -1; s[i]; ++i) {
        if (getNext(t, j, s[i], next) != n - 1) continue;
        return i - n + 1;
    }    
    return -1;
}

int sunday(const char *s, const char *t) {
    int n = strlen(t);
    int m = strlen(s);
    int offset[256];
    for (int i = 0; i < 256; ++i) offset[i] = n + 1;
    for (int i = 0; t[i]; ++i) offset[t[i]] = n - i;
    for (int i = 0; i + n <= m; i += offset[s[i + n]]) {
        int flag = 1;
        for (int j = 0; t[j]; ++j) {
            flag = flag && (t[j] == s[i + j]);
        } 
        if (flag) return i;
    }
    return -1;
}


int main () {
    char s[1000], t[1000];

    while (scanf("%s %s", s, t)) {
        printf("brute_force(%s %s) = %d\n", s, t, brute_force(s,t) );
        printf("KMP(%s %s) = %d\n", s, t, kmp(s,t));
        printf("sunday(%s %s) = %d\n", s, t, sunday(s,t));
    }

    return 0;
}
