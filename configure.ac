AC_PREREQ([2.69])
AC_INIT([snapd-xdg-open], [0.0.0])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/snapd-xdg-open.c])

AM_INIT_AUTOMAKE

# information on the package

# checks for programs

AC_PROG_CC

# checks for libraries

PKG_CHECK_MODULES([GIO], [gio-2.0])
AC_SUBST([GIO_CFLAGS])
AC_SUBST([GIO_LIBS])

# checks for header files

# checks for types

# checks for structures

# checks for compiler characteristics

# checks for library functions

# checks for system services

AC_CONFIG_FILES([Makefile data/Makefile src/Makefile])
AC_OUTPUT
