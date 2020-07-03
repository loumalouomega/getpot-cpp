IPATH = -I./. -I../.

# Delete the coverage flag, if no test coverage is necessary
ADDFLAGS = -ggdb # --coverage

PROGRAMS = \
		   absorb          \
		   constraints     \
		   direct_follow   \
		   ez-ufo          \
		   field_separator \
		   filter          \
		   flags           \
		   follow          \
		   get             \
		   bool            \
		   input-file      \
		   next            \
		   options         \
		   tails           \
		   ufo             \
		   variables       \
	       nominus_followers \
    	   expand          \
           nominus         \

all: $(PROGRAMS) 

%: %.cpp ../GetPot.hpp ../GetPot.cpp
	g++ $(ADDFLAGS) $(IPATH) $< -o $@

clean:
	rm -f $(PROGRAMS)
	rm -f *.gcov *.gcno *.gcda \#*

