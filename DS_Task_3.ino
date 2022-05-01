float input_volt = 0.0; // Variable for output
float data = 0.0; // Variable for converting voltage values
float formula = 0.0; // Variable for the voltage divider calculation formula
float r1 = 4650.0; // First resistor
float r2 = 2350.0; // Second resistor
float x = 1.56; // Basic power supply at input A0
const int buttonPin = 8; // Button coonect pin
const int delay_button = 20; // Delay to eliminate noise
const int delay_prog = 150; // Wait between processes
const int delay_end = 2000; // Delay in the end of program

void setup() {
pinMode(buttonPin, INPUT); // Button initialization
Serial.begin(9600); 
}

void loop() {
int buttonState = digitalRead(buttonPin); // Assign read data from the port
if (buttonState == HIGH) { // If the button is pressed - perform measurements
  delay(delay_button);
  measure(); // Performance of input voltage measurement
  buttonState = 0; // Resetting the value of the input variable
  delay(delay_prog);
  Serial.println("Please, measure it ");
  Serial.println(".");
} else { // Otherwise, wait for 150 ms
  delay(delay_prog);
  }
}

void measure() { // Function of calculation and transfer of input data
int analog_value = analogRead(A0); // Reading data from port A0
float formula = r2/(r1+r2); // Calculate the voltage divider
data = (analog_value * x) / 1024.0; // Voltage conversion
input_volt = data / formula; // Calculate the input voltage

Serial.print("Analog Value = "); 
Serial.println(analog_value);
Serial.print("Voltage = ");
Serial.println(input_volt);
delay(delay_end);
}