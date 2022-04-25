CC=g++
CCFLAGS=-std=c++14 -I ../resources/radiotap-library -I .
LDFLAGS=-L ../resources/build -Wl,-R ../resources/build -s -lradiotap -lPocoNet -lpcap -lPocoFoundation
TARGET=pcap

all: $(TARGET)

$(TARGET): pcap.cpp defines.h http.o pcap_handler.o config.o
	$(CC) $(CCFLAGS) pcap.cpp -o pcap http.o pcap_handler.o config.o $(LDFLAGS)

%.o: %.cpp %.h
	$(CC) $(CCFLAGS) -c $< -o $@
