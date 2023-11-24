// DEFINICIÓN DE PINES: INSTRUCCIONES
#define LDA 22
#define ADDD 23
#define SUBB 24
#define OUT 25
#define HLT 26
#define MULL 27
#define DIVV 28
#define CALLL 29
#define RETURNN 30
#define INST5 31

// DEFINICIÓN PIN DIV_0
#define DIV0 36

// DEFINICIÓN DE PINES: CONTROL (CON)
#define RETURN 37
#define CALL 38
#define LA 39
#define EA 40
#define LB 41
#define LI 42
#define EI 43
#define LM 44
#define LO 45
#define EU 46
#define ER 47
#define CP 48
#define EP 49
#define ADD 50
#define SUB 51
#define MUL 52
#define DIV 53
#define EMOD 35
#define SM 34
// DEFINICIÓN VARIABLE DELAY
unsigned int delay_time = 50;
void setup() {
  // CONFIGURACIÓN PINES DE ENTRADA: INSTRUCCIONES
  pinMode(LDA, INPUT);
  pinMode(ADDD, INPUT);
  pinMode(SUBB, INPUT);
  pinMode(OUT, INPUT);
  pinMode(HLT, INPUT);
  pinMode(MULL, INPUT);
  pinMode(DIVV, INPUT);
  pinMode(CALLL, INPUT);
  pinMode(RETURNN, INPUT);
  pinMode(INST5, INPUT);
  pinMode(DIV0, INPUT);
  // CONFIGURACIÓN PINES DE SALIDA: CONTROL
  pinMode(LA,OUTPUT);
  pinMode(EA,OUTPUT);
  pinMode(LB,OUTPUT);
  pinMode(LI,OUTPUT);
  pinMode(EI,OUTPUT);
  pinMode(LM,OUTPUT);
  pinMode(LO,OUTPUT);
  pinMode(EU,OUTPUT);
  pinMode(ER,OUTPUT);
  pinMode(CP,OUTPUT);
  pinMode(EP,OUTPUT);
  pinMode(ADD,OUTPUT);
  pinMode(SUB,OUTPUT);
  pinMode(MUL,OUTPUT);
  pinMode(DIV,OUTPUT);
  pinMode(CALL,OUTPUT);
  pinMode(RETURN, OUTPUT);
  pinMode(EMOD,OUTPUT);
  pinMode(SM, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /* 
  PROCESO REPETITIVO: OBTENER DIRECCIÓN DE MEMORIA DE LA INSTRUCCIÓN ACTUAL, ALMACENARLA EN LA MAR, ACCEDER A LA DIRECCIÓN DE MEMORIA EN LA PROM, 
  ALMACENAR VALOR DE LA DIRRECCIÓN DE MEMORIA EN EL INSTRUCTION REGISTER Y REALIZAR INSTRUCCIÓN.
  */
  digitalWrite(EP,1);
  digitalWrite(LM,1);
  delay(delay_time);
  digitalWrite(LM,0);
  digitalWrite(EP,0);
  digitalWrite(ER,1);
  digitalWrite(LI,1);
  delay(delay_time);
  digitalWrite(LI,0);
  digitalWrite(ER,0);

  // QUE INSTRUCCIÓN REALIZAR SEGÚN LOS BITS MAS SIGNIFICATIVOS PROVENIENTES DEL INSTRUCTION REGISTER.
  if (digitalRead(LDA)==1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(delay_time);
    digitalWrite(LM,0);
    digitalWrite(EI,0);
    digitalWrite(ER,1);
    digitalWrite(LA,1);
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(ER,0);
  }
  if (digitalRead(ADDD)==1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(delay_time);
    digitalWrite(LM,0);
    digitalWrite(EI,0);
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    delay(delay_time);
    digitalWrite(LB,0);
    digitalWrite(ER,0);
    digitalWrite(ADD,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(ADD,0);
  }
  if (digitalRead(SUBB)==1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(delay_time);
    digitalWrite(LM,0);
    digitalWrite(EI,0);
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    delay(delay_time);
    digitalWrite(LB,0);
    digitalWrite(ER,0);
    digitalWrite(SUB,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(SUB,0);
  }
  if (digitalRead(OUT)==1){
    digitalWrite(EA,1);
    digitalWrite(LO,1);
    delay(delay_time);
    digitalWrite(LO,0);
    digitalWrite(EA,0);
  }
  if (digitalRead(HLT)==1){
    exit(1);
    return;
  }
  if (digitalRead(MULL)==1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(delay_time);
    digitalWrite(LM,0);
    digitalWrite(EI,0);
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    delay(delay_time);
    digitalWrite(LB,0);
    digitalWrite(ER,0);
    digitalWrite(MUL,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(MUL,0);
  }
  if (digitalRead(CALLL)==1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(delay_time);
    digitalWrite(LM,0);
    digitalWrite(EI,0);
    digitalWrite(ER,1);
    digitalWrite(CALL,1);
    delay(delay_time);
    digitalWrite(CALL,0);
    digitalWrite(ER,0);
  }
  if (digitalRead(RETURNN)==1){
    digitalWrite(RETURN,1);
    delay(delay_time);
    digitalWrite(RETURN,0);
  }

  if (digitalRead(DIVV)==1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(delay_time);
    digitalWrite(LM,0);
    digitalWrite(EI,0);
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    delay(delay_time);
    digitalWrite(LB,0);
    digitalWrite(ER,0);
    digitalWrite(DIV,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    if (digitalRead(DIV0)==1){
      exit(1);
      return;
    }
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(DIV,0);
  }
  /*
  if (digitalRead(INST5)==1){
    digitalWrite(EA,1);
    digitalWrite(LB,1);
    delay(delay_time);
    digitalWrite(LB,0);
    digitalWrite(EA,0);
    digitalWrite(MUL,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(MUL,0);
  }
  */
  if (digitalRead(INST5)==1){
    digitalWrite(EI,1);
    digitalWrite(LM,1);
    delay(delay_time);
    digitalWrite(LM,0);
    digitalWrite(EI,0);
    digitalWrite(ER,1);
    digitalWrite(LB,1);
    delay(delay_time);
    digitalWrite(LB,0);
    digitalWrite(ER,0);
    digitalWrite(EA,1);
    digitalWrite(SM,1);
    delay(delay_time);
    digitalWrite(SM,0);
    digitalWrite(EA,0);
    digitalWrite(DIV,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(DIV,0);
    digitalWrite(MUL,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(MUL,0);
    digitalWrite(EA,1);
    digitalWrite(LB,1);
    delay(delay_time);
    digitalWrite(LB,0);
    digitalWrite(EA,0);
    digitalWrite(EMOD,1);
    digitalWrite(LA,1);
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(EMOD,0);
    digitalWrite(SUB,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(delay_time);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(SUB,0);
  }
  digitalWrite(CP,1);
  delay(delay_time);
  digitalWrite(CP,0);
  
}
