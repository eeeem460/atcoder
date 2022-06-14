#!/bin/bash

if [ -z "$1" ]; then
    echo "directory name not found"
fi

cp -r ~/atcoder/src/ABC ~/atcoder/src/$1

code ~/atcoder/src/$1/*