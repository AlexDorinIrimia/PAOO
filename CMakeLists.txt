cmake_minimum_required(VERSION 3.10)

set(project "budget")
project(${project})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(myfiles src/Transaction.cpp src/Budget.cpp include/Transaction.hpp include/Budget.hpp)
include_directories(src)
include_directories(include)
add_library(lib STATIC ${myfiles})
add_executable(${project} src/main.cpp)
target_link_libraries(${project} PUBLIC lib)
target_include_directories(${project} 
 PRIVATE src INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>)
