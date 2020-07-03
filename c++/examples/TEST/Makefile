TEST_FILES = bug-2026390 \
			 bug-2990791 \
			 bug-2992224

IPATH = -I./.. -I../../ -I$(HWUT_PATH)

ADDFLAGS = -ggdb -Wall --coverage

all: $(TEST_FILES)

hwut-info:
	@echo $(TEST_FILES)

%: %.cpp 
	g++ $(ADDFLAGS) $(IPATH) $< -o $@

clean:
	rm -f $(TEST_FILES)
	rm -f *.gcov *.gcno *.gcda \#*


hwut-gcov-info:
	@echo bug-*.cpp
	@echo ../*.cpp
	@echo ../../GetPot.cpp

hwut-gcov-obj:
	@echo ./ ../
