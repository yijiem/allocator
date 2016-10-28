# allocator
customized C++ allocator library

### allocators list
count allocator: an allocator which counts the number of bytes its user holds

### how to run
eg: run the set_test inside ./example
```
mkdir build
cd build
cmake .. 
cmake --build . --target set_test
./set_test
```

### output
std::set allocates 736 bytes for 23 elements

std::unordered_set allocates 736 bytes for 23 elements
