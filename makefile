CFLAGS=-D _DEBUG -ggdb3 -std=c99 -O0 -Wall -Wextra -Waggressive-loop-optimizations -Wmissing-declarations \
-Wcast-align -Wcast-qual -Wchar-subscripts -Wno-conversion -Wempty-body -Wfloat-equal -Wformat-nonliteral \
-Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wopenmp-simd -Wpacked -Wpointer-arith \
-Winit-self -Wredundant-decls -Wshadow -Wno-sign-conversion -Wstrict-overflow=2 -Wsuggest-attribute=noreturn \
-Wsuggest-final-methods -Wsuggest-final-types  -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code \
-Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-varargs -Wstack-protector -fcheck-new \
-fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 \
-pie -fPIE -Werror=vla \
-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

all:
	@gcc ${CFLAGS} gameplay.c rules2ver.c bitboards.c -o chess
