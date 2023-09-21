all:
	bash test.sh -n 3000 -c 10

clean:
	rm -f PmergeMe

fclean:clean
	make fclean -C ../
	rm -rf ./log
	

p:
	make pair -C ..
 
s:
	make separate -C ..

f:
	make first -C ..

sort:
	make sort -C ..

re:
	make re -C ..

i:
	bash infinity.sh