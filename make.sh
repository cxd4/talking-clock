mkdir -p obj
src="."

FLAGS_C="-masm=intel -Os -pedantic -ansi -Wall"
OBJ_LIST="obj/main.o"

echo Compiling C sources...
cc -S $FLAGS_C -o obj/main.asm          $src/main.c

echo Assembling compiled sources...
as -o obj/main.o                        obj/main.asm

echo Linking assembled objects...
cc -s -o talktime $OBJ_LIST
