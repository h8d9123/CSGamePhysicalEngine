MINGW_PATH:=/c/mingw-w64/x86_64-8.1.0-posix-sjlj-rt_v6-rev0/mingw64/x86_64-w64-mingw32
PROJECT_DIR:=/c/mytemp/gitwork/CSGamePhysicalEngine
MINGW_INCLUDE:=$(MINGW_PATH)/include
MINGW_GL_INCLUDE:=$(MINGW_PATH)/include/GL
MINGW_LIBS:=$(MINGW_PATH)/lib32
OBJS=main main2 main3
CC=/c/mingw-w64/x86_64-8.1.0-posix-sjlj-rt_v6-rev0/mingw64/bin/g++
INC=-I$(MINGW_GL_INCLUDE) \
	-I$(PROJECT_DIR)/3rd/local/windows/include \
	-I$(PROJECT_DIR)/3rd/local/windows/glew/include

LIBS=-L$(PROJECT_DIR)/3rd/local/windows/glew/lib \
-L$(PROJECT_DIR)/3rd/local/windows/glfw/src

.PHONY:all
all:$(OBJS)
	@echo "Compiled Successfully!"
main: main.cpp
	$(CC) $(INC) $(LIBS) -o $@ $^ -lglfw3 -lopengl32
main2: main2.cpp
	$(CC) $(INC) $(LIBS) -o $@ $^ -lglfw3 -lopengl32
main3: main3.cpp
	$(CC) $(INC) $(LIBS) -o $@ $^ -lglew32 -lglfw3 -lopengl32

.PHONY: clean
clean:
	rm -rf $(addsuffix .exe, $(OBJS))
