//=====VITOR-MAZIERO-OLIVEIRA=====//
//=====GITHUB:VITOR-M-O=====//

//=====CODIGO-GERADO-PELO-CHAT-GPT=====//
//=====MODIFICADO-E-ANALISADO-POR-VITOR======//

// Bibliotecas utilizadas no código
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ESP32Servo.h>

// Defina as credenciais do Wi-Fi
const char* ssid = "Vitor";
const char* password = "vanessa07022002";

// Configuração do servo
Servo meuServo;
int posicaoServo = 0;  // Inicialize a posição do servo

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);
  
  // Conectar ao Wi-Fi
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }
  
  Serial.println("Conectado ao Wi-Fi!");
  
  // Iniciar o servo no pino 26 
  meuServo.attach(26);
}

void loop() {
  // Verificar se a conexão Wi-Fi está ativa
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // Defina a URL do arquivo JSON no GitHub (link raw do arquivo JSON)
    String url = "https://raw.githubusercontent.com/vitor-m-o/dispensador-racao-1/main/servo_control.json";
    
    // Iniciar a requisição GET
    http.begin(url);
    int httpCode = http.GET();
    
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      
      // Analisar o JSON
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);
      
      // Suponha que a variável no JSON seja "valorServo" e tenha um valor numérico
      int valorServo = doc["valorServo"];  // Obter o valor da variável do JSON

      if (valorServo == 1)
      {
        meuServo.write(180);
        delay(500);
        meuServo.write(0);
        delay(900000);
      }
      else
      {
        meuServo.write(0);
      }
    } else {
      Serial.println("Erro ao acessar o arquivo JSON");
    }
    
    http.end();
  } else {
    Serial.println("WiFi não conectado");
  }
  
  delay(5000);  // Aguardar 5 segundos antes de fazer nova requisição
}
