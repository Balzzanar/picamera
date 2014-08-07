all: build run

build:
	g++ src/main.cpp src/example.cpp src/Photocaper.cpp -o mynewtest

run:
	./mynewtest

clean:
	rm -f *.o mynewtest