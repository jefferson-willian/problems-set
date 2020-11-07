#!/bin/bash

export GITHUB_PATH="https://github.com/jefferson-willian/problems-set/tree/master/leetcode/"

echo "## Problems" > README.md
grep -ir "PROBLEM: " src/* | awk -v var=$GITHUB_PATH -F':// PROBLEM: ' '{print "- " $2 " | [solution](" var $1 ")"}' | sort >> README.md
