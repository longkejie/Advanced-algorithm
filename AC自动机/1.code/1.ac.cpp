/*************************************************************************
	> File Name: 1.ac.cpp
	> Author: longkejie
	> Mail:1721248012@qq.com 
	> Created Time: Sat 23 Jan 2021 03:05:37 PM CST
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
#define BASE 26
typedef struct Node {
    int flag, tag[BASE];
    const char *str;
    struct Node *next[BASE], *fail;
}Node;
int node_cnt;
Node *getNewNode() {
    node_cnt++;
    Node *q = (Node *)malloc(sizeof(Node));
    q -> flag = 0;
    memset(q->next, 0, sizeof(q->next));
    q->fail = NULL;
    return q;
}

void insert(Node *root, const char *str) {
    for (int i = 0; str[i]; ++i) {
        int ind = str[i] - 'a';
        if (root -> next[ind] == NULL) root->next[ind] = getNewNode();
        root = root->next[ind];
        root -> tag[ind] = 1;
    }
    root -> flag = 1;
    root -> str = strdup(str);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; ++i) {
        if (root->tag[i]) clear(root->next[i]);
    }
    free(root->fail);
    free(root);
}

void build_ac(Node *root) {
    Node **q = (Node **)malloc(sizeof(Node *) * (node_cnt + 5));
    int head = 0, tail = 0;
    root->fail = NULL;
    for (int i = 0; i < BASE; ++i) {
        if (root -> next[i]) {
            root->next[i]->fail = root;
            q[tail++] = root->next[i];
        }else {
            root->next[i] = root;
        }
    }
    while (head < tail) {
        Node *p = q[head++];
        for (int i = 0; i < BASE; ++i) {
            Node *c = p->next[i], *k = p -> fail;
            if (c == NULL) {
                p->next[i] = k -> next[i];
                continue;
            }
            while (k && k->next[i] == NULL) k = k -> fail;
            if (k == NULL) k = root;
            if (k -> next[i]) k = k -> next[i];
            c -> fail = k;
            q[tail++] = c;
        }
    }
    free(q);
    return ;
}

void match(Node *root, const char *test) {
    Node *p = root, *q;
    for (int i = 0; test[i]; ++i) {
        int ind = test[i] - 'a';
        p = p->next[ind];
        q = p;
        while (q) {
            if (q -> flag) printf("find : %s\n",q->str);
            q = q = q->fail;
        } 
    }
}

int main () {
    int n;
    char str[100];
    scanf("%d",&n);
    Node *root = getNewNode();
    for (int i = 0;i < n; ++i) {
        scanf("%s",str);
        insert(root, str);
    }
    build_ac(root);
    scanf("%s", str);
    match(root, str);
    clear(root);
    return 0;
}
