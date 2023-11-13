---
title: Bellman-Ford algorithm / ベルマンフォード法による最短経
documentation_of: ./Bellman-Ford.hpp
---

## 概要
グラフで、ある頂点から各頂点への最短経路を求めます。重みが負の辺があっても動作します。始点から到達可能な負閉路がある場合は、その旨を報告します。

## 計算量
頂点数$N$、辺数$M$として、$O(NM)$
