---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/enum-prime.hpp
    title: "enumerate prime / \u7D20\u6570\u7BE9"
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/isprime.hpp
    title: "is prime / \u7D20\u6570\u5224\u5B9A"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"Math/Number-Theory/enum-prme.test.cpp\"\n# define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n# include <iostream>\n\
    #line 2 \"templete.hpp\"\n\n#line 4 \"templete.hpp\"\n#include <string> // string,\
    \ to_string, stoi\n#include <vector> // vector\n#include <algorithm> // min, max,\
    \ swap, sort, reverse, lower_bound, upper_bound\n#include <utility> // pair, make_pair\n\
    #include <tuple> // tuple, make_tuple\n#include <cstdint> // int64_t, int*_t\n\
    #include <cstdio> // printf\n#include <map> // map\n#include <queue> // queue,\
    \ priority_queue\n#include <set> // set\n#include <stack> // stack\n#include <deque>\
    \ // deque\n#include <unordered_map> // unordered_map\n#include <unordered_set>\
    \ // unordered_set\n#include <bitset> // bitset\n#include <cctype> // isupper,\
    \ islower, isdigit, toupper, tolower\n#include <iomanip>\n#include <climits>\n\
    #include <cmath>\n#include <functional>\n#include <numeric>\n#include <regex>\n\
    #include <array>\n#include <fstream>\n#include <sstream>\n\n\nusing namespace\
    \ std;\n\n\n\ntemplate<class T> inline bool chmin(T& a, T b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate<class\
    \ T> inline bool chmax(T& a, T b) {\n    if (a < b) {\n        a = b;\n      \
    \  return true;\n    }\n    return false;\n}\n\ntemplate<class T> void printArray(vector<T>&A){\n\
    \    for(T&a:A){\n        cout<<a<<\" \";\n    }\n    cout<<endl;\n}\ntemplate<class\
    \ T> void printArrayln(vector<T>&A){\n    for(T&a:A){\n        cout<<a<<endl;\n\
    \    }\n}\n\n\ntemplate<class T1,class T2> std::ostream &operator<<(std::ostream\
    \ &out, const pair<T1,T2> &A){\n    cout<<\"{\"<<A.first<<\",\"<<A.second<<\"\
    }\";\n    return out;\n}\n\ntemplate<class T1,class T2> std::ostream &operator<<(std::ostream\
    \ &out, const map<T1,T2> &M){\n    for(const auto&A:M){\n        cout<<\"{\"<<A.first<<\"\
    ,\"<<A.second<<\"}\";\n    }\n    return out;\n}\n\ntemplate<class T1> std::ostream\
    \ &operator<<(std::ostream &out, const set<T1> &M){\n    cout<<\"{\";\n    for(const\
    \ auto&A:M){\n        cout<<A<<\", \";\n    }\n    cout<<\"}\"<<endl;\n    return\
    \ out;\n}\n\n\ntemplate<class T1> std::ostream &operator<<(std::ostream &out,\
    \ const multiset<T1> &M){\n    cout<<\"{\";\n    for(const auto&A:M){\n      \
    \  cout<<A<<\", \";\n    }\n    cout<<\"}\"<<endl;\n    return out;\n}\n\ntemplate<class\
    \ T> std::ostream &operator<<(std::ostream &out, const vector<T> &A){\n    for(const\
    \ T &a:A){\n        cout<<a<<\" \";\n    }\n    return out;\n}\n\nvoid print()\
    \ { cout << endl; }\n \ntemplate <typename Head, typename... Tail>\nvoid print(Head\
    \ H, Tail... T) {\n  cout << H << \" \";\n  print(T...);\n}\n\n\ntemplate<class\
    \ T> std::istream &operator>>(std::istream &in,vector<T>&A){\n    for(T&a:A){\n\
    \        std::cin>>a;\n    }\n    return in;\n}\n\n#line 2 \"Math/Number-Theory/enum-prime.hpp\"\
    \n\nstruct primeSieve{\n    vector<long> mfactor;\n    //\u65E2\u77E5\u306E\u7D20\
    \u6570(\u968F\u6642\u8FFD\u52A0\u3055\u308C\u308B)\n    vector<long> primes;\n\
    \    set<long> primeSet;\n    long N;\n    primeSieve(){\n        N = 0;\n   \
    \     calc();\n    }\n    primeSieve(long N){\n        this-> N = N;\n       \
    \ calc();\n    }\n    /*\n    \u7D20\u6570\u7BE9\n    O(sqrt(N))\n    */\n   \
    \ void calc(){\n        primes.clear();\n        mfactor.resize(N+1);\n      \
    \  fill(mfactor.begin(),mfactor.end(),-1);\n        mfactor[0] = 0;\n        mfactor[1]\
    \ = 1;\n        for(long i=2;i<=N;i++){\n            if(mfactor[i] == -1){\n \
    \               for(long j=i;j<=N;j+=i){\n                    mfactor[j] = i;\n\
    \                }\n            }\n        }\n        for(long i=2;i<=N;i++){\n\
    \            if(mfactor[i] == i){\n                primes.push_back(i);\n    \
    \            primeSet.insert(i);\n            }\n        }\n    }\n    /*\n  \
    \  \u7D20\u6570\u5224\u5B9A\n    O(1)\n    */\n    bool isPrime(long x){\n   \
    \     if(x==1)return false;\n        if(x<=N) return x == mfactor[x];\n      \
    \  if(primeSet.count(x))return true;\n        return isPrimeNaive(x);\n    }\n\
    \    /*\n    Naive\u7D20\u6570\u5224\u5B9A\n    O(sqrt(N))\n    */\n    bool isPrimeNaive(long\
    \ x){\n        if(x<=1)return false;\n        for(long i=2;i*i<=x;i++){\n    \
    \        if(x%i==0){\n                return false;\n            }\n        }\n\
    \        primes.push_back(x);\n        primeSet.insert(x);\n        return true;\n\
    \    }\n    /*\n    \u7D20\u56E0\u6570\u5206\u89E3\n    O(log N)\n    */\n   \
    \ vector<long> factorization(long x){\n        if(x>N){\n            return factorizationNaive(x);\n\
    \        }\n        vector<long> A(0);\n        if(x==1){\n            A.push_back(1);\n\
    \            return A;\n        }\n        while(x>1){\n            A.push_back(mfactor[x]);\n\
    \            x /= mfactor[x];\n        }\n        reverse(A.begin(),A.end());\n\
    \        return A;\n    }\n    /*\n    Naive\u7D20\u56E0\u6570\u5206\u89E3\n \
    \   O(sqrt N)\n    */\n    vector<long> factorizationNaive(long x){\n        vector<long>\
    \ A(0);\n        for(long i=2;i*i<=x;){\n            if(x%i==0){\n           \
    \     x/=i;\n                A.push_back(i);\n            }else{\n           \
    \     i++;\n            }\n        }\n        if(x>1){\n            A.push_back(x);\n\
    \        }\n        return A;\n    }\n};\n#line 1 \"Math/Number-Theory/isprime.hpp\"\
    \nbool isPrime(long N){\n    if(N<=1)return false;\n    for(long i=2;i*i<=N;i++){\n\
    \        if(N%i==0){\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n#line 5 \"Math/Number-Theory/enum-prme.test.cpp\"\nusing namespace\
    \ std;\n\nbool verify(){\n    int N = 1000000;\n    primeSieve ps(N);\n    ps.calc();\n\
    \    for(int i=1;i<N;i++){\n        if(ps.isPrime(i) != isPrime(i)){\n       \
    \     return false;\n        }\n    }\n    return true;\n}\n\nint main(){\n  \
    \  // \u81EA\u524D\u30C6\u30B9\u30C8\u3092\u884C\u3046\n    cout << (verify()?\"\
    Hello World\": \"WA\") << endl;\n    return 0;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\
    # include <iostream>\n# include \"enum-prime.hpp\"\n# include \"isprime.hpp\"\n\
    using namespace std;\n\nbool verify(){\n    int N = 1000000;\n    primeSieve ps(N);\n\
    \    ps.calc();\n    for(int i=1;i<N;i++){\n        if(ps.isPrime(i) != isPrime(i)){\n\
    \            return false;\n        }\n    }\n    return true;\n}\n\nint main(){\n\
    \    // \u81EA\u524D\u30C6\u30B9\u30C8\u3092\u884C\u3046\n    cout << (verify()?\"\
    Hello World\": \"WA\") << endl;\n    return 0;\n}\n"
  dependsOn:
  - Math/Number-Theory/enum-prime.hpp
  - templete.hpp
  - Math/Number-Theory/isprime.hpp
  isVerificationFile: true
  path: Math/Number-Theory/enum-prme.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Number-Theory/enum-prme.test.cpp
layout: document
redirect_from:
- /verify/Math/Number-Theory/enum-prme.test.cpp
- /verify/Math/Number-Theory/enum-prme.test.cpp.html
title: Math/Number-Theory/enum-prme.test.cpp
---