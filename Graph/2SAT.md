---
title: 2-SAT / 充足可能性問題
documentation_of: ./2SAT.hpp
---

## 概要
2-Satisfiability Problem (2-SAT) を解きます。論理式を満たす変数の割当が存在する場合、その一つを求めます。

## 使い方
- `TwoSAT(N)` : 変数の数$N$を指定して初期化します。
- `add_clause(i, f, j, g)` : 論理式$(x_i=f) \lor (x_j=g)$を追加します。
    - 例えば、$(x_1 \lor x_2)$を追加するには`add_clause(1, true, 2, true)`とします。
    - $(x_1 \lor \lnot x_2)$を追加するには`add_clause(1, true, 2, false)`とします。
- `satisfiable()` : 論理式を満たす変数の割当が存在するかを判定します。
    - 存在する場合は、`ans`に割当が格納されます。


## 計算量
変数の数を$N$、節の数を$M$として、$O(N+M)$

## 2-SAT とは
論理式が与えられたとき、その論理式を満たす変数の割当が存在するかを判定する問題です。論理積($\land$)、論理和($\lor$)、否定($\lnot$)のみから構成され、
- 論理和と否定のみからなる論理式を節(clause)と呼びます。
- 2-SATは、節が2つの論理式のみで、その積で表される論理式を考えます。
    - 例えば、$(x_1 \lor x_2) \land (\lnot x_1 \lor x_3) \land (\lnot x_2 \lor \lnot x_3)$は2-SATです。
    - 一方、$(x_1 \lor x_2) \land (\lnot x_1 \lor x_2 \lor x_3)$は2-SATではありません。
    - $(x_1) \land (\lnot x_1 \lor x_2)$は、$(x_1 \lor x_1) \land (\lnot x_1 \lor x_2)$と同値なので、2-SATに帰着できます。
- 2-SATは、論理式を満たす変数の割当が存在するかを判定する問題です。

