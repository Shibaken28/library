---
title: Lowlink / グラフの関節点・橋の検出
documentation_of: ./lowlink.hpp
---

## 概要
lowlinkのアルゴリズムを使って、グラフの関節点・橋を検出します。

- グラフの関節点: ある頂点とその頂点から伸びる辺を削除したときに、グラフの連結成分が増える頂点
- グラフの橋: ある辺を削除したときに、グラフの連結成分が増える辺

## 計算量
頂点数$N$、辺数$M$として、$O(N+M)$
