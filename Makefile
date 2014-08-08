all: build run

build:
	g++ src/main.cpp src/Videocaper.cpp src/Photocaper.cpp -o bin/wCamera

run:
	bin/wCamera -p path -l 10 -a vid

clean:
	rm -f *.o bin/wCamera