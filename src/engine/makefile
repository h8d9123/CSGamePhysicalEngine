MINGW_PATH:=$(MINGW_HOME)/$(MINGW_PLATFORM)
MINGW_INCLUDE:=$(MINGW_PATH)/include
MINGW_GL_INCLUDE:=$(MINGW_PATH)/include/GL
MINGW_LIBS:=$(MINGW_PATH)/lib32
OBJS=csengine
CC=$(MINGW_HOME)/bin/g++
INC=-I$(MINGW_GL_INCLUDE) \
	-I$(PROJECT_DIR)/3rd/local/windows/include \
	-I$(PROJECT_DIR)/3rd/stb \
	-I$(PROJECT_DIR)/3rd/local/windows/glew/include \
	-I.

LIBS=-L$(PROJECT_DIR)/3rd/local/windows/glew/lib \
-L$(PROJECT_DIR)/3rd/local/windows/glfw/src

SRC=$(wildcard *.cpp)
.PHONY:all
all:$(OBJS)
	@echo "Compiled Successfully!"
csengine: $(SRC)
	$(CC) $(INC) $(LIBS) -o $(PROJECT_BIN)/$@ $^ -lglew32 -lglfw3 -lopengl32

.PHONY: clean
clean:
	rm -rf $(addsuffix .exe, $(OBJS))
