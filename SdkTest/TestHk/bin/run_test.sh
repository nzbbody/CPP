#!/bin/sh
ulimit -c unlimited
PROXY_HOME=`dirname $0`
cd ${PROXY_HOME}
export LD_LIBRARY_PATH=./:${LD_LIBRARY_PATH}
./test

