build/debug.out: lab1.cpp Rect.cpp Barrel.cpp
	g++ -g -o build/debug.out lab1.cpp Rect.cpp Barrel.cpp
debug: build/debug.out
	gdb build/debug.out