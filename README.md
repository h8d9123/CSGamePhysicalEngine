# CSGamePhysicalEngine
physical engine 
1.config glew
   1)install dependency
    sudo yum install libXmu-devel libXi-devel libGL-devel
   2)make
    make;sudo make intall;make clean;
2.config glfw
    1)install depdency for x11 (if need)
    sudo yum install libXrandr libXrandr-devel
    sudo yum install libXinerama libXinerama-devel
    sudo yum install libXcursor libXcursor-devel
    2) build(in glfw-root)
    mkdir build
    cd build
    cmake ..
    make 
    sudo make install
    3)result
    Installing: /usr/local/include/GLFW
    -- Up-to-date: /usr/local/include/GLFW/glfw3.h
    -- Up-to-date: /usr/local/lib/cmake/glfw3/glfw3Config.cmake
    -- Up-to-date: /usr/local/lib/cmake/glfw3/glfw3ConfigVersion.cmake
    -- Up-to-date: /usr/local/lib/cmake/glfw3/glfw3Targets.cmake
    -- Up-to-date: /usr/local/lib/cmake/glfw3/glfw3Targets-noconfig.cmake
    -- Up-to-date: /usr/local/lib/pkgconfig/glfw3.pc
    -- Up-to-date: /usr/local/lib/libglfw3.a
3.using glfw
    cc flags for glfw:
        `pkg-config --cflags glfw3` `pkg-config --static --libs glfw3`
    cc flags for opengl:
        -lGL
    eg. 
        g++ main2.cpp `pkg-config --cflags glfw3` `pkg-config --static --libs glfw3` -lGL
4.install glu
    ./configure;make;sudo make install
5.install glut
    sudo yum install freeglut freeglut-devel
