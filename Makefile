PROG = prog 
OBJS = base.o scan.o parse.o interpret.o main.o

CFLAGS = -g
LIBS = -lm # Link the math library

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

all : $(PROG)

$(PROG) : prog.h $(OBJS)
	gcc $(CFLAGS) $(LIBS) -o $@ $(OBJS)

clean :
	rm -rf $(PROG) $(OBJS)
