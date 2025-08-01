# Compiler information
CC := g++

# Path information
BIN_PATH := bin
INCLUDE_PATH := include
TESTS_PATH := tests

# Files information
INCLUDE_FILES := $(wildcard ${INCLUDE_PATH}/*/*.h)
TESTS_FILES := $(wildcard ${TESTS_PATH}/*.cpp)
BIN_FILES := $(patsubst ${TESTS_PATH}/%.cpp,${BIN_PATH}/%,${TESTS_FILES})

tests: ${BIN_PATH} ${BIN_FILES}
	@echo tests build

${BIN_PATH}:
	mkdir -p ${BIN_PATH}

${BIN_PATH}/%: ${TESTS_PATH}/%.cpp ${INCLUDE_FILES}
	${CC} -I${INCLUDE_PATH} -o $@ $<

clean:
	rm -rf ${BIN_PATH}

.PHONY: clean
