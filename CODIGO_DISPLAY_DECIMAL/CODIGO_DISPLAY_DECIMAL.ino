/*Definición de pines de entrada y salida*/
int val_input=0;
int decenas=0;
int unidades=0; 
void setup() {
  DDRA = 0x00;
  DDRF = 0xFF;
  DDRH = 0xFF;
}

void loop() {
  val_input = PINA;
  decenas = val_input/10;
  unidades = val_input%10;
  PORTF = decenas;
  PORTH = unidades;
}
