---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Dijkstra.hpp
    title: "Dijkstra's algorithm / \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u306B\
      \u3088\u308B\u6700\u77ED\u7D4C\u8DEF"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
  bundledCode: "#line 1 \"Graph/Dijkstra.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\"\
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/Dijkstra.hpp\"\n\nstruct Edge{\n\
    \    int to;\n    long cost;\n};\n\nstruct WeightedVertex{\n    int v;\n    long\
    \ cost;\n};\n\nusing Graph = vector<vector<Edge>>;\n\nvoid dijkstra(int s,Graph\
    \ &G,vector<long>&D){\n    auto comp = [](WeightedVertex &l,WeightedVertex &r){return\
    \ l.cost > r.cost;};\n    priority_queue < \n        WeightedVertex,\n       \
    \ vector<WeightedVertex>,\n        function<bool(WeightedVertex&,WeightedVertex&)>\n\
    \        > qu (comp);\n    D.resize(G.size());\n    fill(D.begin(),D.end(),-1);\n\
    \    D[s] = 0;\n    qu.push({s,0});\n    while(!qu.empty()){\n        auto a =\
    \ qu.top(); qu.pop();\n        int from = a.v;\n        for(auto&e:G[from]){\n\
    \            if(D[e.to] == -1 || D[e.to] > D[from] + e.cost){\n              \
    \  D[e.to] = D[from] + e.cost;\n                qu.push({e.to,D[e.to]});\n   \
    \         }\n        }\n    }\n}\n#line 4 \"Graph/Dijkstra.test.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n    Graph g;\n    int n,m,r;\n    cin >> n >> m >> r;\n\
    \    g.resize(n);\n    for(int i=0;i<m;i++){\n        int s,t,d;\n        cin\
    \ >> s >> t >> d;\n        g[s].push_back({t,d});\n    }\n    vector<long> d;\n\
    \    dijkstra(r,g,d);\n    for(int i=0;i<n;i++){\n        if(d[i] == -1)cout <<\
    \ \"INF\" << endl;\n        else cout << d[i] << endl;\n    }\n}\n\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\"\
    \n# include <iostream>\n# include \"Dijkstra.hpp\"\nusing namespace std;\n\nint\
    \ main(){\n    Graph g;\n    int n,m,r;\n    cin >> n >> m >> r;\n    g.resize(n);\n\
    \    for(int i=0;i<m;i++){\n        int s,t,d;\n        cin >> s >> t >> d;\n\
    \        g[s].push_back({t,d});\n    }\n    vector<long> d;\n    dijkstra(r,g,d);\n\
    \    for(int i=0;i<n;i++){\n        if(d[i] == -1)cout << \"INF\" << endl;\n \
    \       else cout << d[i] << endl;\n    }\n}\n\n"
  dependsOn:
  - Graph/Dijkstra.hpp
  - templete.hpp
  isVerificationFile: true
  path: Graph/Dijkstra.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/Dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Graph/Dijkstra.test.cpp
- /verify/Graph/Dijkstra.test.cpp.html
title: Graph/Dijkstra.test.cpp
---
