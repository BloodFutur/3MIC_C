PROG = main
OBJS = $(PROG).o pile.o lexer.o execute.o command.o

FLAGS = -Wall
args = '$(filter-out $@,$(MAKECMDGOALS))'

default: $(PROG)

clean:
	rm *.o $(PROG)

run: $(PROG)
	./$(PROG) $(args)

$(PROG): $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $@

%:
	@:

%.o: %.c
	gcc -c $< $(FLAGS)


pile.o: pile.h
lexer.o: lexer.h
execute.o: execute.h
command.o: command.h