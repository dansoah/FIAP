void setup();
void rodaContador();
int converterNumero(int numero);
void mostraNumero(int numero, int display);


int main(){

  setup();
  rodaContador();


  return 0;
}

void rodaContador(){
    int contador = 0;
    while(1){
        mostraNumero(contador,1);
        delay_ms(1000);
        contador++;
    }

}

/**
 * Desenha número no display da placa
 * numero: número a ser exibido
 * display: display a ser utilizado
 */
void mostraNumero(int numero, int display){

    switch(display){

        case 1:
          PORTD = converterNumero(numero);
          porta.ra2 = 1;
          delay_ms (1);
          porta.ra2 = 0;
          break;
        case 2:
          PORTD = converterNumero(numero);
          porta.ra3 = 1;
          delay_ms (1);
          porta.ra3 = 0;
          break;

    }

}
/**
 * Converte um número DECIMAL para o binário
 * correspondente no display de 7 segmentos
 */
int converterNumero(int numero){
    switch(numero){
      case 0:
          return 0b00000110;
      case 1:
          return 0b00000110;
      case 2:
          return 0b01011011;
      case 3:
          return 0b01001111;
      case 4:
          return 0b01100110;
      case 5:
          return 0b01101101;
      case 6:
          return 0b01111100;
      case 7:
          return 0b00000111;
      case 8:
          return 0b01111111;
      case 9:
          return 0b01100111;
      default:
          return 0b01111001;
    }
}
/**
 * Inicializa as variáveis do programa
 *
 */
void setup(){

  adcon1 = 0b00000110;

  trisa.ra2 = 0;
  porta.ra2 = 0;

  trisa.ra3 = 0;
  porta.ra3 = 0;

  trisa.ra4 = 0;
  porta.ra4 = 0;

  trisa.ra5 = 0;
  porta.ra5 = 0;

  trisd = 0;
  portd = 255;
}
