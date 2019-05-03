#!/bin/bash
if [ $OS_NAME = "CentOS" ];then
    suod yum-builddep mesa
fi
if [ $OS_NAME = "Ubuntu" ];then
    apt-get build-dep mesa
fi
#SCONS_PATH=/usr/local/bin
#cd mesa-19.0.0 
#$SCONS_PATH/scons


