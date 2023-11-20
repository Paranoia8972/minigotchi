// packet.cpp: handles json payload

##include "packet.h"
#include <ESP8266WiFi.h>

PacketSender packetSender; // instance of the object

// json payload
const char* jsonPayload = "{"
    "\"epoch\": 1, "
    "\"face\": \"(◕‿‿◕)\", "
    "\"identity\": \"b9210077f7c14c0651aa338c55e820e93f90110ef679648001b1cecdbffc0090\", "
    "\"name\": \"minigotchi\", "
    "\"policy\": {"
        "\"advertise\": true, "
        "\"ap_ttl\": 0, "
        "\"associate\": true, "
        "\"bored_num_epochs\": 0, "
        "\"channels\": ["
          "1, "
          "3, "
          "4, "
          "5, "
          "6"
        "], "
        "\"deauth\": true, "
        "\"excited_num_epochs\": 1, "
        "\"hop_recon_time\": 1, "
        "\"max_inactive_scale\": 0, "
        "\"max_interactions\": 1, "
        "\"max_misses_for_recon\": 1, "
        "\"min_recon_time\": 1, "
        "\"min_rssi\": 1, "
        "\"recon_inactive_multiplier\": 1, "
        "\"recon_time\": 1, "
        "\"sad_num_epochs\": 1, "
        "\"sta_ttl\": 0"
    "}, "
    "\"pwnd_run\": 0, "
    "\"pwnd_tot\": 0, "
    "\"session_id\": \"84:f3:eb:58:95:bd,\""
    "\"uptime\": 1, "
    "\"version\": \"v1.0.0\""
"}";

String PacketSender::serializeJsonPayload(const char* essid) {

}