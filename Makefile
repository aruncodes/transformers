OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw3
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB) -lXrandr -lXi -lm -lXxf86vm -lX11 -lpthread -lrt
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include

BIN=transformer
SRCS=main.cpp gl_framework.cpp texture.cpp blocks.cpp keycontrols.cpp robot.cpp  animate.cpp world.cpp
INCLUDES=gl_framework.hpp texture.hpp blocks.hpp keycontrols.hpp robot.hpp world.hpp



all: $(BIN)


$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(BIN)
	rm -f *.o
	rm -f *~
	
