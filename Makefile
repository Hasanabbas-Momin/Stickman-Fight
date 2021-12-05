
File_main = src/main.cpp 
File1  = src/Window.cpp
File2 = src/Button.cpp

Stickman-Fight:
	g++ $(File_main)  $(File1)  $(File2) `pkg-config --cflags --libs sdl2` -lSDL2_image -o bin/Stickman-Fight