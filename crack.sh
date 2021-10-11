#!/bin/bash

for ((i=1;i<=999999999;i++))
do
    unzip -q -o -P $i wang.zip
    if [ $? -eq 0 ]; then
        echo "succeed $i"
        break
    fi
done
