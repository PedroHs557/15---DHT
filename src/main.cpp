#include <Arduino.h>
#include <DHT.h>

#define PINO_DHT 5
#define TIPO_DHT DHT22

DHT dht(PINO_DHT, TIPO_DHT);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("==== Sensor DHT 22 ====");
  dht.begin();
  Serial.println("Sensor iniciado");
  Serial.println("=======================");
}

void loop()
{
  delay(2000);

  float umidade = dht.readHumidity();
  float tempCelsius = dht.readTemperature();
  float tempFahrenheit = dht.readTemperature(true);

  if (isnan(umidade) || isnan(tempCelsius))
  {
    Serial.println("Falha ao iniciar o sensor");
    Serial.println("Verifique a conexão e o pino definido");
    return;
  }

  float sensacaoTerm = dht.computeHeatIndex(tempCelsius, umidade, false);

  Serial.printf("Temperatura: %.1f °C | %.1f °F\n\f", tempCelsius, tempFahrenheit);
  Serial.printf("Umidade: %.0f %\n\f", umidade);
  Serial.printf("Sensação térmica: %.1f °C\n\f", sensacaoTerm);
  Serial.print("\n---------------------------------------\n");
}
