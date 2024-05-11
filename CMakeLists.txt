cmake_minimum_required(VERSION 3.11)

project(Chess)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(SOURCE
    ./src/bitboards.c
    ./src/gameplay.c
    ./src/rules2ver.c
)

set(INCLUDE_DIR 
    ./include/
)

set(DEBUG_FLAGS 
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

option(MyDebug OFF)

if (MyDebug)
    set(CMAKE_C_FLAGS ${DEBUG_FLAGS})
endif()

add_executable(chess ${SOURCE})

target_include_directories(chess PRIVATE ${INCLUDE_DIR})

target_compile_features(chess PRIVATE c_std_99)

add_subdirectory(lib/SDL-release-2.30.3)
add_subdirectory(lib/SDL_ttf-release-2.22.0)

add_executable(gui gui/gui.c)

target_include_directories(gui PRIVATE
    lib/SDL-release-2.30.3/include/
    lib/SDL_ttf-release-2.22.0/
)

target_link_libraries(gui PRIVATE
    SDL2
    SDL2_ttf
)