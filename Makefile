vpath %.cpp ./src ./demos
ifdef dbg
DEBUG:=-DDEBUG -g -ggdb3 -rdynamic
endif


CXXFLAGS =-std=c++0x -I./inc $(DEBUG) 

OBJ=$(addsuffix .o, $(basename $(SRC)))
BIN_DOT_A=$(addsuffix .a, $(basename $(SRC)))
BIN=$(basename $(SRC))

default:$(BIN_DOT_A)
	ls *.a|xargs -I{} echo '{}' |perl -ne 'chomp;$$i=$$_;s/\..*//g;rename $$i,$$_'
	mv -f $(BIN) ./bin/
	rm -fr *.o

%.a:%.o
	g++ $(CXXFLAGS) -o $@ $^
