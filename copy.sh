#!/bin/bash

# クリップボードにincludeを展開したコードをコピーする
# oj-bundle hoge.cpp | iconv -t sjis | clip.exe
# でできる

if [ $# -ne 1 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

oj-bundle $1 | iconv -t sjis | clip.exe
# define PROBLEMがある行を削除してrandom.cppに出力
oj-bundle $1 | sed -e '/define PROBLEM/d' > random.cpp
make random
