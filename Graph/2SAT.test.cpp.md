---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/2SAT.hpp
    title: "2-SAT / \u5145\u8DB3\u53EF\u80FD\u6027\u554F\u984C"
  - icon: ':heavy_check_mark:'
    path: Graph/SCC.hpp
    title: "Strongly Connected Components / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
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
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"Graph/2SAT.test.cpp\"\n# define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/SCC.hpp\"\n\nusing Graph = vector<vector<int>>;\n\
    struct StronglyConnectedComponents{\n    Graph &G;\n    Graph invG;\n    vector<int>\
    \ ord, visit, inv;\n    vector<vector<int>> groups;\n    StronglyConnectedComponents(Graph\
    \ &_G): G(_G){\n        int v = (int)G.size();\n        invG.resize(v);\n    \
    \    for(int i=0;i<v;i++){\n            for(auto&g:G[i]){\n                invG[g].push_back(i);\n\
    \            }\n        }\n        // DFS\u3092\u3059\u308B\n        ord.resize(v,\
    \ -1);\n        inv.resize(v, -1);\n        visit.resize(v, 0);\n        int k\
    \ = 0;\n        for(int i=0;i<v;i++){\n            if(ord[i]==-1)k = dfs(i, k);\n\
    \        }\n        for(int i=0;i<v;i++){\n            inv[ord[i]] = i;\n    \
    \        ord[i] = -1;\n        }\n        // \u8FBA\u3092\u9006\u5411\u304D\u306B\
    \u3057\u3066DFS\n        k = 0;\n        for(int i=v-1;i>=0;i--){\n          \
    \  if(ord[inv[i]]==-1){\n                vector<int> group(0);\n             \
    \   k = dfs2(inv[i], k, group);\n                groups.push_back(group);  \n\
    \            }\n        }\n    }\n    int dfs(int n, int k){\n        if(visit[n])return\
    \ k;\n        visit[n] = 1;\n        for(auto&e:G[n]){\n            k = dfs(e,\
    \ k);\n        }\n        ord[n] = k++;\n        return k;\n    }\n    int dfs2(int\
    \ n,int k, vector<int>&group){\n        group.push_back(n);\n        ord[n] =\
    \ k++;\n        for(auto&e:invG[n]){\n            if(ord[e]==-1){\n          \
    \      k = dfs2(e, k, group);\n            }\n        }\n        return k;\n \
    \   }\n};\n#line 2 \"Graph/2SAT.hpp\"\n\nstruct TwoSAT{\n    int n;\n    vector<bool>\
    \ ans;\n    Graph g;\n    TwoSAT(int n):n(n),ans(n),g(2*n){}\n    void add_clause(int\
    \ x, bool a, int y, bool b){\n        g[x+n*(a?0:1)].push_back(y+n*(b?1:0));\n\
    \        g[y+n*(b?0:1)].push_back(x+n*(a?1:0));\n    }\n    bool satisfiable(){\n\
    \        StronglyConnectedComponents scc(g);\n        vector<int> id(n*2, -1);\
    \ //\u305D\u306E\u9802\u70B9\u542B\u307E\u308C\u3066\u3044\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u756A\u53F7\n        for(int i=0;i<(int)scc.groups.size();i++){\n\
    \            for(int v:scc.groups[i]){\n                if(id[v] != -1) return\
    \ false;\n                id[v] = i;\n            }\n        }\n        for(int\
    \ i=0;i<n;i++){\n            if(id[i] == id[i+n]) return false;\n            ans[i]\
    \ = id[i] < id[i+n];\n        }\n        return true;\n    }\n};\n#line 3 \"Graph/2SAT.test.cpp\"\
    \n\nint main(){\n    string _;\n    int n,m;\n    cin >> _ >> _ >> n >> m;\n \
    \   TwoSAT sat(n);\n    for(int i=0;i<m;i++){\n        int a,b,c;\n        cin\
    \ >> a >> b >> c;\n        sat.add_clause(abs(a)-1, a>0, abs(b)-1, b>0);\n   \
    \ }\n    if(!sat.satisfiable()){\n        cout << \"s UNSATISFIABLE\" << endl;\n\
    \        return 0;\n    }else{\n        cout << \"s SATISFIABLE\" << endl;\n \
    \       cout << \"v \";\n        for(int i=0;i<n;i++){\n            cout << (sat.ans[i]?i+1:-i-1)\
    \ << \" \";\n        }\n        cout << \"0\" << endl;\n    }\n}\n"
  code: "# define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n# include \"\
    2SAT.hpp\"\n\nint main(){\n    string _;\n    int n,m;\n    cin >> _ >> _ >> n\
    \ >> m;\n    TwoSAT sat(n);\n    for(int i=0;i<m;i++){\n        int a,b,c;\n \
    \       cin >> a >> b >> c;\n        sat.add_clause(abs(a)-1, a>0, abs(b)-1, b>0);\n\
    \    }\n    if(!sat.satisfiable()){\n        cout << \"s UNSATISFIABLE\" << endl;\n\
    \        return 0;\n    }else{\n        cout << \"s SATISFIABLE\" << endl;\n \
    \       cout << \"v \";\n        for(int i=0;i<n;i++){\n            cout << (sat.ans[i]?i+1:-i-1)\
    \ << \" \";\n        }\n        cout << \"0\" << endl;\n    }\n}\n"
  dependsOn:
  - Graph/2SAT.hpp
  - Graph/SCC.hpp
  - templete.hpp
  isVerificationFile: true
  path: Graph/2SAT.test.cpp
  requiredBy: []
  timestamp: '2023-11-17 03:21:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/2SAT.test.cpp
layout: document
redirect_from:
- /verify/Graph/2SAT.test.cpp
- /verify/Graph/2SAT.test.cpp.html
title: Graph/2SAT.test.cpp
---
