# TD4: network probes

In this session, you shall write a Wi-Fi network probe in order to intercept any nearby traffic along with RSSI values. Remember that each frame has its own RSSI value, which cannot be swapped with another one.

## Hardware

You shall use Raspberry Pi with an additional Wi-Fi NIC able to go into monitoring mode. A Raspberry Pi is able to compile code, so use it to compile your code in and avoid relying on a cross compilation toolchain.

## Compile the radiotap iter library

For network probes, you need to compile the radiotap library. You have to get the radiotap.tar.gz file from Moodle, then unpack it and compile it.

```bash
tar xzf radiotap.tar.gz
mkdir build
cd build/
cmake ../radiotap-library
make
```

When compilation is finished, copy file libradiotap.so in /usr/lib (or /usr/lib64 given your system architecture).

## Instructions

Our Raspberry Pi comes with a Raspbian system (GNU/Linux Debian distribution adapted to Raspberry Pi), that enables all of the regular linux interactions and softwares, including, but not limited to, C++ and libpcap library as well as the radiotap_iter headers.
The tasks are:

- implement the pcap handler in pcap_handler.cpp. This handler relies on ratiotap_iter to extract RSSI and MAC address values from the **incoming** frames. Then, both information are stored along the current timestamp. Last, you must clean the RSSI samples list from every sample older than 1 second. Note that, from the network probe point of view, the MAC addresses identifying a RSSI sample are the mobile devices MAC addresses.
- implement the send_samples function in http.cpp. This function builds an HTTP request whose parameters are ap with the current probe MAC address (from the server point of view, each probe must be identified), and as many parameters as there are mobile devices detected. Those parameters are named with the mobile device MAC address while their values are the average value of the RSSI samples available for the current address. For instance, probe with MAC@ 00:00:00:00:00:01 and RSSI samples (already averaged) ['01:00:00:00:00:00': -56.8, '02:00:00:00:00:00': -47.1] will send the following parameters: ap=00:00:00:00:00:01&01:00:00:00:00:00=-56.8&02:00:00:00:00:00=-47.1
- implement the options passing to the probe. It can receive 3 parameters:
    - -i with a parameter defines the RFMON interface to use (it is already in the code, use it as a model)
    - -h with a parameter defines the positioning server host (name or IP)
    - -p with a parameter defines the positioning server listening port

## Test

You may choose to test your code against a simple web server (which only outputs its requests parameters) or a nc listening server.
