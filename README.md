# About

This is a collection of C programs, which I created for the FHNW-module 
'pct - programming contest training'.

# Build

The programs are located in the `src` directory. 

The basic pattern to compile a single program with [gcc](https://gcc.gnu.org/) 
is as follows:

```
gcc src_file.c -o executable_file       # Compiles C-files
g++ src_file.cpp -o executable_file     # Compiles C++-files
```

This will compile `src_file.c` and generate an executable file called 
`executable_file` in the same directory.  Execute it with `./executable_file`.

A `makefile` is present to compile **all** programs at once to `src/out`:

```
cd src
make
```

Single programs can be compiled using their names:

```
make time1
```
You can also do the following to compile and then immediately execute an 
application:
```
make time1 && ./out/time1
```