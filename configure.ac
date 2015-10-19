#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([helloworld], [1], [daniel.yin@gmail.com])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AM_INIT_AUTOMAKE(no-define subdir-objects foreign)
AC_PROG_CXX

LT_INIT([pic-only])

# Checks for libraries.
AC_PATH_TOOL(RANLIB, ranlib)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.


AC_CONFIG_FILES([Makefile lib/Makefile src/Makefile])
AC_OUTPUT
