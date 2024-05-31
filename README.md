# GameForge

Gameforge is a game development library designed to unify game engine development tools in C++. It is very much a work in progress, but the eventual goal is to 
add support for every major game development tool.

# What GameForge does

When developing games without an engine, often a lot of boilerplate code is needed that takes a significant time to write. GameForge aims to collect all that boilerplate code together in an easy to use package, in a format that gives the user free choice over how the code is used.

# Planned Frameworks 

These frameworks are planned to have GameForge support and integration:
* SDL2/3
* SFML
* OpenGL 
* CGLM/GLM
* Chipmunk

# How to use

It is highly recomended that users build this library alongside their project, as the cmake options are highly specific to the project that the library is used with. To add the library to your project, simply git clone it and then add this to your cmakelists.txt:
```cmake 
add_subdirectory(Path/To/GameForge ${CMAKE_BINARY_DIR}/GameForge)
target_link_libraries(YourProjectName PUBLIC GameForge)
```

There are a number of important options that need to be set before adding GameForge, as listed below:
* BUILD_SHARED_LIBS - This sets whether or not to build the library as shared or static
* USING_CHIPMUNK2D - This sets whether or not to look for, link against, and create definitions for Chipmunk2D related utilites
* USING_SFML - This sets whether or not to look for, link against, and create definitions for SFML related utilites
