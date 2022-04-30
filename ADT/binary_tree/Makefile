CXX=g++
CXXFLAGS=-Wall -std=c++11 -Wc++11-extensions

binary_search_tree: binary_search_tree.o
	$(CXX) $(CXXFLAGS) -o $@ $^

binary_tree: binary_tree.o
	$(CXX) $(CXXFLAGS) -o $@ $^

check_bst: check_bst.o
	$(CXX) $(CXXFLAGS) -o $@ $^

lowest_common_ancestor: lowest_common_ancestor.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o binary_search_tree binary_tree check_bst lowest_common_ancestor
	
all: binary_tree binary_search_tree check_bst lowest_common_ancestor