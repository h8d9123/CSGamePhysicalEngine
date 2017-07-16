somedirs=./src/math
for tardir in $somedirs
do
	make -C $tardir
	make -C $tardir clean
done

