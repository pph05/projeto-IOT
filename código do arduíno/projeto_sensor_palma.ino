#define sensor 10
#define rele 11

int palmas = 0;
boolean tempalmas = true;
boolean contapalma = true;
unsigned long tempo = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(rele, OUTPUT);
 

  digitalWrite(rele, LOW);
}

void loop() {
  tempalmas = digitalRead(sensor);

  if(!tempalmas){
    if(contapalma){
      palmas++;
      tempo = millis();
      contapalma = false;
    }
  
    else{
      if(millis() - tempo > 200){
        contapalma = true;
      }
    }
  }

  if(millis() - tempo > 400){
    switch(palmas){
      case 1:
      digitalWrite(rele, HIGH);
      break;

      case 2:
      digitalWrite(rele, LOW);
      break;
    }
    palmas = 0;
  }
}