#!/usr/bin/env bash

dirname=$(dirname "$0")
test_runner="$dirname/42Tester"
clear
echo "Running 42 Tester"
echo "File::$@"
echo
eval $(echo "$test_runner $dirname $@")
echo

