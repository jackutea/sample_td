gcc .\src\main.c -I include -c -o .\build\main.o
gcc .\build\main.o .\lib\raylib.dll -o .\bin\main.exe
.\bin\main.exe