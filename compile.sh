#!/bin/bash

SRC_DIR="src"
LIB_DIR="lib"
BIN_DIR="bin"
PROGNAME="Phonebook"

OUTPUT="$BIN_DIR/$PROGNAME"

CXX=g++
CXXFLAGS="-I$LIB_DIR -Wall -Wextra -std=c++17"


if [ "$1" == "DEBUG" ] || [ "$1" == "debug" ]; then 
    echo "Debug Mode"
    CXXFLAGS="$CXXFLAGS -DDEBUG"
fi 

mkdir -p $BIN_DIR

CPP_FILES=$(find $SRC_DIR -type f -name "*.cpp")

echo "Compiling..."

$CXX $CXXFLAGS $CPP_FILES -o $OUTPUT

if [ $? -eq 0 ]; then
    echo "Compilation successful."
    echo "Running $PROGNAME"
    echo ""
    echo ""

    cd $BIN_DIR
    ./$PROGNAME
else
    echo "Compilation failed."
fi
