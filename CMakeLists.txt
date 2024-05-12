cmake_minimum_required(VERSION 3.11)

project(Chess)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(MY_DEBUG_FLAGS
    -DDEBUG
    -ggdb3
    -O0 
    -Wall 
    -Wextra 
    -Waggressive-loop-optimizations
    -Wmissing-declarations 
    -Wcast-align 
    -Wcast-qual 
    -Wno-char-subscripts    
    -Wconversion 
    -Wempty-body 
    -Wfloat-equal 
    -Wformat-nonliteral 
    -Wformat-security 
    -Wformat-signedness 
    -Wformat=2 
    -Winline 
    -Wlogical-op 
    -Wopenmp-simd 
    -Wpacked 
    -Wpointer-arith 
    -Winit-self 
    -Wredundant-decls 
    -Wshadow 
    -Wsign-conversion 
    -Wstrict-overflow=2 
    -Wsuggest-attribute=noreturn 
    -Wsuggest-final-methods 
    -Wsuggest-final-types 
    -Wswitch-default 
    -Wswitch-enum 
    -Wsync-nand 
    -Wundef 
    -Wunreachable-code 
    -Wunused 
    -Wvariadic-macros 
    -Wno-missing-field-initializers 
    -Wno-narrowing 
    -Wno-varargs 
    -Wstack-protector 
    -fcheck-new 
    -fstack-protector 
    -fstrict-overflow 
    -fno-omit-frame-pointer 
    -Wlarger-than=16384 
    -Wstack-usage=8192  
    -fPIE 
    -Werror=vla 
    -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
)

if (CMAKE_BUILD_TYPE EQUAL "MyDedug")
    set(CMAKE_C_FLAGS ${MY_DEBUG_FLAGS})
endif()

set(SOURCES
    ./src/main.c
    ./src/bitboards.c
    ./src/gameplay.c
    ./src/rules2ver.c
    ./src/gui.c
)

set(INCLUDE_DIRS
    ./include/
)

set(LIB_INCLUDE_DIRS
    ./lib/SDL-release-2.30.3/include/
    ./lib/SDL_ttf-release-2.22.0/
    ./lib/SDL_image-release-2.8.2/include/
)

add_executable(chess ${SOURCES})

target_include_directories(chess PRIVATE ${INCLUDE_DIRS} ${LIB_INCLUDE_DIRS})

target_compile_features(chess PRIVATE c_std_99)

add_subdirectory(./lib/SDL-release-2.30.3)
add_subdirectory(./lib/SDL_ttf-release-2.22.0)
add_subdirectory(./lib/SDL_image-release-2.8.2)

target_link_libraries(chess PRIVATE
    SDL2
    SDL2_ttf
    SDL2_image
)
