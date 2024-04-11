# strawx engine

custom wrapper/engine using SDL2 library

## How To Use

clone the repo inside your project folder:

```
- main/
    - strawx/
        - CMakeLists.txt
        - engine.hpp
        ...
    - CMakeLists.txt
    - user.cpp
    ...
```

and add the `strawx` folder to your cmakelist file using `add_subdirectory`:

```cmake
# user CMakeLists.txt
cmake_minimum_required(VERSION 3.26)

project(MyGame CXX)

add_subdirectory(strawx)

add_executable(${PROJECT_NAME} "user.cpp")

target_link_libraries(${PROJECT_NAME} PUBLIC strawx_engine)
```

then create a `.cpp` source file and define the Functions which is declared in `strawx/engine.hpp`

```cpp
#include "strawx/engine.hpp"

using namespace strawx;

void Game::Start()
{

}

void Game::Update()
{

}

void Game::Render()
{

}
```
