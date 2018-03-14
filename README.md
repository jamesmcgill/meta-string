# meta-string

Tiny project using constexpr to concatenate string literals at compile time

## Building:
+ On Windows run the provided `build.bat` file  
   
+ On gnu tools run `build.sh`  
   
+ Or type the following commands:  
   `mkdir build && cd build`  
   
   `cmake ..`  
     or to use your specific compiler:  
   `cmake .. -DCMAKE_CXX_COMPILER=g++-7.1`  
   
   then finally:  
   `cmake --build .`  

## Requirements:
+ A compiler with some C++ 14 support (i.e. extended constexpr support)  
    (Tested on VS 2017 15.6 and GCC 7.1) 

+ CMake 3.9.2 or higher
