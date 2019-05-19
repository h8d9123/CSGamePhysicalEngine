#!/bin/bash
pwd_dir=`pwd`
export OS_NAME=`lsb_release -i |awk '{print $3}'`
export OS_RELEASE=`lsb_release -r |awk '{print $2}'`
if [ $OS = "Windows_NT" ];then
    MINGW_HOME=/c/mingw-w64/x86_64-8.1.0-posix-sjlj-rt_v6-rev0/mingw64
    MINGW_PLATFORM=x86_64-w64-mingw32
    PATH=/c/Program\ Files/CMake/bin:$PATH
    PATH=$MINGW_HOME/bin/:$PATH
    export MINGW_HOME
    export MINGW_PLATFORM
    export OS_NAME="Windows_NT"
    export MINGW_MAKE=`which mingw32-make`
fi
export PROJECT_DIR=`echo ${pwd_dir}| sed -e "s/\(.*CSGamePhysicalEngine\).*/\1/"`
export PROJECT_BIN=${PROJECT_DIR}/bin
export PROJECT_LIBS=${PROJECT_DIR}/libs
export PROJECT_TEST=${PROJECT_DIR}/test 
export PROJECT_3RD=${PROJECT_DIR}/3rd

if [ $OS != "Windows_NT" ];then
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
fi

#dump env
echo "PROJECT_DIR=$PROJECT_DIR"
if [ $OS != "Windows_NT" ];then
    echo "LD_LIBRARY_PATH=$LD_LIBRARY_PATH"
    echo "CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH"
else
    echo "MINGW_HOME=$MINGW_HOME"
    echo "MINGW_PLATFORM=$MINGW_PLATFORM"
fi

