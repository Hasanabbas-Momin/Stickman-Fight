# game: game.cpp Ghost.cpp main.cpp SinGhost.cpp Player.cpp
# 	g++ -o  play game.cpp Ghost.cpp main.cpp SinGhost.cpp Player.cpp `pkg-config --cflags --libs sdl2` -lSDL2_image
Stickman-Fight:
	g++ main.cpp `pkg-config --cflags --libs sdl2` -lSDL2_image -o Stickman-Fight