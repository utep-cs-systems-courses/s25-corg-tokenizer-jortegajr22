OBJS = uimain.o tokenizer.o history.o

CFLAGS = -g -O3

all: starT

starT: $(OBJS)
	cc -o starT $(CFLAGS) $(OBJS)

$(OBJS): uimain.h tokenizer.h history.h

clean:
	rm -f *.o starT


run:starT
	./starT
