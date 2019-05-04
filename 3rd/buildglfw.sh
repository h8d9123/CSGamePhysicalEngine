#!/bin/bash
if [ $OS_NAME = "CentOS" ];then
    sudo yum install libXrandr libXrandr-devel
    sudo yum install libXinerama libXinerama-devel
    sudo yum install libXcursor libXcursor-devel
fi

if [ $OS_NAME = "Ubuntu" ];then
    sudo apt-get -y install xorg-dev
fi
if [ -z $1 ];then
    echo "ERROR: GLFW name show be given."
    exit -1
fi
GLFW_NAME=$1 
LOCAL_GLFW_PATH=`pwd`/$GLFW_NAME
export GLFW_DEST=${PROJECT_3RD}/local/glfw
export GLFW_PREFIX=$GLFW_DEST
cd $LOCAL_GLFW_PATH
mkdir glfw-release
cd ./glfw-release
echo `pwd`
cmake -DCMAKE_INSTALL_PREFIX=$GLFW_PREFIX ..
make && make install
