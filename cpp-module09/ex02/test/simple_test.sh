#!/bin/bash

MIN=1
MAX=10000
INCREMENT=1

for ((i=$MIN; i<=$MAX; i+=INCREMENT)); do
    echo "count [100] length[$i] number[$i]"
    
    echo "bash test.sh -c 1 -l $i -n $i"
    bash test.sh -c 1 -l $i -n $i
    
    # Check the exit status of the last command (test.sh)
    if [ $? -ne 0 ]; then
        echo "test.sh failed for count [100] length[$i] number[$i]"
        exit 1
    fi
done

echo "finally"
echo "count [1] length[2147483647] number[777777]"
sleep 1
bash test.sh -c 1 -l 2147483647 -n 7777777

if [ $? -ne 0 ]; then
    echo "test.sh failed for count [1] length[2147483647] number[7777777]"
    exit 1
fi
