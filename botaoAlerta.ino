//IURI BOIOLAUM
//VERSAO TETA
#include <SoftwareSerial.h>


                              //Entradas
int const botaoP = 2;         //pino para botao de "panico"

                              //Saidas
int const alarme = 3;         //pino para acionamento de alarme (led, buzzers ...)

unsigned long const atraso = 3000;             //tempo mínimo que o botão deve ficar pressionado para disparar o alarme (3 segs)
unsigned long const tempoAcionado = 10000;      //tempo que o alarme se mantera acionado (10 segs) - Verificar tempo. 
//unsigned long tempoAtual = 0;                //tempo atual que sera capturado pela funcao millis()
unsigned long tempoDecorrido = 0;              //tempo decorrido que sera capturado pela funcao millis()

void alerta();

int temporizador();

void setup(){
  
  //Declaracao dos pinos de entrada
  pinMode(botaoP, INPUT);

  //Declaracao de pinos de saida
  pinMode(alarme, OUTPUT);
 
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(botaoP) == HIGH)                        //Chama a funcao alerta se botao de panico for acionado
  alerta();
  tempoDecorrido = millis();                             //Salva o tempo decorrido fim de execucao do codigo
}

void alerta(){
  if(temporizador()){
    digitalWrite(alarme, HIGH);            //Aciona o alarme
    delay(tempoAcionado);                  //Tempo que o alarme se mantera acionado
    digitalWrite(alarme, LOW);             //Desaciona alarme
  }
  else
    digitalWrite(alarme, LOW);
  
}

int temporizador(){                                      //Funcao que mede tempo decorrido entre acionamentos
  unsigned long tempoAtual = millis();                   //Tempo atual que sera capturado pela funcao millis()
                                                         //Funcao millis() registra qual o tempo de execucao do programa no arduino
  
  if((tempoAtual - tempoDecorrido) >= atraso)
    return (1);                                          //Se passou 3 segs apos ultimo acionamento, retorna (1 = verdadeiro)
  else
    return (0);                                          //Caso contrario retorna (0 = falso)
}
//Funcao millis() -> https://www.arduino.cc/en/Reference/Millis
