#!/bin/bash
if [ -z $1 ];then
    echo "ERROR: GLU name show be given."
    exit -1
fi
GLU_NAME=$1 
LOCAL_GLU_PATH=`pwd`/$GLU_NAME
export GLU_DEST=${PROJECT_3RD}/local/glu
export GLU_PREFIX=$GLU_DEST
cd $LOCAL_GLU_PATH
./configure --prefix $GLU_PREFIX
make && make install
