---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random.cpp\"\n#line 1 \"Data-Structure/cumulative2D.test.cpp\"\
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
    \    }\n    return in;\n}\n\n#line 2 \"Data-Structure/cumulative2D.hpp\"\n\n\n\
    template<class T> struct CumulativeSum2D{\n    size_t H,W;\n    vector<vector<T>>data,A;\n\
    \    bool isBuild=false;\n    CumulativeSum2D(size_t H,size_t W){\n        this->H=H;\n\
    \        this->W=W;\n        data.resize(H+1,vector<T>(W+1,0));\n        A.resize(H+1,vector<T>(W+1,0));\n\
    \    }\n    void add(int y1,int x1,int y2,int x2,T x){\n        A[y1][x1]+=x;\n\
    \        A[y2+1][x1]-=x;\n        A[y1][x2+1]-=x;\n        A[y2+1][x2+1]+=x;\n\
    \    }\n    void add(int y1,int x1,T x){\n        add(y1,x1,y1+1,x1+1,x);\n  \
    \  }\n\n    void build(){\n        data=vector<vector<T>>(A.size()+1,vector<T>(A.front().size()+1,0));\n\
    \        \n        for(int _=0; _<2; _++){\n            for(size_t i=0; i<=H;\
    \ i++){\n                for(size_t j=0; j<W; j++){\n                    A[i][j+1]+=A[i][j];\n\
    \                }\n            }\n            for(size_t i=0; i<H; i++){\n  \
    \              for(size_t j=0; j<=W; j++){\n                    A[i+1][j]+=A[i][j];\n\
    \                }\n            }\n        }\n\n        for(size_t i=0; i<=H;\
    \ i++){\n            for(size_t j=0; j<=W; j++){\n                data[i+1][j+1]=A[i][j];\n\
    \            }\n        }\n\n        isBuild=true;\n    }\n    /*w1<=x<w2, h1<=y<h2*/\n\
    \    T sum(int h1,int w1,int h2,int w2){\n        if(!isBuild)build();\n     \
    \   return data[h2][w2]-data[h1][w2]-data[h2][w1]+data[h1][w1];\n    }\n    //\
    \ 1\uFFFD_\uFFFD\u0312l\uFFFD\uFFFD\u0502\uFFFD\n    T sum(int h1,int w1){\n \
    \       return sum(h1,w1,h1+1,w1+1);\n    }\n};\n#line 3 \"Data-Structure/cumulative2D.test.cpp\"\
    \n\nint main(){\n    int N;cin>>N;\n    int M = 2;\n    CumulativeSum2D<long>\
    \ cum(M,M);\n    for(int i=0;i<N;i++){\n        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;\n\
    \        cum.add(y1,x1,y2-1,x2-1,1);\n    }\n    // \u4E00\u756A\u5927\u304D\u3044\
    \u5024\u3092\u63A2\u3059\n    long ans=0;\n    for(int i=0;i<M;i++){\n       \
    \ for(int j=0;j<M;j++){\n            chmax(ans,cum.sum(i,j));\n            cout\
    \ << cum.sum(i,j)  << \" \";\n        }\n        cout << endl;\n    }\n    cout\
    \ << ans << endl;\n}\n"
  code: "#line 1 \"Data-Structure/cumulative2D.test.cpp\"\n#line 2 \"templete.hpp\"\
    \n\n#include <iostream> // cout, endl, cin\n#include <string> // string, to_string,\
    \ stoi\n#include <vector> // vector\n#include <algorithm> // min, max, swap, sort,\
    \ reverse, lower_bound, upper_bound\n#include <utility> // pair, make_pair\n#include\
    \ <tuple> // tuple, make_tuple\n#include <cstdint> // int64_t, int*_t\n#include\
    \ <cstdio> // printf\n#include <map> // map\n#include <queue> // queue, priority_queue\n\
    #include <set> // set\n#include <stack> // stack\n#include <deque> // deque\n\
    #include <unordered_map> // unordered_map\n#include <unordered_set> // unordered_set\n\
    #include <bitset> // bitset\n#include <cctype> // isupper, islower, isdigit, toupper,\
    \ tolower\n#include <iomanip>\n#include <climits>\n#include <cmath>\n#include\
    \ <functional>\n#include <numeric>\n#include <regex>\n#include <array>\n#include\
    \ <fstream>\n#include <sstream>\n\n\nusing namespace std;\n\n\n\ntemplate<class\
    \ T> inline bool chmin(T& a, T b) {\n    if (a > b) {\n        a = b;\n      \
    \  return true;\n    }\n    return false;\n}\ntemplate<class T> inline bool chmax(T&\
    \ a, T b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n \
    \   return false;\n}\n\ntemplate<class T> void printArray(vector<T>&A){\n    for(T&a:A){\n\
    \        cout<<a<<\" \";\n    }\n    cout<<endl;\n}\ntemplate<class T> void printArrayln(vector<T>&A){\n\
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
    \    }\n    return in;\n}\n\n#line 2 \"Data-Structure/cumulative2D.hpp\"\n\n\n\
    template<class T> struct CumulativeSum2D{\n    size_t H,W;\n    vector<vector<T>>data,A;\n\
    \    bool isBuild=false;\n    CumulativeSum2D(size_t H,size_t W){\n        this->H=H;\n\
    \        this->W=W;\n        data.resize(H+1,vector<T>(W+1,0));\n        A.resize(H+1,vector<T>(W+1,0));\n\
    \    }\n    void add(int y1,int x1,int y2,int x2,T x){\n        A[y1][x1]+=x;\n\
    \        A[y2+1][x1]-=x;\n        A[y1][x2+1]-=x;\n        A[y2+1][x2+1]+=x;\n\
    \    }\n    void add(int y1,int x1,T x){\n        add(y1,x1,y1+1,x1+1,x);\n  \
    \  }\n\n    void build(){\n        data=vector<vector<T>>(A.size()+1,vector<T>(A.front().size()+1,0));\n\
    \        \n        for(int _=0; _<2; _++){\n            for(size_t i=0; i<=H;\
    \ i++){\n                for(size_t j=0; j<W; j++){\n                    A[i][j+1]+=A[i][j];\n\
    \                }\n            }\n            for(size_t i=0; i<H; i++){\n  \
    \              for(size_t j=0; j<=W; j++){\n                    A[i+1][j]+=A[i][j];\n\
    \                }\n            }\n        }\n\n        for(size_t i=0; i<=H;\
    \ i++){\n            for(size_t j=0; j<=W; j++){\n                data[i+1][j+1]=A[i][j];\n\
    \            }\n        }\n\n        isBuild=true;\n    }\n    /*w1<=x<w2, h1<=y<h2*/\n\
    \    T sum(int h1,int w1,int h2,int w2){\n        if(!isBuild)build();\n     \
    \   return data[h2][w2]-data[h1][w2]-data[h2][w1]+data[h1][w1];\n    }\n    //\
    \ 1\uFFFD_\uFFFD\u0312l\uFFFD\uFFFD\u0502\uFFFD\n    T sum(int h1,int w1){\n \
    \       return sum(h1,w1,h1+1,w1+1);\n    }\n};\n#line 3 \"Data-Structure/cumulative2D.test.cpp\"\
    \n\nint main(){\n    int N;cin>>N;\n    int M = 2;\n    CumulativeSum2D<long>\
    \ cum(M,M);\n    for(int i=0;i<N;i++){\n        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;\n\
    \        cum.add(y1,x1,y2-1,x2-1,1);\n    }\n    // \u4E00\u756A\u5927\u304D\u3044\
    \u5024\u3092\u63A2\u3059\n    long ans=0;\n    for(int i=0;i<M;i++){\n       \
    \ for(int j=0;j<M;j++){\n            chmax(ans,cum.sum(i,j));\n            cout\
    \ << cum.sum(i,j)  << \" \";\n        }\n        cout << endl;\n    }\n    cout\
    \ << ans << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: random.cpp
  requiredBy: []
  timestamp: '2023-11-16 00:45:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random.cpp
layout: document
redirect_from:
- /library/random.cpp
- /library/random.cpp.html
title: random.cpp
---
