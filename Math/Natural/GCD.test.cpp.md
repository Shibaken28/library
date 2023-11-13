---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Natural/GCD.hpp
    title: Math/Natural/GCD.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
  bundledCode: "#line 1 \"Math/Natural/GCD.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B\"\
    \n\n# include <iostream>\n#line 1 \"Math/Natural/GCD.hpp\"\n# include <vector>\n\
    using namespace std;\n\nlong GCD(long a,long b){\n    if(a<b)return GCD(b,a);\n\
    \    if(b==0)return a;\n    return GCD(b,a%b);\n}\n\nlong GCD(vector<long>&A){\n\
    \    long gcd = A.front();\n    for(auto&a:A)gcd = GCD(gcd,a);\n    return gcd;\n\
    }\n\nlong LCM(long a,long b){\n    return (a/GCD(a,b))*b;\n}\n\n\nlong LCM(vector<long>&A){\n\
    \    long lcm = 1;\n    for(auto&a:A)lcm = LCM(lcm,a);\n    return lcm;\n}\n\n\
    #line 5 \"Math/Natural/GCD.test.cpp\"\nusing namespace std;\n\nint main(){\n \
    \   int x, y;\n    cin>>x>>y;\n    cout<<GCD(x,y)<<endl;\n}\n\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B\"\
    \n\n# include <iostream>\n# include \"GCD.hpp\"\nusing namespace std;\n\nint main(){\n\
    \    int x, y;\n    cin>>x>>y;\n    cout<<GCD(x,y)<<endl;\n}\n\n"
  dependsOn:
  - Math/Natural/GCD.hpp
  isVerificationFile: true
  path: Math/Natural/GCD.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 12:17:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Natural/GCD.test.cpp
layout: document
redirect_from:
- /verify/Math/Natural/GCD.test.cpp
- /verify/Math/Natural/GCD.test.cpp.html
title: Math/Natural/GCD.test.cpp
---
