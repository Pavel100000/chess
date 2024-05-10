cmake_minimum_required(VERSION 3.11)

project(Chess)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
add_executable(gui_test ./gui/gui.c)

target_link_libraries(gui_test 
    SDL2
    SDL2_ttf
)

target_include_directories(chess PRIVATE ${INCLUDE_DIR})

target_compile_features(chess PUBLIC c_std_99)

