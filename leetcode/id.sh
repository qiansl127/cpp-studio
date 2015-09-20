#!/bin/bash

DIR=`dirname "$0"`
DIR=`cd "${DIR}"; pwd`

find ${DIR} -name "*.cc" ! -name "template.cc" | xargs sed -n '/^* # /p' | awk '{print $3}' | sort -n
