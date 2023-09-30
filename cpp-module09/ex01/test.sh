#!bin/bash

run_tests() {
    make

    ./RPN "5 6 +"
    ./RPN "7 2 /"
    ./RPN "3 5 8 * +"
    ./RPN "4 2 /"
    ./RPN "9 3 /"
    ./RPN "6 3 - 2 +"
    ./RPN "5 5 2 * +"
    ./RPN "9 4 5 + +"
    ./RPN "6 4 2 * -"
    ./RPN "8 5 3 * +"
    ./RPN "3 4 5 / -"
    ./RPN "5 6 7 * 8 / -"
    ./RPN "8 7 2 - *"
    ./RPN "4 3 6 * 2 / -"
    ./RPN "7 4 3 + *"
    ./RPN "1 5 /"
    ./RPN "4 5 6 + +"
    ./RPN "2 3 4 * 5 + +"
    ./RPN "1 2 3 * -"
    ./RPN "7 5 3 4 + + -"
    ./RPN "3 4 * 5 /"
    ./RPN "6 7 - 8 +"
    ./RPN "4 5 + 6 7 - *"
    ./RPN "9 8 7 / +"
    ./RPN "5 6 7 8 + + +"

    echo 
    echo "Running error cases..."
    echo

    #error case
    ./RPN "5 + -"
    ./RPN "+ 5 6 -"
    ./RPN "5 6 7 +"
    ./RPN "5 6 7 * + + -"
    ./RPN "5 6 / * -"
    ./RPN "/ 5 6 -"
    ./RPN "* 5 -"
    ./RPN "5 6 7 + + + -"
    ./RPN "7 8 - + -"
    ./RPN "4 * -"
    ./RPN "* 6 7 -"
    ./RPN "5 6 7 -"
    ./RPN "+ + 5 6 7 -"
    ./RPN "5 5 6 6 + +"
    ./RPN "8 9 10 + - * -"
    ./RPN "4 5 6 +"
    ./RPN "5 6 * + -"
    ./RPN "/ -"
    ./RPN "7 + 8 -"
    ./RPN "+ - * / -"
    ./RPN " 7 9 +"
    ./RPN "7 9 + "
    ./RPN ""
    ./RPN "1" "2" "+"
    ./RPN
    ./RPN 1 3 +
}

check_errors() {
    if [ $? -ne 0 ]; then
        echo "Error with input: $1"
    fi
}

make

run_tests
