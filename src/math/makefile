cc = g++
CFLAGS = -c
OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
targetName =../libs/libphymath.a
$(targetName):$(OBJS)
	ar crv -o $(targetName) $(OBJS)
$(OBJS): $(OBJS:%.o=%.cpp) $(OBJS:%.o=%.h)
	$(cc) $(CFLAGS) -o $(OBJS) $(OBJS:%.o=%.cpp)
clean:
	rm -f *.o




