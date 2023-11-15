#!/bin/bash

# クリップボードにincludeを展開したコードをコピーする
# oj-bundle hoge.cpp | iconv -t sjis | clip.exe
# でできる

if [ $# -ne 1 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

oj-bundle $1 | clip.exe
oj-bundle $1 > random.cpp
make random
