# Conexa-oMQTT
Conexão de um esp32 com uma máquina local utilizando o Mosquitto
O protocolo MQTT é um protocolo de transporte de mensagens baseado no conceito de publicação / assinatura, isto significa, que um cliente pode publicar uma mensagem em específico que será enviada ao corretor e outro cliente pode ter acesso a esta mensagem fazendo a assinatura neste tópico . O MQTT é principalmente utilizado devido a sua facilidade de aplicação e por ser um protocolo leve e aberto, porém, possui limitações de tamanho de pacotes e largura de banda.  
Neste algoritimo o esp32 atua como Publisher e envia uma mensagem que será recebida pela máquina local (Assinante) assim que realizar a assinatura no tópico referente à mensagem, esta assinatura é possível através do comando mosquitto_sub -t teste / esp / 1245 pelo terminal.

<img scr="raissa/imagens/mqtt.mosquito.png" alt="My cool logo">
