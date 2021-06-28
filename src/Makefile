
src := $(wildcard ./*.cpp)
output := ../bin/log.a
obj = $(patsubst %.cpp, %.o, $(src))  # or  obj := $(src:.cpp=.o)
flag =  -std=c++11 -fpermissive

$(output): $(obj)
	echo $(obj)
	ar crv $@ $?
	rm -rf $(obj)

%.o: %.cpp 
	g++ -c $? -o $@ $(flag)

.PHONY: clean
clean:
	rm -rf $(output) \
	rm -rf $(obj)