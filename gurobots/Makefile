#
# Makefile
# Callum McColl, 2019-06-05 11:58
#

ALL_TARGETS=test robot-local

C_SRCS!=ls *.c
CC_SRCS!=ls *.cc
ALL_HDRS!=ls *.h *.hpp
DOC_HDRS=${ALL_HDRS}
SPECIFIC_LIBS+=-lm
SPECIFIC_LIBS+=-lguunits
SPECIFIC_LIBS+=-lgusimplewhiteboard
SPECIFIC_LIBS+=-lgucoordinates
LOCAL=_LOCAL

${MODULE_BASE}_HDRS=${ALL_HDRS}
PKGCONFIG_NAME=gurobots
PKGCONFIG_VERSION=1.0
PKGCONFIG_DESCRIPTION=Utilities for monitoring sensors for specific robots.


.include "../../../mk/cxxstd.mk"

.include "../../../mk/mipal.mk"
# vim:ft=make
#
