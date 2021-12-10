all: cpp

cpp: reader writer

gen-cpp-from-proto:
	protoc -I=src --cpp_out=src/cpp src/addressbook.proto

writer: src/cpp/writer.cpp gen-cpp-from-proto
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ -std=c++11 src/cpp/writer.cpp src/cpp/addressbook.pb.cc -o writer `pkg-config --cflags --libs protobuf`

sim: reader-lib
	c++ -Lsim/models/ -o sim/sim sim/sim.cpp -lreader `pkg-config --cflags --libs protobuf`

reader-lib: addressbook
	mkdir -p sim/models
	c++ -shared -o sim/models/libreader.so src/cpp/obj/addressbook.pb.o src/cpp/obj/reader.o

addressbook: gen-cpp-from-proto
	mkdir -p src/cpp/obj
	c++ -std=c++11 -fPIC -c -o src/cpp/obj/addressbook.pb.o src/cpp/addressbook.pb.cc `pkg-config --cflags --libs protobuf`

reader: addressbook 
	mkdir -p src/cpp/obj
	c++ -std=c++11 -fPIC -c -o src/cpp/obj/reader.o src/cpp/reader.cpp `pkg-config --cflags --libs protobuf`

