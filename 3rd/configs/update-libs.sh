#!/bin/bash
tmpf="tmpf.log"
if [ -e "$tmpf" ];then
    rm -rf $tmpf
fi
touch $tmpf
echo `pkg-config --libs-only-L glew` | awk '{for (i=1; i<=NF; i++) { print $i }}' |sed "s/\-L//" >> $tmpf
echo `pkg-config --libs-only-L glfw3` | awk '{for (i=1; i<=NF; i++) { print $i }}' |sed "s/\-L//" >> $tmpf
echo `pkg-config --libs-only-L glu` | awk '{for (i=1; i<=NF; i++) { print $i }}' |sed "s/\-L//" >> $tmpf
sort $tmpf |uniq > libsdir.log
rm $tmpf
if [ -z $PROJECT_LIBS ]; then 
    echo "please source makesetup.sh"
fi
while read dirname
do
    cp $dirname/lib* $PROJECT_LIBS
done < libsdir.log
