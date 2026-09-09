#include <iostream>

void canDecoder(uint16_t canID, uint8_t payload[8], uint8_t dlc);

int main() {
    std::cout << "Hello World" << std::endl;

    uint8_t payload[8] = {0x0A, 0x1B, 0xFF}; // Example payload data
    canDecoder(0x123, payload, 3); //example CAN message with ID 0x123 and payload

    return 0;
}

//we are going to be adding a CAN decoder. Something that reads the oncoming information and sends it in for processing
//something from my CAN IDS project (in a simpler way)

void canDecoder(uint16_t canID, uint8_t payload[8], uint8_t dlc) {

    if (dlc < 3) {
        return;
    }

    //payload contains the data bytes of the CAN message
    if (canID == 0x123) { //let's say this is the canID we need to work with. This brings forward the ENGINE_RMP and THROTTLE
        //extract engine RPM and throttle position from the payload
        uint16_t engineRPM = (payload[0] << 8) | payload[1];
        uint8_t throttlePosition = payload[2];
        throttlePosition = throttlePosition * 100 / 255; // Convert to percentage

        std::cout << "Engine RPM: " << engineRPM << ", Throttle Position: " << (int)throttlePosition << "%" << std::endl;
    }
}