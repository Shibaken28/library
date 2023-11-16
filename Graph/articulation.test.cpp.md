---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/lowlink.hpp
    title: "Lowlink / \u30B0\u30E9\u30D5\u306E\u95A2\u7BC0\u70B9\u30FB\u6A4B\u306E\
      \u691C\u51FA"
  - icon: ':question:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A
  bundledCode: "#line 1 \"Graph/articulation.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A\"\
    \n# include <iostream>\n#line 2 \"templete.hpp\"\n\n#line 4 \"templete.hpp\"\n\
    #include <string> // string, to_string, stoi\n#include <vector> // vector\n#include\
    \ <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound\n#include\
    \ <utility> // pair, make_pair\n#include <tuple> // tuple, make_tuple\n#include\
    \ <cstdint> // int64_t, int*_t\n#include <cstdio> // printf\n#include <map> //\
    \ map\n#include <queue> // queue, priority_queue\n#include <set> // set\n#include\
    \ <stack> // stack\n#include <deque> // deque\n#include <unordered_map> // unordered_map\n\
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/lowlink.hpp\"\n\nusing Graph = vector<vector<int>>;\n\
    \n// \u6A4B\u3068\u95A2\u7BC0\u70B9\u3092\u6C42\u3081\u308B\nstruct Lowlink{\n\
    \    int v;\n    vector<int> ord, low;\n    // ord[i] := \u9802\u70B9i\u306Bdfs\u3067\
    \u8A2A\u308C\u305F\u9806\u756A\n    // low[i] := DFS\u6728\u3092\u4E0B\u3063\u3066\
    \u3044\u304D(\u8449\u65B9\u5411\u306B\u9032\u3093\u3067\u3044\u304D)\u3001\u6700\
    \u5F8C\u306B\u5F8C\u9000\u8FBA\u3092\u4F7F\u3063\u3066\u9802\u70B9i\u3088\u308A\
    \u524D\u306B\u8A2A\u308C\u305F\u9802\u70B9\u306Eord\u306E\u6700\u5C0F\u5024\n\
    \    // * \u3059\u306A\u308F\u3061\u3001\u5F8C\u9000\u8FBA=\u30EB\u30FC\u30D7\u304C\
    \u898B\u3064\u304B\u308B\u3068\u3001\u305D\u306E\u30EB\u30FC\u30D7\u5185\u306E\
    low\u306B\u540C\u3058\u6570\u5B57\u3092\u5272\u308A\u5F53\u3066\u3066\u3044\u304F\
    \u3053\u3068\u306B\u306A\u308B(\u30EB\u30FC\u30D7\u304C\u8907\u6570\u91CD\u306A\
    \u3063\u3066\u3044\u308B\u5834\u5408\u3082\u306A\u3093\u304B\u3044\u3044\u304B\
    \u3093\u3058\u306E\u6319\u52D5\u306B\u306A\u308B)\n    vector<int> articulation;\n\
    \    vector<pair<int, int>> bridge;\n    Graph &G;\n    Lowlink(Graph &G) : G(G)\
    \ {\n        v = (int)G.size();\n        ord.resize(v, -1);\n        low.resize(v,\
    \ -1);\n        for(int i = 0; i < v; i++){\n            if(ord[i] == -1) dfs(i,\
    \ -1, 0);\n        }\n    }\n    int dfs(int n, int par, int c){\n        ord[n]\
    \ = c++;\n        low[n] = ord[n];\n        bool is_articulation = false;\n  \
    \      int cnt = 0; // \u5B50\u306E\u6570\n        for(auto& e : G[n]){\n    \
    \        if(ord[e] == -1){\n                cnt++;\n                c = dfs(e,\
    \ n, c);\n                low[n] = min(low[n], low[e]); //low\u3092\u4F1D\u642C\
    \n                if(par != -1 && ord[n] <= low[e]) is_articulation = true; //\u95A2\
    \u7BC0\u70B9\n                if(ord[n] < low[e]) bridge.push_back({min(n, e),\
    \ max(n, e)}); //\u6A4B\n            }else if(e != par){ //\u5F8C\u9000\u8FBA\n\
    \                low[n] = min(low[n], ord[e]); //\u30EB\u30FC\u30D7\u691C\u51FA\
    \n            }\n        }\n        if(par == -1 && cnt > 1) is_articulation =\
    \ true; //\u6839\n        if(is_articulation) articulation.push_back(n);\n   \
    \     return c;\n    }\n};\n\n#line 4 \"Graph/articulation.test.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n    int v,e; cin>>v>>e;\n    Graph G(v);\n    for(int i=0;i<e;i++){\n\
    \        int s,t; cin>>s>>t;\n        G[s].push_back(t);\n        G[t].push_back(s);\n\
    \    }\n    Lowlink lowlink(G);\n    sort(lowlink.articulation.begin(), lowlink.articulation.end());\n\
    \    for(auto& x : lowlink.articulation) cout << x << endl;\n}\n\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A\"\
    \n# include <iostream>\n# include \"lowlink.hpp\"\nusing namespace std;\n\nint\
    \ main(){\n    int v,e; cin>>v>>e;\n    Graph G(v);\n    for(int i=0;i<e;i++){\n\
    \        int s,t; cin>>s>>t;\n        G[s].push_back(t);\n        G[t].push_back(s);\n\
    \    }\n    Lowlink lowlink(G);\n    sort(lowlink.articulation.begin(), lowlink.articulation.end());\n\
    \    for(auto& x : lowlink.articulation) cout << x << endl;\n}\n\n"
  dependsOn:
  - Graph/lowlink.hpp
  - templete.hpp
  isVerificationFile: true
  path: Graph/articulation.test.cpp
  requiredBy: []
  timestamp: '2023-11-16 21:58:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/articulation.test.cpp
layout: document
redirect_from:
- /verify/Graph/articulation.test.cpp
- /verify/Graph/articulation.test.cpp.html
title: Graph/articulation.test.cpp
---
