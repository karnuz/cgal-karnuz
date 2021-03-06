CXX=g++ -std=c++11

OBJDIR=bin
SRCDIR=src
TESTDIR=test
TEST_OBJDIR=bin/test
LIBNAME=karnuz

LIB=$(OBJDIR)/lib$(LIBNAME).so

SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

TEST_SRC=$(wildcard $(TESTDIR)/*.cpp)
TEST_OBJS=$(patsubst $(TESTDIR)/%.cpp, $(TEST_OBJDIR)/%.o, $(TEST_SRC))
TEST_BINS=$(patsubst %.o, %, $(TEST_OBJS))

CFLAGS=-Isrc/ -I/Users/himanshusharma/bin/gtestlibs/include -L/Users/himanshusharma/bin/gtestlibs/lib -lgtest -fPIC

TEST_LDFLAGS=-L$(OBJDIR) -l$(LIBNAME) -Wl,-rpath $(OBJDIR)

# define a newline function to run each test as a separate command
define \n


endef

default: $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(OBJDIR)
	$(CXX) -D_DEBUG -g -O0 -c -o $@ $< $(CFLAGS)

$(LIB): $(OBJS)
	$(CXX) -D_DEBUG -g -O0 -shared -o $@ $^

$(OBJDIR):
	mkdir $@

tests: $(LIB) $(TEST_OBJDIR) $(TEST_BINS)

$(TEST_BINS): $(TEST_OBJS)

$(TEST_OBJDIR): $(OBJDIR)
	mkdir $@

$(TEST_OBJDIR)/%: $(TEST_OBJDIR)/%.o $(LIB)
	$(CXX) -g -o $@ $< $(TEST_LDFLAGS)

$(TEST_OBJDIR)/%.o: $(TESTDIR)/%.cpp $(OBJDIR)
	$(CXX) -D_DEBUG -g -O0 -I$(SRCDIR) -c -o $@ $<

check: tests
	@echo "Running tests..."
	$(foreach TEST, $(TEST_BINS), @./$(TEST) 2>&1 1>/dev/null && printf "$(TEST) \t Pass\n" || printf "$(TEST) \t Fail\n";${\n})

clean:
	rm -rf $(OBJDIR)

.PHONY: clean default tests check
