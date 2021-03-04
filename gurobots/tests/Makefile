WFLAGS=-Wall -Weverything -Wno-unknown-pragmas -Wno-unknown-warning-option -Wno-global-constructors -Werror -Wno-padded -Wno-weak-vtables -Wno-c99-extensions -Wno-variadic-macros ${EXTRA_WFLAGS} -Wno-poison-system-directories -Wno-suggest-override -Wno-suggest-destructor-override

HDRS!=ls *.h 2>/dev/null || :
C_SRCS!=ls *.c 2>/dev/null || :
CC_SRCS!=ls *.cc 2>/dev/null || :
CPP_SRCS!=ls *.cpp 2>/dev/null || :

CXXFLAGS+=-I../../../../../Common -I../../../../gusimplewhiteboard
SPECIFIC_LIBS=-lguunits -lgucoordinates -lgusimplewhiteboard

.include "../../../../mk/gtest.mk"
.include "../../../../mk/mipal.mk"
