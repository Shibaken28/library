---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/prime-factorize.hpp
    title: "prime factorize/ \u7D20\u56E0\u6570\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"Math/Number-Theory/prime-factorize.test.cpp\"\n# define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n# include <iostream>\n#line 1 \"Math/Number-Theory/prime-factorize.hpp\"\n#\
    \ include <vector>\nusing namespace std;\n\n//\u7D20\u56E0\u6570\u5206\u89E3\n\
    vector<long> factor(long x){\n    vector<long> f(0);\n    for(long i=2;i*i<=x;i++){\n\
    \        if(x%i==0){\n            f.push_back(i);\n            x/=i;\n       \
    \     i--;\n        }\n    }\n    if(x>1)f.push_back(x);\n    return f;\n}\n\n\
    //\u7D20\u56E0\u6570\u5206\u89E32\n// (\u7D20\u6570,\u6307\u6570) \u306Epair\n\
    vector<pair<long,long>> factor2(long x){\n    auto f = factor(x);\n    vector<pair<long,long>>\
    \ f2(0);\n    for(auto a:f){\n        if(f2.empty()){\n            f2.push_back({a,1});\n\
    \        }else if(f2.back().first==a){\n            f2.back().second ++;\n   \
    \     }else{\n            f2.push_back({a,1});\n        }\n    }\n    return f2;\n\
    }\n#line 4 \"Math/Number-Theory/prime-factorize.test.cpp\"\n\nusing namespace\
    \ std;\n\n\nint main(){\n    int n; cin>>n;\n    auto f = factor(n);\n    cout\
    \ << n << \":\";\n    for(auto a:f){\n        cout << \" \" << a;\n    }\n   \
    \ cout << endl;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n# include <iostream>\n# include \"prime-factorize.hpp\"\n\nusing namespace std;\n\
    \n\nint main(){\n    int n; cin>>n;\n    auto f = factor(n);\n    cout << n <<\
    \ \":\";\n    for(auto a:f){\n        cout << \" \" << a;\n    }\n    cout <<\
    \ endl;\n}\n"
  dependsOn:
  - Math/Number-Theory/prime-factorize.hpp
  isVerificationFile: true
  path: Math/Number-Theory/prime-factorize.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Number-Theory/prime-factorize.test.cpp
layout: document
redirect_from:
- /verify/Math/Number-Theory/prime-factorize.test.cpp
- /verify/Math/Number-Theory/prime-factorize.test.cpp.html
title: Math/Number-Theory/prime-factorize.test.cpp
---
