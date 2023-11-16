---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Prim.hpp
    title: "Prim's algorithm / \u30D7\u30EA\u30E0\u6CD5\u306B\u3088\u308B\u6700\u5C0F\
      \u5168\u57DF\u6728"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_12_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_12_A
  bundledCode: "#line 1 \"Graph/Prim.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_12_A\"\
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/Prim.hpp\"\n\nstruct Edge{\n    int\
    \ from;\n    int to;\n    long cost;\n};\n\nusing Graph = vector<vector<Edge>>;\n\
    using Pll = pair<long,long>;\n\n/*\u30D7\u30EA\u30E0\u6CD5*/\nstruct Prim{\n \
    \   Graph G;\n    int V;\n    Prim(int V):V(V){\n        G.resize(V);\n    }\n\
    \    //\u7121\u5411\u30B0\u30E9\u30D5\uFF01\n    void addEdge(int from,int to,long\
    \ cost){\n        G[from].push_back({from,to,cost});\n        G[to].push_back({to,from,cost});\n\
    \    }\n    long long build(){\n        long long res = 0;\n        vector<bool>\
    \ used(V,false);\n        priority_queue<Pll,vector<Pll>,greater<Pll>> que;\n\
    \        que.push({0,0});\n        while(!que.empty()){\n            auto [cost,\
    \ v] = que.top(); que.pop();\n            if(used[v])continue;\n            used[v]\
    \ = true;\n            res += cost;\n            for(auto& e:G[v]){\n        \
    \        if(!used[e.to]){\n                    que.push({e.cost,e.to});\n    \
    \            }\n            }\n        }\n        return res;\n    }\n};\n#line\
    \ 4 \"Graph/Prim.test.cpp\"\nusing namespace std;\n\nint main(){\n    int n;\n\
    \    cin >> n;\n    Prim k(n);\n    for(int i=0;i<n;i++)for(int j=0;j<n;j++){\n\
    \        int a;\n        cin >> a;\n        if(a!=-1)k.addEdge(i,j,a);\n    }\n\
    \    cout << k.build() << endl;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_12_A\"\
    \n# include <iostream>\n# include \"Prim.hpp\"\nusing namespace std;\n\nint main(){\n\
    \    int n;\n    cin >> n;\n    Prim k(n);\n    for(int i=0;i<n;i++)for(int j=0;j<n;j++){\n\
    \        int a;\n        cin >> a;\n        if(a!=-1)k.addEdge(i,j,a);\n    }\n\
    \    cout << k.build() << endl;\n}\n"
  dependsOn:
  - Graph/Prim.hpp
  - templete.hpp
  isVerificationFile: true
  path: Graph/Prim.test.cpp
  requiredBy: []
  timestamp: '2023-11-16 00:45:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/Prim.test.cpp
layout: document
redirect_from:
- /verify/Graph/Prim.test.cpp
- /verify/Graph/Prim.test.cpp.html
title: Graph/Prim.test.cpp
---
