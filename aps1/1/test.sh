#!/bin/sh

search_dir=$(pwd)
g++ -std=c++2a $1 -o program.out
for entry in "$search_dir"/*.in
do
    filename=$(echo "$entry" | rev | cut -d"." -f2- | rev)
    name=$(echo "$entry" | rev | cut -d"/" -f1 | rev)
    echo "\033[1;32mTesting $name\033[0m\n"
    ./program.out < $entry > $filename.res
    diff "$filename.out" "$filename.res"
done
