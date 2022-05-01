#define PIN_LED 8 // Initialization of LED foam.
float input_volt = 0.0; // Variable for output 
float data = 0.0; // Variable for converting voltage values
float formula = 0.0; // Variable for the voltage divider calculation formula
float r1 = 4650.0; // First resistor
float r2 = 2350.0; // Second resistor
float x = 1.56; // Basic power supply at input A0
const int delay_prog = 500; // Wait between processes
const int delay_end = 100; // Delay in the end of program

void setup() {
Serial.begin(9600); 
}

void loop() {
measure(); // Performance of input voltage measurement
delay(delay_prog);
search(); // Search and comparison of input current
delay(delay_prog);
}

void search() { // Determining the desired value of the input voltage
if (input_volt >= 0 && input_volt < 0.5) { // Device OFF condition
  Serial.println("0 ... 0.5");
  Serial.println("...");
  digitalWrite(PIN_LED, LOW);
  delay(delay_end);
} 
else if (input_volt >= 0.5 && input_volt < 1.3) { // Device ON condition
  Serial.println("0.5 ... 1.3");
  Serial.println("...");
  digitalWrite(PIN_LED, HIGH);
  delay(delay_end);
}
else if (input_volt >= 1.3 && input_volt < 2.5) { // Device OFF condition
  Serial.println("1.3 ... 2.5");
  Serial.println("...");
  digitalWrite(PIN_LED, LOW);
  delay(delay_end);
}
else if (input_volt >= 2.5 && input_volt < 3.5) { // Device ON condition
  Serial.println("2.5 ... 3.5");
  Serial.println("...");
  digitalWrite(PIN_LED, HIGH);
  delay(delay_end);
}
}

void measure() { // Function of calculation and transfer of input data
int analogvalue = analogRead(A0); // Reading data from port A0
float formula = r2/(r1+r2); // Calculate the voltage divider
data = (analogvalue * x) / 1024.0; // Voltage conversion
input_volt = data / formula; // Calculate the input voltage

Serial.print("analogvalue = "); 
Serial.println(analogvalue);
Serial.print("Voltage= ");
Serial.println(input_volt);
}