---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/treeWalk.hpp
    title: "Tree Walk / \u4E8C\u5206\u6728\u306E\u5DE1\u56DE"
  - icon: ':heavy_check_mark:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_7_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_7_C
  bundledCode: "#line 1 \"Graph/treeWalk.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_7_C\"\
    \n#line 2 \"templete.hpp\"\n\n#include <iostream> // cout, endl, cin\n#include\
    \ <string> // string, to_string, stoi\n#include <vector> // vector\n#include <algorithm>\
    \ // min, max, swap, sort, reverse, lower_bound, upper_bound\n#include <utility>\
    \ // pair, make_pair\n#include <tuple> // tuple, make_tuple\n#include <cstdint>\
    \ // int64_t, int*_t\n#include <cstdio> // printf\n#include <map> // map\n#include\
    \ <queue> // queue, priority_queue\n#include <set> // set\n#include <stack> //\
    \ stack\n#include <deque> // deque\n#include <unordered_map> // unordered_map\n\
    #include <unordered_set> // unordered_set\n#include <bitset> // bitset\n#include\
    \ <cctype> // isupper, islower, isdigit, toupper, tolower\n#include <iomanip>\n\
    #include <climits>\n#include <cmath>\n#include <functional>\n#include <numeric>\n\
    #include <regex>\n#include <array>\n#include <fstream>\n#include <sstream>\n\n\
    \nusing namespace std;\n\n\n\ntemplate<class T> inline bool chmin(T& a, T b) {\n\
    \    if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\ntemplate<class T> inline bool chmax(T& a, T b) {\n    if (a < b) {\n      \
    \  a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate<class\
    \ T> void printArray(vector<T>&A){\n    for(T&a:A){\n        cout<<a<<\" \";\n\
    \    }\n    cout<<endl;\n}\ntemplate<class T> void printArrayln(vector<T>&A){\n\
    \    for(T&a:A){\n        cout<<a<<endl;\n    }\n}\n\n\ntemplate<class T1,class\
    \ T2> std::ostream &operator<<(std::ostream &out, const pair<T1,T2> &A){\n   \
    \ cout<<\"{\"<<A.first<<\",\"<<A.second<<\"}\";\n    return out;\n}\n\ntemplate<class\
    \ T1,class T2> std::ostream &operator<<(std::ostream &out, const map<T1,T2> &M){\n\
    \    for(const auto&A:M){\n        cout<<\"{\"<<A.first<<\",\"<<A.second<<\"}\"\
    ;\n    }\n    return out;\n}\n\ntemplate<class T1> std::ostream &operator<<(std::ostream\
    \ &out, const set<T1> &M){\n    cout<<\"{\";\n    for(const auto&A:M){\n     \
    \   cout<<A<<\", \";\n    }\n    cout<<\"}\"<<endl;\n    return out;\n}\n\n\n\
    template<class T1> std::ostream &operator<<(std::ostream &out, const multiset<T1>\
    \ &M){\n    cout<<\"{\";\n    for(const auto&A:M){\n        cout<<A<<\", \";\n\
    \    }\n    cout<<\"}\"<<endl;\n    return out;\n}\n\ntemplate<class T> std::ostream\
    \ &operator<<(std::ostream &out, const vector<T> &A){\n    for(const T &a:A){\n\
    \        cout<<a<<\" \";\n    }\n    return out;\n}\n\nvoid print() { cout <<\
    \ endl; }\n \ntemplate <typename Head, typename... Tail>\nvoid print(Head H, Tail...\
    \ T) {\n  cout << H << \" \";\n  print(T...);\n}\n\n\ntemplate<class T> std::istream\
    \ &operator>>(std::istream &in,vector<T>&A){\n    for(T&a:A){\n        std::cin>>a;\n\
    \    }\n    return in;\n}\n\n#line 2 \"Graph/treeWalk.hpp\"\n\nstruct Node{\n\
    \    int left;\n    int right;\n    int parent = -1;\n    // \u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306F-1\n};\n\nusing BinaryTree = vector<Node>;\n\nvoid\
    \ binaryTreeWalkPre(const BinaryTree &T, vector<int>&order, int &n, int v=0){\n\
    \    // v: \u73FE\u5728\u306E\u9802\u70B9\u3001 n: \u73FE\u5728\u306E\u756A\u53F7\
    \n    if(v==-1)return;\n    order[n++] = v;\n    binaryTreeWalkPre(T, order, n,\
    \ T[v].left);\n    binaryTreeWalkPre(T, order, n, T[v].right);\n}\n\nvoid binaryTreeWalkIn(const\
    \ BinaryTree &T, vector<int>&order, int &n, int v=0){\n    // v: \u73FE\u5728\u306E\
    \u9802\u70B9\u3001 n: \u73FE\u5728\u306E\u756A\u53F7\n    if(v==-1)return;\n \
    \   binaryTreeWalkIn(T, order, n, T[v].left);\n    order[n++] = v;\n    binaryTreeWalkIn(T,\
    \ order, n, T[v].right);\n}\n\nvoid binaryTreeWalkPost(const BinaryTree &T, vector<int>&order,\
    \ int &n, int v=0){\n    // v: \u73FE\u5728\u306E\u9802\u70B9\u3001 n: \u73FE\u5728\
    \u306E\u756A\u53F7\n    if(v==-1)return;\n    binaryTreeWalkPost(T, order, n,\
    \ T[v].left);\n    binaryTreeWalkPost(T, order, n, T[v].right);\n    order[n++]\
    \ = v;\n}\n#line 3 \"Graph/treeWalk.test.cpp\"\n\n\nint main(void){\n    std::cin.tie(0)->sync_with_stdio(0);\n\
    \    int n;cin>>n;\n    BinaryTree bt(n);\n    for(int i=0;i<n;i++){\n       \
    \ int id, l, r;\n        cin>>id>>l>>r;\n        bt[id].left = l;\n        bt[id].right\
    \ = r;\n        if(l>=0){\n            bt[l].parent = id;\n        }\n       \
    \ if(r>=0){\n            bt[r].parent = id;\n        }\n    }\n    // root\u3092\
    \u63A2\u3059\n    int root = 0;\n    for(int i=0;i<n;i++){\n        if(bt[i].parent==-1){\n\
    \            root = i;\n            break;\n        }\n    }\n\n    vector<int>\
    \ pre(n), in(n), post(n);\n    int a;\n    a = 0; binaryTreeWalkPre(bt, pre, a,\
    \ root);\n    a = 0; binaryTreeWalkIn(bt, in, a, root);\n    a = 0; binaryTreeWalkPost(bt,\
    \ post, a, root);\n    cout<<\"Preorder\"<<endl;\n    for(auto&v:pre)cout<<\"\
    \ \"<<v;\n    cout<<endl;\n    cout<<\"Inorder\"<<endl;\n    for(auto&v:in)cout<<\"\
    \ \"<<v;\n    cout<<endl;\n    cout<<\"Postorder\"<<endl;\n    for(auto&v:post)cout<<\"\
    \ \"<<v;\n    cout<<endl;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_7_C\"\n\
    # include \"treeWalk.hpp\"\n\n\nint main(void){\n    std::cin.tie(0)->sync_with_stdio(0);\n\
    \    int n;cin>>n;\n    BinaryTree bt(n);\n    for(int i=0;i<n;i++){\n       \
    \ int id, l, r;\n        cin>>id>>l>>r;\n        bt[id].left = l;\n        bt[id].right\
    \ = r;\n        if(l>=0){\n            bt[l].parent = id;\n        }\n       \
    \ if(r>=0){\n            bt[r].parent = id;\n        }\n    }\n    // root\u3092\
    \u63A2\u3059\n    int root = 0;\n    for(int i=0;i<n;i++){\n        if(bt[i].parent==-1){\n\
    \            root = i;\n            break;\n        }\n    }\n\n    vector<int>\
    \ pre(n), in(n), post(n);\n    int a;\n    a = 0; binaryTreeWalkPre(bt, pre, a,\
    \ root);\n    a = 0; binaryTreeWalkIn(bt, in, a, root);\n    a = 0; binaryTreeWalkPost(bt,\
    \ post, a, root);\n    cout<<\"Preorder\"<<endl;\n    for(auto&v:pre)cout<<\"\
    \ \"<<v;\n    cout<<endl;\n    cout<<\"Inorder\"<<endl;\n    for(auto&v:in)cout<<\"\
    \ \"<<v;\n    cout<<endl;\n    cout<<\"Postorder\"<<endl;\n    for(auto&v:post)cout<<\"\
    \ \"<<v;\n    cout<<endl;\n}\n"
  dependsOn:
  - Graph/treeWalk.hpp
  - templete.hpp
  isVerificationFile: true
  path: Graph/treeWalk.test.cpp
  requiredBy: []
  timestamp: '2023-11-16 00:45:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/treeWalk.test.cpp
layout: document
redirect_from:
- /verify/Graph/treeWalk.test.cpp
- /verify/Graph/treeWalk.test.cpp.html
title: Graph/treeWalk.test.cpp
---
