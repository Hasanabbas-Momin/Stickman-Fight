
File_main = src/main.cpp 
File1  = src/Window.cpp
File2 = src/Button.cpp
File3 = src/Mouse.cpp
File4 = src/Enemy.cpp
File5 = src/Game.cpp
File6 = src/leaderboard.cpp
File7 = src/hero.cpp
File8 = src/music.cpp

Stickman-Fight:
	g++ $(File_main)  $(File1)  $(File2) $(File3) $(File4) $(File5) $(File6) $(File7) $(File8) `pkg-config --cflags --libs sdl2` -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o Stickman-Fight

