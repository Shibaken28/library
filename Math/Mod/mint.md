---
title: modint / modint構造体
documentation_of: ./mint.hpp
---

## 概要
$\pmod{m}$の世界での四則演算を行う構造体です

[参考](https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/modint.cpp)

[実行時に法が決まるやつ](https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/modint_runtime.cpp)

## 制約
- 逆元が存在しない場合に割り算をするとバグります
- 実行する前に法を決めておく必要があります

## 使い方
`using`で`mint`を定義すると使いやすいです

```cpp
using mint = Fp<11>;

int main(){
    mint a = 5;
    mint b = 9;
    mint c = a + b;
    cout << c << endl; // 3
}
```
