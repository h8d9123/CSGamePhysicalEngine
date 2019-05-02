#!/bin/bash
pwd_dir=`pwd`
export PROJECT_DIR=`echo ${pwd_dir}| sed -e "s/\(.*CSGamePhysicalEngine\).*/\1/"`
export PROJECT_BIN=${PROJECT_DIR}/bin
export PROJECT_LIBS=${PROJECT_DIR}/libs
export PROJECT_TEST=${PROJECT_DIR}/test 
export PROJECT_3RD=${PROJECT_DIR}/3rd
export PKG_CONFIG_PATH=/usr/lib/pkgconfig:/usr/local/lib/pkgconfig
