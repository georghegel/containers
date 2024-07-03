rwildcard = $(foreach d, $(wildcard $(1:=/*)), $(call rwildcard,$d,$2) $(filter $(subst *,%,$2), $d))

.PHONY: clean s21_containers.a gcov_report test
all: clean

test: clean
	@rm -rf build
	@mkdir build
	@cd build && cmake ../ && make && ./containers

leaks: test
	@cd build && leaks -atExit -- ./containers

clean:
	@rm -rf ./build
