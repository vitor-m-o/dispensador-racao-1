# Dispensador de Ração Online
# Descrição do projeto:
-  Dispensador de Ração que despeja ração utilizando um ESP-32 e um servo que são acionados de forma online
-  O ESP-32 lê o valor da variavel que está no arquivo servo_control.json e assim despeja ração se o valor for equivalente a 1, caso contrario não faz nada
-  A variavel que determina a função do ESP-32 deveria ser manipulada pelo site HTML, porém ainda estou trabalhando nisso
-  Será disponibilizado no futuro um arquivo do desenho técnico e o modelo 3D para a parte física do projeto no futuro

# Arquivos:
- ESP32-SERVO.ino -> O código que está no ESP32 para ler o valor da variavel do arquivo servo_control.json do github e controlar o servo
- index.html -> O código do site em HTML que supostamente controlaria a variavel do arquivo servo_control.json
- servo_control.json -> Arquivo que possuí a variavel utilizada para o ESP32 ler e assim mover o servo, e também para o site HTML manipula-la
- .github/workflows/update-json.yml -> Suposto workflow que faria o commit e o push da alteração do valor da variavel do arquivo servo_control.json

# Bibliotecas utilizadas no código do ESP32:
- Bibliotecas instaladas diretamente da IDE Arduino. Creditos aos seus devidos criadores.
- Wifi
- HTTPClient
- ArduinoJson
- ESP32Servo

# Linguagem utilizada:
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/arduino/arduino-original.svg" width="115" height="115"/>

# Autor:

[<img loading="lazy" src="https://avatars.githubusercontent.com/u/110566021?v=4" width=115><br><sub>Vítor Maziero Oliveira</sub>](https://github.com/vitor-m-o)
