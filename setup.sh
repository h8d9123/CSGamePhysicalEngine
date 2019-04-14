#!/bin/bash
pwd_dir=`pwd`
export PROJECT_DIR=`echo ${pwd_dir}| sed -e "s/\(.*CSGamePhysicalEngine\).*/\1/"`
export PROJECT_BIN=${PROJECT_DIR}/bin
