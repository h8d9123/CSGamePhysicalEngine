#g++ main.cpp `pkg-config --cflags --libs glew` `pkg-config --libs glew` `pkg-config --cflags glfw3` `pkg-config --static --libs glfw3` -lGL -lGLEW
cc=g++
cflags=`pkg-config --cflags --libs glew` `pkg-config --libs glew` `pkg-config --cflags glfw3` `pkg-config --static --libs glfw3` -lGL -lGLEW
obj=csengine
${obj}:main.cpp
	${cc} $< -o ${PROJECT_BIN}/${@} ${cflags}
