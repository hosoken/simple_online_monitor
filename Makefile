### ROOT
RTINCLUDE = $(shell root-config --cflags)
RTLIBS    = $(shell root-config --glibs)

### Flags
CXX     = g++
CFLAGS  = -O2 -Wall
FLAGS   = $(CFLAGS) $(RTINCLUDE) -I.
LIB     = $(RTLIBS)


all: online

online: online.o
	@echo Linking $@        
	@$(CXX) $(FLAGS) -o $@ $^ $(LIB) 

%.o: %.cc
	@echo Compiling $< ...
	@$(CXX) $(FLAGS) -c $<

clean:
	@echo Cleaning up ...
	@rm -f *.o onlie viwer
