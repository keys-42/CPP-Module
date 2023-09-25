#!/bin/bash

# RESULT=./log/result.log
# ERROR=./log/error.log
# mkdir -p log

# make -C ..

# cp ../PmergeMe ./

# chmod +x PmergeMe

# ./PmergeMe $(python -c "import random; nums = range(1, 101); random.shuffle(nums); count = random.randint(1, 100); print(' '.join(str(nums[i]) for i in range(count)))") >> $RESULT 2>> $ERROR

# echo "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" >> $RESULT
# echo >> $RESULT
# echo "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" >> $ERROR
# echo >> $ERROR
# make clean


ERROR=./log/error.log
mkdir -p log

make -C ..

cp ../PmergeMe ./

chmod +x PmergeMe

./PmergeMe $(python -c "import random; nums = range(1, 101); random.shuffle(nums); count = random.randint(1, 100); print(' '.join(str(nums[i]) for i in range(count)))") 2>> $ERROR

echo "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
echo 
echo "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" >> $ERROR
echo >> $ERROR
make clean
