.PHONY: clean tidy format cppcheck

CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC =	$(shell find . -name '*.cpp' -or -name '*.hpp')

SHELL := /bin/bash

tidy:
	@find . -name '*.cpp' -or -name '*.hpp' | while read file; do \
		if [[ $$file == ./cpp-module06/ex00/* ]]; then \
			clang-tidy $$file -- -Wall -Wextra -Werror -std=c++11; \
		else \
			clang-tidy $$file -- -Wall -Wextra -Werror -std=c++98; \
		fi \
	done

format:
	find . -name '*.cpp' -or -name '*.hpp' | xargs clang-format -i

cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --force --suppress=ctuOneDefinitionRuleViolation --suppress=duplInheritedMember --suppress=missingIncludeSystem --suppress=missingOverride --suppress=functionStatic:"./cpp-module04/*" --std=c++11 ./ 2> cppcheck.txt


clean:
	find . -name 'cppcheck.txt' -delete

