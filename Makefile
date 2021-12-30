
File_main = src/main.cpp 
File1  = src/Window.cpp
File2 = src/Button.cpp
File3 = src/Mouse.cpp
File4 = src/leaderboard.cpp
File5 = src/Hero.cpp
File6 = src/Enemy.cpp

Stickman-Fight:
	g++ $(File_main)  $(File1)  $(File2) $(File3) $(File4) $(File5) $(File6) `pkg-config --cflags --libs sdl2` -lSDL2_image -lSDL2_ttf -o bin/Stickman-Fight
