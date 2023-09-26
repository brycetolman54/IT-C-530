CMake and Git

- We can use make files to automate the compilation and running process
```
// the file is called MakeFile

exectuableFileName: files needed to make it
	g++ -o -$@ -Os $<

// those mean the g++ compiler, the output is the name given above, optimize for file size, and use the first file given above to compile

run it with: make
```
- The file will only recompile when you change the files given in the line

- C++ uses a file called CMakeLists.txt:
```
// optimize for small size
set(CMAKE_CXX_FLAGS "-Os")

// add the exectuable
add_executable(hi hello.cc hello.h)
```

- You can make from a directory that is not the same as your source code
```
mkdir build
cd build
cmake .. 
// that will build the make file with the stuff in your .. directory but put the file in the build directory
```
