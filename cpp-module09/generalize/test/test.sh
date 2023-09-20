#!/bin/bash

mkdir -p log

make -C ..

cp ../PmergeMe ./

chmod +x PmergeMe

count=1
length=2147483647
number=10

while getopts "l:c:n:" opt; do
    case $opt in
    l)
        length=$OPTARG
        ;;
    c)
        count=$OPTARG
        ;;
    n)
        number=$OPTARG
        ;;
    *)
        echo "Usage: $0 [-l length] [-c count] [-n number]"
        exit 1
        ;;
    esac
done

for ((i=1; i<=count; i++)); do
    numbers=$(python3 -c "import random; print(' '.join(str(random.randint(1, $length)) for _ in range($number)))")
    ./PmergeMe $numbers | grep after >sorted.log
    sorted_numbers=$(echo "$numbers" | tr ' ' '\n' | sort -n | tr '\n' ' ')
    echo "after:" $sorted_numbers"" > sorted_test.log
    diff sorted_test.log sorted.log > /dev/null
    if [ $? -eq 0 ]; then
        echo $numbers
        echo -e "\e[32mOK\e[0m"
    else
        echo -e "\e[31mNO\e[0m"
        break
    fi
done


echo "-------------------------------------------------------------------------------------------------------------------------------"
echo 
make clean
