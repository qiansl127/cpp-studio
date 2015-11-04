#!/bin/bash

DIR=`dirname "$0"`
DIR=`cd "${DIR}"; pwd`

for file in `find ${DIR} -name "*.cc" ! -name "template.cc"`
do
  sed -n '2,3p' $file | sed 'N;s/\n/ /' | sed 's/* //g'
done | sort -n -k 2
