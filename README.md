# build with autotools on osx 
i.e. use (utoscan, autoreconf, autoconf, automake, libtool) to build and install to 
/usr/local/bin/hello 
/usr/local/lib/libhi.dylib, libhi.la, etc
/usr/local/include/hi.h  

editted conigure.ac, Makefile.am, lib/Makefile.am, src/Makefile.am.

to build
./autogen.sh
./configure
make
sudo make install 

# create static lib libhi.a and build main.cpp against it
g++ -c lib/hi.cpp -o lib/hi.o
ar rcs lib/libhi.a lib/hi.o
g++ src/main.cpp -L./lib/ -lhi -I./lib/
(./a.out is ~14K and move lib/libhi.a doesn't matter)
 
# create dynamic lib libhi.dylib and build main.cpp against it
g++ -dynamiclib -o lib/libhi.dylib lib/hi.cpp
g++ src/main.cpp -L./lib/ -lhi -I./lib/
(./a.out is ~8K and move lib/libhi.dylib will generate an error)
