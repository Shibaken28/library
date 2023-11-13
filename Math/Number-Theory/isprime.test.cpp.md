---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/isprime.hpp
    title: "is prime / \u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja
  bundledCode: "#line 1 \"Math/Number-Theory/isprime.test.cpp\"\n# define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja\"\
    \n\n# include <iostream>\n#line 1 \"Math/Number-Theory/isprime.hpp\"\nbool isPrime(long\
    \ N){\n    if(N<=1)return false;\n    for(long i=2;i*i<=N;i++){\n        if(N%i==0){\n\
    \            return false;\n        }\n    }\n    return true;\n}\n#line 5 \"\
    Math/Number-Theory/isprime.test.cpp\"\nusing namespace std;\n\nint main(){\n \
    \   int n;cin>>n;\n    int ans=0;\n    for(int i=0;i<n;i++){\n        int x;cin>>x;\n\
    \        if(isPrime(x))ans++;\n    }\n    cout<<ans<<endl;\n}\n\n"
  code: "# define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja\"\
    \n\n# include <iostream>\n# include \"isprime.hpp\"\nusing namespace std;\n\n\
    int main(){\n    int n;cin>>n;\n    int ans=0;\n    for(int i=0;i<n;i++){\n  \
    \      int x;cin>>x;\n        if(isPrime(x))ans++;\n    }\n    cout<<ans<<endl;\n\
    }\n\n"
  dependsOn:
  - Math/Number-Theory/isprime.hpp
  isVerificationFile: true
  path: Math/Number-Theory/isprime.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Number-Theory/isprime.test.cpp
layout: document
redirect_from:
- /verify/Math/Number-Theory/isprime.test.cpp
- /verify/Math/Number-Theory/isprime.test.cpp.html
title: Math/Number-Theory/isprime.test.cpp
---
