//Chamando a biblioteca do LCD
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); // Portas do LCD

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(8, INPUT); // definindo como entrada porta 8
  Serial.begin(9600); 
  lcd.begin(16,2); //Ligando o LCD
  pinMode(9, OUTPUT); // definindo como saída porta 9
}

void loop()
{
  // Código para transformar o sinal sensor 1 em centimetros 
  long duration, cm;
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  digitalWrite(8, HIGH);
  delayMicroseconds(5);
  digitalWrite(8, LOW);
  
  pinMode(8, INPUT);
  duration = pulseIn(8, HIGH);
  
  cm = microsecondsToCentimeters(duration);
  
  // Print no serial da distancia em centimetros
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.print("CM");
  Serial.println();
  
   // Print da distancia no visor 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Protitipo");
  lcd.setCursor(0,1);
  lcd.print("Distancia:");
  lcd.print(cm);
  lcd.print("cm");
  delay(2000);
  
  if (cm < 30) { // Caso distancia seja menor que 30cm
  	digitalWrite(9, HIGH); // Sinal 1 para porta 9
  }
  
  else {				   // Caso contrario
  	digitalWrite(9, LOW);  // Sinal 0 para porta 9
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
  }