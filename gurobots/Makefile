#
# Makefile
# Callum McColl, 2019-06-05 11:58
#

ALL_TARGETS=test host-local atom-local atom1-local geode-local xc doc

C_SRCS!=ls *.c
CC_SRCS!=ls *.cc
ALL_HDRS!=ls *.h *.hpp
DOC_HDRS=${ALL_HDRS}
SPECIFIC_LIBS+=-lm
SPECIFIC_LIBS+=-lguunits
SPECIFIC_LIBS+=-lgusimplewhiteboard
SPECIFIC_LIBS+=-lgucoordinates

PKGCONFIG_NAME=gurobots
PKGCONFIG_VERSION=1.0
PKGCONFIG_DESCRIPTION=Provides structures which make dealing with robots easier.

.include "../../../mk/c++20.mk"
.include "../../../mk/prefs.mk"

${MODULE_BASE}_HDRS=${ALL_HDRS}

.include "../../../mk/testdir.mk"
.include "../../../mk/mipal.mk"
# vim:ft=make
#
