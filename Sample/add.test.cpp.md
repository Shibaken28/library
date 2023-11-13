---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Sample/add.hpp
    title: "Sample / \u8DB3\u3057\u7B97\u306E\u30B5\u30F3\u30D7\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Sample/add.test.cpp\"\n# define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n# include <iostream>\n#line 1 \"Sample/add.hpp\"\nint sum(int a, int b){\n \
    \   return a + b;\n}\n#line 4 \"Sample/add.test.cpp\"\nusing namespace std;\n\n\
    int main(){\n    int a, b;\n    cin >> a >> b;\n    cout << sum(a, b) << endl;\n\
    }\n"
  code: "# define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n# include <iostream>\n\
    # include \"add.hpp\"\nusing namespace std;\n\nint main(){\n    int a, b;\n  \
    \  cin >> a >> b;\n    cout << sum(a, b) << endl;\n}\n"
  dependsOn:
  - Sample/add.hpp
  isVerificationFile: true
  path: Sample/add.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 11:25:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Sample/add.test.cpp
layout: document
redirect_from:
- /verify/Sample/add.test.cpp
- /verify/Sample/add.test.cpp.html
title: Sample/add.test.cpp
---
