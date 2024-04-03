nasm -f win64 saxpy.asm
gcc -c specs_c.c -o main.o
gcc -o main saxpy.obj main.o