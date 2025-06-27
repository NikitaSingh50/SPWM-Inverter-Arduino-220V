const int carrierFreq = 20000; // 20 kHz carrier
const int sineFreq = 50;       // 50 Hz reference
int sineTable[256];            // Precomputed sine wave values

void generateSineTable() {
    for (int i = 0; i < 256; i++) {
        sineTable[i] = 127 + 127 * sin(2 * PI * i / 256); // Fill with sine values (0-255)
    }
}

void setup() {
    pinMode(10, OUTPUT); // Upper MOSFET
    pinMode(9, OUTPUT);  // Lower MOSFET
    generateSineTable(); // Precomputes sine wave values
}

void loop() {
    for (int i = 0; i < 256; i++) {
        if (carrierFreq > sineTable[i]) {
            digitalWrite(10, HIGH);
            digitalWrite(9, LOW);
        } else {
            digitalWrite(10, LOW);
            digitalWrite(9, HIGH);
        }
        delayMicroseconds(100); // Add a delay if needed to control loop speed
    }
}

