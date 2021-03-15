#include <WiFi.h>

unsigned long connect_timer = 0;
bool wifi_connected = false;

void WiFiEvent(WiFiEvent_t event) {
    switch (event) {
        case SYSTEM_EVENT_STA_GOT_IP:
            DBG("\nWiFi connected");
            DBG(WiFi.localIP());

            wifi_connected = true;
            break;

        case SYSTEM_EVENT_STA_DISCONNECTED:
            DBG("WiFi connection lost");
            wifi_connected = false;
            connect_timer = millis();

            break;

        default:
            break;
    }
}

void wifiInit() {
    WiFi.onEvent(WiFiEvent);
}

void wifiConnect() {
    DBG("\nConnecting to WiFi");
    WiFi.disconnect(true);
    WiFi.begin(ssid, pass);
}
