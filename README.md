# About

This is a collection of C++ programs, which I created for the FHNW-module 
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
Depending on your operating system, you might miss some libraries that are 
necessary for a few programs. E.g., OS X does not provide POSIX `mqueue.h`, 
thus the message queue programs won't compile on OS X. Therefore, our 
lecturer suggested to work on a Raspberry Pi using a linux distribution.

An alternative way is to compile and execute the programs in a docker container.
You can find a `Dockerfile` in this repository which uses an ubuntu image 
and installs the following components:
- `gcc` compiler for C-applications
- `g++` compiler for C++-applications
- `make` build-tool for C/C++
- `libc` library
- `libncurses` library

Build the image using the provided shell script:
```
chmod u+x docker-build.sh
./docker-build.sh
```

Afterwards, start a container (this will directly connect you to the 
container, so you can start hacking):
```
chmod u+x docker-start.sh
./docker-start.sh
```
All files/directories from your working directory will be synced with the 
container, so you can edit on your computer and compile/execute in the 
container. Run `exit` when connected to the container to terminate the session.

## Multiple Docker-connections
If you want to have multiple terminals to the same docker, you can easily 
do that like this: Open a new terminal window and type:
```
docker exec -it fhnw_pct /bin/bash

# Or do once:
chmod u+x docker-second-connection.sh

# Then simply:
./docker-second-connection.sh
```


# Running in CLion
If you want to run this project in CLion, then it is very useful for better 
code-completion, if you do the following when creating or adding new 
*.c - files:
- When creating inside CLion, then make sure to choose option "add to 
  targets", so the file gets added to `CMakeLists.txt`.
- When importing a file, just manually add it to the list of 
  "add_executable" inside `CMakeLists.txt`.
