P_OUTDIR = ./
P_LIBDIR = ./lib

CPP     = g++
CC      = gcc
LD      = ld

CFLAGS = -D_REENTRANT -DLINUX -Wall -O2 -pthread -Wno-deprecated -g
LFLAGS = -Wl

CFLAGS += -I./ \
		-I./depend/ 
	
SRCS = $(wildcard ./src/*.cpp)
OBJS =  $(patsubst %.cpp, %.o, $(SRCS))
	
LDLIBS =  -L./Bin/ \
	-L./	\
	-ldhdvr		\
	-ldhnetsdk 


CFLAGS += -D_DEBUG
LDFLAGS = -Wl -Bdynamic -lgcc_s

####################################################################
EXEC = $(P_OUTDIR)/test
####################################################################
# make all
# client:all

all: checkoutdir $(EXEC)

$(EXEC): $(OBJS)
	$(CPP) $(LDFLAGS)  $(CFLAGS)  -o $@ $(OBJS) $(LDLIBS)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

.cpp.o:
	$(CPP) -c $(CFLAGS) $< -o $@
	
checkoutdir: 
	@if test ! -d $(P_OUTDIR) ; \
	then \
		mkdir $(P_OUTDIR) ; \
	fi

clean:
	rm -f $(OBJS) $(EXEC)*

