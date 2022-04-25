#include "pcap_handler.h"
#include "http.h"
#include <radiotap_iter.h>
#include <string>
#include <stdint.h>
#include <sys/time.h>
#include <inttypes.h>
#include <map>

using namespace std;

RSSILog logs;

string mac2string(unsigned char mac[6]) {
  char mac_c_str[18];
  sprintf(mac_c_str, "%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  mac_c_str[17] = '\0';
  return string{mac_c_str};
}

/*
 * \function process_pkts PCAP callback function
 * \param user a pointer (to be cast) to a RSSILog variable
 * \param pkt a pointer to a rtap header
 * \param bytes a pointer to the captured packet, starting by the radiotap header
 */
void process_pkts(u_char* user, const struct pcap_pkthdr *pkt, const u_char *bytes) {
  /*
   * TODO: for each packet, extract the source address, the RSSI value(s),
   * the antenna index when present, and get system time. Each RSSI goes
   * to one element in the user->samples vector.
   * After dealing with the packet, check the first vector element
   * timestamp against current time. If it is older than 1 second, send
   * the samples (call send_samples from http.h)
   * */
    auto rtap_hdr = ( struct ieee80211_radiotap_header *) bytes;
    int fieldslen[] = {8, 1, 1, 4, 2};
    
    // check version it is not a 0 it's not radiotap
    if(rtap_hdr->it_version == 0) {
        struct ieee80211_radiotap_iterator iter;
        
        // start iterator
        int err = ieee80211_radiotap_iterator_init(&iter, rtap_hdr, pkt->caplen, nullptr);
        
        // if not starting errors
        if (!err) {
            auto wifi_hdr = (struct ieee80211_header *) ( bytes + iter._max_length);
            if (/* Filter only FromDS=0, ToDS=1 */ ) {
                // get source address
                
                // iterate over the radiotap iterator
                
                RSSISample sample = {
									/* Init. fields here */
                };
                
								// Create a sample and add it to the logs
                logs.push_back(sample);
                
                // if timestamp diff bigger than 1,
                // send the  packets
                time_t current_time = time(NULL);
                if (/* Check logs age */) {
                    printf("Sending packets\n");
                    send_samples(logs, source_address);
                    logs.clear();
                }
            }
        }
    }
}
