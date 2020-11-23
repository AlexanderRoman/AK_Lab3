.PHONY: build

build:
	g++ ./main.cpp -o parseApp

default_goal: build def
.PHONY: def
def:
	./parseApp -m --help -v --value=100

.PHONY: run

run:
	./parseApp -m


.DEFAULT_GOAL:=default_goal
