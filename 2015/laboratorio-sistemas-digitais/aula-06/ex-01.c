void setup();
void rodaContador();
int converterNumero(int numero);
void mostraNumero(int numero, int display);
int obterTemperatura();

int main(){
  int temp = 0;
  setup();
  
  while(1){


    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    int d4 = 0;

    temp = obterTemperatura();
    
    if(temp > 0){
      d1 = 1;
    }
    
    if(temp>10)
       d1 = 2;


    mostraNumero(d1,4);
    mostraNumero(d2,3);
    mostraNumero(d3,2);
    mostraNumero(d4,1);
  }


  return 0;
}

int obterTemperatura(){

    adcon0.go = 1; //Inicia conversão

    while (adcon0.go == 1){}//Espera conversão terminar

    return adresh; //Retorna o valor da conversão (0-255)
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
