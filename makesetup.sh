#!/bin/bash
pwd_dir=`pwd`
export OS_NAME=`lsb_release -i |awk '{print $3}'`
export OS_RELEASE=`lsb_release -r |awk '{print $2}'`

export PROJECT_DIR=`echo ${pwd_dir}| sed -e "s/\(.*CSGamePhysicalEngine\).*/\1/"`
export PROJECT_BIN=${PROJECT_DIR}/bin
export PROJECT_LIBS=${PROJECT_DIR}/libs
export PROJECT_TEST=${PROJECT_DIR}/test 
export PROJECT_3RD=${PROJECT_DIR}/3rd

#update pkg-config
source $PROJECT_3RD/configs/update-pkg-config.sh
if [ $PKG_CONFIG_PATH ];then
    export PKG_CONFIG_PATH=$PROJECT_3RD/configs:$PKG_CONFIG_PATH
else
    export PKG_CONFIG_PATH=$PROJECT_3RD/configs
fi

if [ $LD_LIBRARY_PATH ];then
    export LD_LIBRARY_PATH=$PROJECT_LIBS:$LD_LIBRARY_PATH
else
    export LD_LIBRARY_PATH=$PROJECT_LIBS
fi

#add include-dir for g++
#update CPLUS_INCLUDE_PATH
source $PROJECT_3RD/configs/update-cflags.sh
export CPLUS_INCLUDE_PATH

#dump env
echo "PROJECT_DIR=$PROJECT_DIR"
echo "LD_LIBRARY_PATH=$LD_LIBRARY_PATH"
echo "CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH"
