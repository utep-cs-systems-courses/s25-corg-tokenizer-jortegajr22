OBJS = uimain.o tokenizer.o

CFLAGS = -g -O3

all: starT

starT: $(OBJS)
	cc -o starT $(CFLAGS) $(OBJS)

$(OBJS): uimain.c tokenizer.c

clean:
	rm -f *.o starT


run:starT
	./starT
