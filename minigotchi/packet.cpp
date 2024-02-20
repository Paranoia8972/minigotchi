///////////////////////////////////////////////////////////
// packet.cpp: handles the sending of pwnagotchi packets //
///////////////////////////////////////////////////////////

#include "packet.h"

// set magic number(222 in hex)
const uint8_t MAGIC_NUMBER = 0xDE;
const uint8_t COMPRESSION_ID = 0xDF; 

void Packet::send() {

    // json object creation
    DynamicJsonDocument doc(1024);

    // all settings
    // if github goes insane about that key in the "identity", its just the identity key that identifies a pwnagotchi 
  
    doc["epoch"] = 1;
    doc["face"] = "(^-^)";
    doc["identity"] = "b9210077f7c14c0651aa338c55e820e93f90110ef679648001b1cecdbffc0090";
    doc["name"] = "minigotchi";

    JsonObject policy = doc.createNestedObject("policy");
    policy["advertise"] = true;
    policy["ap_ttl"] = 0;
    policy["associate"] = true;
    policy["bored_num_epochs"] = 0;

    JsonArray channels = policy.createNestedArray("channels");
    channels.add(1);
    channels.add(3);
    channels.add(4);
    channels.add(5);
    channels.add(6);

    policy["deauth"] = true;
    policy["excited_num_epochs"] = 1;
    policy["hop_recon_time"] = 1;
    policy["max_inactive_scale"] = 0;
    policy["max_interactions"] = 1;
    policy["max_misses_for_recon"] = 1;
    policy["min_recon_time"] = 1;
    policy["min_rssi"] = 1;
    policy["recon_inactive_multiplier"] = 1;
    policy["recon_time"] = 1;
    policy["sad_num_epochs"] = 1;
    policy["sta_ttl"] = 0;

    doc["pwnd_run"] = 0;
    doc["pwnd_tot"] = 0;
    doc["session_id"] = "84:f3:eb:58:95:bd";
    doc["uptime"] = 1;
    doc["version"] = "v1.3.0";

    String jsonString;
    if (serializeJson(doc, jsonString) == 0) {
        // handle errors here
        // its usually just the json's fault maybe, please fix it dj1ch(or whoever changed that json above here, it's your fault)
        Serial.println("(X-X) Failed to serialize JSON");
    } else {
        // find frame size
        size_t frameSize = sizeof(MAGIC_NUMBER) + jsonString.length();

        // use memory for the data frame
        uint8_t* dataFrame = new uint8_t[frameSize];

        // set/copy compression id
        dataFrame[0] = MAGIC_NUMBER;

        // copy payload
        jsonString.getBytes(dataFrame + sizeof(MAGIC_NUMBER), frameSize - sizeof(MAGIC_NUMBER) + 1);

        // send full frame
        Raw80211::send(dataFrame, frameSize);

        // save memory 
        delete[] dataFrame;
        Serial.println("(>-<) Sent payload!");
    }
}

void Packet::advertise() {
    // for the sake of consistency also sending this packet 15 times
    for (int i = 0; i < 15; ++i) {
        send();
        delay(100);
    }
}
