#define BLYNK_TEMPLATE_ID "TMPL208Sd1kkf"
#define BLYNK_TEMPLATE_NAME "Control de ventilador"
#define BLYNK_AUTH_TOKEN "HfRFcFrBIHsxaYn_ptcJWL25e_t1Y1wz"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define RELEPIN 5

#define WIFI_SSID "Prueba"
#define WIFI_PASSWORD "pollofrito"
#define WIFI_CHANNEL 6
#define BME_SDA 21
#define BME_SCL 22


// Credenciales de Blynk
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASSWORD;

BlynkTimer timer;
Adafruit_BME280 bme;

void sendSensorData() {
  float temp = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F; // hPa

  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, pressure);

  // Encender RELE si la temperatura supera 28°C
  if (temp > 28) {
    //digitalWrite(LEDPIN, HIGH);
    Blynk.virtualWrite(V4, 1);
  } else {
    
    Blynk.virtualWrite(V4, 0);
  }

  Blynk.syncVirtual(V4);
}
int overRide = 0;
BLYNK_WRITE(V4) { 
  if (param.asInt() == 1) {
    overRide = HIGH;
  } else {
    overRide = LOW;
  }
  digitalWrite(RELEPIN, overRide);
}
void setup() {
  Serial.begin(115200);
  setupWifi();
  pinMode(RELEPIN, OUTPUT);
  digitalWrite(RELEPIN, LOW);
  Wire.begin(BME_SDA, BME_SCL);
  if (!bme.begin(0x76)) {
    Serial.println("No se encontró el BME280. Revisa conexiones!");
    while (1);
  }
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}

void setupWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);
  Serial.print("Connecting to WiFi ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}