#!/bin/bash
find . -name "*.cc" ! -name "template.cc" | xargs sed -n '/^* # /p' | awk '{print $3}' | sort -n
