cc = g++
CFLAGS = -c
OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
targetName =../libs/libphymath.a
$(targetName):$(OBJS)
	ar crv -o $(targetName) $(OBJS)
#$(OBJS): $(OBJS:%.o=%.cpp) $(OBJS:%.o=%.h)
$(OBJS): %.o:%.cpp
	$(cc) $(CFLAGS) $< -o $@
clean:
	rm -f *.o




