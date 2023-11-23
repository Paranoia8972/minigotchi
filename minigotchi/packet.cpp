// packet.cpp: handles the sending of pwnagotchi packets

#include "packet.h"
#include "raw80211.h"

void PacketSender::sendJsonPayloadFromFile(const char* filePath) {
  File configFile = SPIFFS.open(filePath, "r");
  if (configFile) {
    size_t size = configFile.size();
    std::unique_ptr<char[]> buf(new char[size]);
    configFile.readBytes(buf.get(), size);
    configFile.close();

    DynamicJsonDocument doc(1024);
    deserializeJson(doc, buf.get());
  } else {
    Serial.println("Failed to open JSON file for reading");
  }
}
