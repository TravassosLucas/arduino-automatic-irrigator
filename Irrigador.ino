#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // define os pinos do lcd

int umidadePin = A0;  
int pinoRele = 8;     

void setup() {
  pinMode(pinoRele, OUTPUT);  // define o relé como saída
  lcd.begin(16, 2); // Inicia o LCD
}

void loop() {
  int umidade = analogRead(umidadePin);  //le o valor do sensor
  int porcento = map(umidade, 0, 1023, 0, 100);  //converter o valor lido em porcentagem

  lcd.clear();  // da um clear no display
  lcd.setCursor(0,0);  // bota na posição inicial 
  lcd.print("Umidade: ");  // bota o texto no display
  lcd.print(porcento); 
  lcd.print("%");

  //é invertido a leitura da porcentagem da umidade conforme abaixo:

  if (porcento >= 45) {  // Se a porcentagem for maior ou igual a 45
    Serial.println("Irrigando a planta...");  // aparece a frase no monitor serial
    lcd.setCursor(0,1);  // bota pra a segunda linha do display
    lcd.print("Irrigando...");  // mostra o texto no display
    digitalWrite(pinoRele, HIGH);  // Liga o relé
    delay(5000);  // Espera 5 segundos
    digitalWrite(pinoRele, LOW);  // Desliga o relé
  }
  else {  // Se a porcentagem for menor que 45
    Serial.println("Planta irrigada...");  
    lcd.setCursor(0,1);  // bota na posição de baixo no display
    lcd.print("Planta irrigada");  // mostra o texto no display
    digitalWrite(pinoRele, LOW);  //desliga o  relé
  }
  delay(3000);  // verifica a cada 30 segundos
}

//criado por lucas travassos 2023

