#!/bin/bash

echo "## Problems" > README.md
grep -irh "PROBLEM: " src/* | sed 's/\/\/ PROBLEM: /- /g' | sort >> README.md
