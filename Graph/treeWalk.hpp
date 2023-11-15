#include "templete.hpp"

struct Node{
    int left;
    int right;
    int parent = -1;
    // 存在しない場合は-1
};

using BinaryTree = vector<Node>;

void binaryTreeWalkPre(const BinaryTree &T, vector<int>&order, int &n, int v=0){
    // v: 現在の頂点、 n: 現在の番号
    if(v==-1)return;
    order[n++] = v;
    binaryTreeWalkPre(T, order, n, T[v].left);
    binaryTreeWalkPre(T, order, n, T[v].right);
}

void binaryTreeWalkIn(const BinaryTree &T, vector<int>&order, int &n, int v=0){
    // v: 現在の頂点、 n: 現在の番号
    if(v==-1)return;
    binaryTreeWalkIn(T, order, n, T[v].left);
    order[n++] = v;
    binaryTreeWalkIn(T, order, n, T[v].right);
}

void binaryTreeWalkPost(const BinaryTree &T, vector<int>&order, int &n, int v=0){
    // v: 現在の頂点、 n: 現在の番号
    if(v==-1)return;
    binaryTreeWalkPost(T, order, n, T[v].left);
    binaryTreeWalkPost(T, order, n, T[v].right);
    order[n++] = v;
}