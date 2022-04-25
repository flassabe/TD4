#include "http.h"
#include <Poco/Net/Net.h>
#include <Poco/Net/HTTPSessionFactory.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <map>
#include <set>
#include <cmath>
#include <string>

using namespace std;
using namespace Poco::Net;

extern string server_host;
extern string server_port;

void send_samples(RSSILog samples, string ap_mac_addr)
{
  /*
   * TODO: Implement this function
   * It takes two parameters:
   * 	- samples with RSSI samples ordered by reception time
   * 	- ap_mac_addr the Raspberry Pi MAC address
   * 
   * It must send its MAC address as variable name ap
   * and a list of pairs DeviceMAC=RSSI where each DeviceMAC is unique
   * and RSSI are average RSSI values when multiple values exist for a
   * given DeviceMAC
   * 
   * The packet must be sent to http://localhost:8080/rssi
   * 
   * HTTP requests handling use Poco::Net API
   * */
	// Your code here
}
