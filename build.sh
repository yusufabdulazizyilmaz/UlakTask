#!/bin/bash
mkdir -p build
cd build/
cmake ..
make
alias cli="./cli"
