.PHONY: all clean

all: bin/mapper bin/reducer_mean bin/reducer_variance

bin/mapper:
	mkdir -p bin
	g++ -o $@ mapper.cpp

bin/reducer_mean:
	mkdir -p bin
	g++ -o $@ reducer_mean.cpp

bin/reducer_variance:
	mkdir -p bin
	g++ -o $@ reducer_variance.cpp

clean:
	rm -rf bin output
