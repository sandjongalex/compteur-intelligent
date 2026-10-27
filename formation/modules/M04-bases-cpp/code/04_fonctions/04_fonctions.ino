/*
 * AlexTech Academy — M04-V02
 * Conversion Watts -> kilowatts, exemples FICTIFS.
 */
float wattsVersKilowatts(float watts) {
  return watts / 1000.0f;
}

void setup() {
  Serial.begin(9600);

  Serial.print("500 W = ");
  Serial.print(wattsVersKilowatts(500.0f), 2);
  Serial.println(" kW"); // 0.50 kW

  Serial.print("1250 W = ");
  Serial.print(wattsVersKilowatts(1250.0f), 2);
  Serial.println(" kW"); // 1.25 kW
}

void loop() {}
