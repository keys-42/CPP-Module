#!/bin/bash

mkdir -p log

make re -C ..

cp ../PmergeMe ./

chmod +x PmergeMe

COUNTER=0
LIMIT=300

while [ $COUNTER -lt $LIMIT ]; do
    OUTPUT=$(./PmergeMe $(python3 -c "import random; nums = list(range(1, 101)); random.shuffle(nums); count = random.randint(1, 100); print(' '.join(str(nums[i]) for i in range(count)))"))

    echo "$OUTPUT"

    echo "$OUTPUT" | grep -q "Yes"
    if [ $? -ne 0 ]; then
        std::cout "\033[31mnumbers is sorted: NONONONONO\033[0m"
        break
    fi
    # echo "$OUTPUT" | grep -q "Lists are equal."

    # if [ $? -ne 0 ]; then
    #     std::cout "\033[31Lists are notnotnotnot equal.\033[0m"
    #     break
    # fi
        COUNTER=$((COUNTER+1))
done;

if [ $COUNTER -eq $LIMIT ]; then
    echo "Fantastic! You completed 300 trials successfully!"
else
    echo "Seriously? That's all you've got? I've seen calculators from the '80s do better!"
fi