[gurobots](https://github.com/mipalgu/gurobots) {#mainpage}
===================================================================
\tableofcontents

A library for abstracting robots that utilises gusimplewhiteboard for local communication.

## Online Documentation

 * [Module](https://mipalgu.github.io/gurobots/globals_defs.html)
   - [Functions](https://mipalgu.github.io/gurobots/globals_func.html)
   - [Classes](https://mipalgu.github.io/gurobots/annotated.html)
   - [Macros](https://mipalgu.github.io/gurobots/globals_defs.html)

## Prerequisites

You need a posix system a C/C++ compiler, [cmake](https://cmake.org),
and a build system supported by cmake, such as
[Ninja](https://ninja-build.org) or
[gmake](https://www.gnu.org/software/make/).
If you are running linux, then you will need to install [libdispatch](https://apple.github.io/swift-corelibs-libdispatch/).
You will also need to install the following pre-requisite packages.
Follow the links below for instructions:

 * [gu_util](https://github.com/mipalgu/gu_util)
 * [guunits](https://github.com/mipalgu/guunits)
 * [gucoordinates](https://github.com/mipalgu/gucoordinates)
 * [guvision_utils](https://github.com/mipalgu/guvision_utils)
 * [gusimplewhiteboard](https://github.com/mipalgu/gusimplewhiteboard)

## Building and Installation

To build, you simply create a build directory (e.g. `build.ninja`)
using [cmake](https://cmake.org), then use your build system to
build and install. Here is an example using
[Ninja](https://ninja-build.org):

	mkdir ../build.ninja
	cd ../build.ninja
	cmake -G Ninja ../gusimplewhiteboard
	ninja
	ninja install

If you require root permissions, run `ninja install` as root,
e.g. by using [sudo](https://www.sudo.ws):

	sudo ninja install
