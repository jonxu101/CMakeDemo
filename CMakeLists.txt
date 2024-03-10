# g++ -Iinclude demo.cpp MyClass.cpp lib/glfw/libglfw3.a lib/glew/lib/libglew32.a -lgdi32 -lopengl32 -lkernel32 -luser32 -o ./bin/demo.exe -DGLEW_STATIC

cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw-3.4)

add_library(headers INTERFACE)
target_include_directories(headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(demo_cmake   demo.cpp 
                            MyClass.cpp)

add_definitions(-DGLEW_STATIC)

target_link_libraries(demo_cmake    headers 

                                    glfw
                                    ${PROJECT_SOURCE_DIR}/lib/glew/lib/libglew32.a 

                                    gdi32 
                                    opengl32 
                                    kernel32 
                                    user32)