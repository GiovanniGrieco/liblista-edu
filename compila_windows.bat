gcc -c -DBUILDING_EXAMPLE_DLL LibLista.c -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers
gcc -shared -o liblista.dll LibLista.o -Wl,--out-implib,liblista.a
gcc -c esempi.c -std=c11 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers
gcc -o test.exe esempi.o -L. -llista
del *.o *.a
mkdir build
move test.exe ./build
move liblista.dll ./build
pause