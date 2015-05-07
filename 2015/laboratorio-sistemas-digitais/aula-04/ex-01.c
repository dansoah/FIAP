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

     
    int contador_4 = 0;
    int contador_3 = 0;
    int contador_2 = 0;
    int contador_1 = 0;
      delay_ms(100);
      
    while(1){

        mostraNumero(contador_1,4);
        mostraNumero(contador_2,3);
        mostraNumero(contador_3,2);
        mostraNumero(contador_4,1);
        delay_ms(10);
        
        contador_1++;
        if(contador_1 > 9){
            contador_1 = 0;
            contador_2++;
        }
        
        if(contador_2 > 9){
        
            contador_2 = 0;
            contador_3++;
        
        }
        
        if(contador_3 > 9){
        
            contador_3 = 0;
            contador_4 ++;
        
        }
        
        if(contador_4 > 9){
             contador_1 = 0;
             contador_2 = 0;
             contador_3 = 0;
             contador_4 = 0;
        }

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
        case 3:
          PORTD = converterNumero(numero);
          porta.ra4 = 1;
          delay_ms (1);
          porta.ra4 = 0;
          break;
        case 4:
          PORTD = converterNumero(numero);
          porta.ra5 = 1;
          delay_ms (1);
          porta.ra5 = 0;
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
          return 0b00111111;
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
