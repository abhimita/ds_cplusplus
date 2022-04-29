CXX=g++
CXXFLAGS=-Wall -std=c++11 -Wc++11-extensions

test_list_doubly_linked: test_list_doubly_linked.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -pthread -lgtest

#list_doubly_linked: list_doubly_linked.o
#	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: run-test
run-test: test_list_doubly_linked
	./test_list_doubly_linked