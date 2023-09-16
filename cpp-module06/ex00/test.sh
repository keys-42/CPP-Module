#!/bin/bash

check_impossible() {
    local num=$1

    result=$(./convert "$num" | grep "char")

    if echo "$result" | grep -q "impossible"; then
        echo -e "\033[0;32m$num: The output contains 'impossible'\033[0m"
    else
        echo -e "\033[0;31m$num: The output does not contain 'impossible'\033[0m"
    fi
}

for ((i=-2147483649; i<=-2147483640; i++)); do
    check_impossible "$i"
done

sleep 1

for ((i=-30; i<=-1; i++)); do
    check_impossible "$i"
done

sleep 1

for ((i=128; i<=150; i++)); do
    check_impossible "$i"
done

sleep 1

for ((i=2147483648; i<=2147483650; i++)); do
    check_impossible "$i"
done