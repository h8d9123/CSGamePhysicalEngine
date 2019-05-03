#!/bin/bash
pwd_dir=`pwd`
cd $PROJECT_3RD/configs
find $PROJECT_3RD/local -iname "*.pc"|xargs -n 1 ln -sf 
cd $pwd_dir
