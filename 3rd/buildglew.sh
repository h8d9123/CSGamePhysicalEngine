#!/bin/bash
if [ -z $1 ];then
    echo "ERROR: GLEW name show be given."
    exit -1
fi
GLEW_NAME=$1 
LOCAL_GLEW_PATH=`pwd`/$GLEW_NAME
export GLEW_DEST=${PROJECT_3RD}/local/glew
export GLEW_PREFIX=$GLEW_DEST
cd $LOCAL_GLEW_PATH
make && make install
