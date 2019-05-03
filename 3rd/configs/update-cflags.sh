#!/bin/bash
tmpf="tmpf.log"
if [ -e "$tmpf" ];then
    rm -rf $tmpf
fi
touch $tmpf
echo `pkg-config --cflags glew` | awk '{for (i=1; i<=NF; i++) { print $i }}' |sed "s/\-I//" >> $tmpf
echo `pkg-config --cflags glfw3` | awk '{for (i=1; i<=NF; i++) { print $i }}' |sed "s/\-I//" >> $tmpf
echo `pkg-config --cflags glu` | awk '{for (i=1; i<=NF; i++) { print $i }}' |sed "s/\-I//" >> $tmpf
sort $tmpf |uniq > flags.log
rm $tmpf
if [ -z $PROJECT_DIR ]; then 
    echo "please source makesetup.sh"
fi

#pkg-config cannot find glu include
echo "$PROJECT_3RD/local/glu/include" >> flags.log

while read dirname
do
    if [ -z $CPLUS_INCLUDE_PATH ];then
        export CPLUS_INCLUDE_PATH=$dirname
    else
        export CPLUS_INCLUDE_PATH=$dirname:$CPLUS_INCLUDE_PATH
    fi
done < flags.log
export CPLUS_INCLUDE_PATH
