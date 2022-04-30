CXX=g++
CXXFLAGS=-Wall -std=c++11 -Wc++11-extensions

MatchingParenthesis: MatchingParenthesis.o
	$(CXX) $(CXXFLAGS) -o $@ $^

QueueUsingTwoStacks: QueueUsingTwoStacks.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Sort: Sort.o
	$(CXX) $(CXXFLAGS) -o $@ $^

DeleteMiddleElement: DeleteMiddleElement.o
	$(CXX) $(CXXFLAGS) -o $@ $^

StackReversal: StackReversal.o
	$(CXX) $(CXXFLAGS) -o $@ $^

QueueReversal: QueueReversal.o
	$(CXX) $(CXXFLAGS) -o $@ $^

SmallerElementForEachArrayElement: SmallerElementForEachArrayElement.o
	$(CXX) $(CXXFLAGS) -o $@ $^

all: MatchingParenthesis StackReversal DeleteMiddleElement QueueUsingTwoStacks Sort QueueReversal SmallerElementForEachArrayElement

clean:
	rm -f  *.o	MatchingParenthesis StackReversal DeleteMiddleElement QueueUsingTwoStacks Sort QueueReversal SmallerElementForEachArrayElement