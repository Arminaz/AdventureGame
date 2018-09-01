CXX=g++
CXXFLAGS= -std=c++0x -g -fprofile-arcs -ftest-coverage

LINKFLAGS= -lcppunit

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage
COVERAGE_RESULTS_TEST = results_test.coverage
COVERAGE_DIR_TEST = coverage_test

MEMCHECK_RESULTS = memcheck.xml
MEMCHECK_TEST_RESULTS = memtestcheck.xml

SRC_DIR = ./src
TEST_DIR = ./test

SRC_INCLUDE = ./include
TEST_INCLUDE = ./include/test

INCLUDE = -I ${SRC_INCLUDE}
INCLUDE_TEST = -I ${TEST_INCLUDE}

PROGRAM = ./Lexington
PROGRAM_TEST = ./Lexington_test

.PHONY: all
all: $(PROGRAM)

test : $(PROGRAM_TEST)

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean-part:
	rm -rf *~ $(SRC)/*.o *.gcov *.gcda *.gcno $(PROGRAM) $(PROGRAM_TEST) 

clean: 
	rm -rf *~ $(SRC)/*.o *.gcov *.gcda *.gcno *.xml *.out $(PROGRAM) $(PROGRAM_TEST) $(COVERAGE_RESULTS) $(COVERAGE_RESULTS_TEST) $(MEMCHECK_RESULTS) $(MEMCHECK_TEST_RESULTS) $(COVERAGE_DIR) $(COVERAGE_DIR_TEST)

$(PROGRAM):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(INCLUDE) $(SRC_DIR)/*.cpp main.cpp

$(PROGRAM_TEST):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE_TEST) $(INCLUDE) $(TEST_DIR)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS)
	$(PROGRAM_TEST)


memory : $(PROGRAM)
	valgrind --tool=memcheck $(PROGRAM)

memcheck: $(PROGRAM)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_RESULTS) $(PROGRAM)
memory : memcheck clean-part

memcheck_test: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_TEST_RESULTS) $(PROGRAM_TEST)

memory_test: memcheck_test clean-part

coverage_test: $(PROGRAM_TEST)
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS_TEST)
	$(LCOV) --extract $(COVERAGE_RESULTS_TEST) "*/src/*" -o $(COVERAGE_RESULTS_TEST)
	genhtml $(COVERAGE_RESULTS_TEST) --output-directory $(COVERAGE_DIR_TEST)
	rm -f *.gc* $(PROGRAM_TEST) 

coverage: $(PROGRAM)
	$(PROGRAM)
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	$(LCOV) --extract $(COVERAGE_RESULTS) "*/src/*" -o $(COVERAGE_RESULTS)
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	rm -f *.gc* $(PROGRAM)

docs: ${SRC_INCLUDE}
	doxygen Doxyfile

