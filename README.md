# build with autotools on osx 
### to use (autoscan, autoreconf, autoconf, automake, libtool) to build and install to 
- /usr/local/bin/hello 
- /usr/local/lib/libhi.dylib, libhi.la, libhi.a
- /usr/local/include/hi.h  

### to use autotools needs to manually craft the following
- conigure.ac
- Makefile.am
- lib/Makefile.am (hi.cpp, hi.h)
- src/Makefile.am (main.cpp, config.h)

### to build hello (executable) and libhi.dylib (osx shared lib)
- ./autogen.sh
- ./configure
- make
- src/hello
(won't work if ./lib/.libs/libhi.0.dylib is absent) 
- sudo make install (this will install /usr/local/lib/libhiXXXX, /usr/local/include/hi.h, /usr/local/bin/hello. (however, no /usr/local/lib/pkgconfig/libhi.pc) 
(similar to 'ldd' on linux, use 'otool' on mac to show which shared libraries an executable depends on.)
(WARN: otool -L doesn't work without 'sudo make install') 
- otool -L /usr/local/bin/hello 
/usr/local/bin/hello:
	/usr/local/lib/libhi.0.dylib (compatibility version 1.0.0, current version 1.0.0)
	/usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 120.0.0)
	/usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1213.0.0)

# create static lib libhi.a and build main.cpp against it
- g++ -c lib/hi.cpp -o lib/hi.o
- ar rcs lib/libhi.a lib/hi.o
- g++ src/main.cpp -L./lib/ -lhi -I./lib/
(./a.out is ~14K and move lib/libhi.a doesn't matter)
 
# create dynamic lib libhi.dylib and build main.cpp against it
- g++ -dynamiclib -o lib/libhi.dylib lib/hi.cpp
- g++ src/main.cpp -L./lib/ -lhi -I./lib/
(./a.out is ~8K and move lib/libhi.dylib will generate an error)

# references
- [](https://pewpewthespells.com/blog/static_and_dynamic_libraries.html)


