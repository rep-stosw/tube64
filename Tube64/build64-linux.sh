#!/bin/bash

clear

#if false; then

rm -f *.o
rm -f *.map
rm -f bin/tube64

#echo 'Press any key...'
#read -rsn1

echo 'Compile tube...'
g++ -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections -fno-rtti -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result -Wno-format-security -c Game/tube.cpp -IGame -IMusic -ISound -Itlsf -fsigned-char
g++ -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections -fno-rtti -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result                      -c Game/trig.cpp -IGame -IMusic -ISound -Itlsf
g++ -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections -fno-rtti -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result                      -c Game/misc.cpp -IGame -IMusic -ISound -Itlsf

g++ -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections -fno-rtti -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result -D_OPL3_ -c Music/HMP.cpp  -IGame -IMusic -ISound -Itlsf
g++ -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections -fno-rtti -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result -D_OPL3_ -c Sound/SB16.cpp -IGame -IMusic -ISound -Itlsf

gcc -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections           -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result -c Music/hmpfile.c       -IGame -IMusic -ISound -Itlsf
gcc -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections           -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result -c Music/hmpopl.c        -IGame -IMusic -ISound -Itlsf
gcc -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections           -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result -c Music/opl3.c -o opl.o -IGame -IMusic -ISound -Itlsf

gcc -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections           -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result -c tlsf/tlsf.c
g++ -m64 -Ofast -DNDEBUG -ffunction-sections -fdata-sections -fno-rtti -ftree-vectorize -fno-math-errno -fmax-errors=1 -fomit-frame-pointer -ffast-math -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wno-unused-variable -Wno-unused-but-set-variable -Wno-parentheses -Wno-maybe-uninitialized -Wno-unused-result -c tlsf/allocator.cpp

#fi

echo 'Link tube...'
g++ -m64 -Ofast -DNDEBUG -o bin/tube64 tube.o trig.o misc.o opl.o hmpopl.o hmpfile.o HMP.o SB16.o tlsf.o allocator.o -static-libstdc++ -static-libgcc -lSDL2 -lasound -Xlinker -Map=tube.map -Wl,--strip-all -Wl,--gc-sections

chmod +x bin/tube64

