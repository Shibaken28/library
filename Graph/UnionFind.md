---
title: UnionFind
documentation_of: ./UnionFind.hpp
---

## 概要
頂点のマージ、連結判定を高速に行うデータ構造です

## 使い方
- `unite(u,v)` : 頂点`u`と頂点`v`を同じ集合にする
- `same(u,v)` : 頂点`u`と頂点`v`が同じ集合に属するか判定する
- `getGroups()` : 集合ごとに分けた頂点のリストを返す
- `getWeight(u)` : 頂点`u`が属する集合の重みを返す
- `changeWeight(u)` : 頂点`u`の重みを変更する
