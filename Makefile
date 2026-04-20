build/debug.out: src/lab1.cpp build/Rect.o build/Barrel.o build/My_string.o build/Text_wrapper.o build/Matrix.o
	g++ -g -o build/debug.out src/lab1.cpp src/Rect.cpp src/Barrel.cpp src/Text_wrapper.cpp src/Matrix.cpp src/My_string.cpp
debug: build/debug.out
	gdb build/debug.out
build/Rect.o: src/Rect.cpp src/Rect.hpp
	g++ -g -c -o build/Rect.o src/Rect.cpp
build/Barrel.o: src/Barrel.cpp src/Barrel.hpp
	g++ -g -c -o build/Barrel.o src/Barrel.cpp
build/My_string.o: src/My_string.cpp src/My_string.hpp
	g++ -g -c -o build/My_string.o src/My_string.cpp
build/Matrix.o: src/Matrix.cpp src/Matrix.hpp
	g++ -g -c -o build/Matrix.o src/Matrix.cpp
build/Text_wrapper.o: src/Text_wrapper.cpp src/Text_wrapper.hpp
	g++ -g -c -o build/Text_wrapper.o src/Text_wrapper.cpp


test: build/test_rect_basic.out build/test_rect_props.out build/test_rect_ops.out build/test_bounding.out
	./build/test_rect_basic.out
	./build/test_rect_props.out
	./build/test_rect_ops.out
	./build/test_bounding.out
	@echo "tests passed\n"

build/test_rect_basic.out: tests/test_rect_basic_methods.cpp build/Rect.o
	g++ -g -o build/test_rect_basic.out tests/test_rect_basic_methods.cpp build/Rect.o
build/test_rect_props.out: tests/test_rect_properties.cpp build/Rect.o
	g++ -g -o build/test_rect_props.out tests/test_rect_properties.cpp build/Rect.o
build/test_rect_ops.out: tests/test_rect_operations.cpp build/Rect.o
	g++ -g -o build/test_rect_ops.out tests/test_rect_operations.cpp build/Rect.o
build/test_bounding.out: tests/test_bounding_rect.cpp build/Rect.o
	g++ -g -o build/test_bounding.out tests/test_bounding_rect.cpp build/Rect.o





build/leaks.out: src/Rect.cpp src/Barrel.cpp src/Matrix.cpp src/My_string.cpp src/Text_wrapper.cpp src/lab1.cpp
	clang++ -g -fsanitize=address -fno-omit-frame-pointer -o build/leaks.out src/lab1.cpp src/Rect.cpp src/Barrel.cpp src/Matrix.cpp src/My_string.cpp src/Text_wrapper.cpp

leaks: build/leaks.out
	./build/leaks.out < input.txt

# 3.5*
clean:
	rm -f build/Rect.o build/Barrel.o build/Batrix.o build/By_string.o build/Text_wrapper.o build/debug.out build/leaks.out

