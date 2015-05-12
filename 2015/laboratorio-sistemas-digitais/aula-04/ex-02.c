void setup();
void rodaContador();
int converterNumero(int numero);
void mostraNumero(int numero, int display);
int obterBotaoPressionado();
void exibeNumero();


int main(){
  int pressionado;
  int ultimo_pressionado;

  setup();
  

  while(1){

      pressionado = obterBotaoPressionado();
      if(pressionado != ultimo_pressionado && pressionado != 0){

          ultimo_pressionado = pressionado;


      }

      exibeNumero(ultimo_pressionado);

  }


  return 0;
}

int obterColunaBotaoSelecionado(){

    if(portd.rd3 == 1){
          delay_ms(10);
          if(portd.rd3 == 1){

              return 1;

          }
    }


    if(portd.rd2 == 1){
          delay_ms(10);
          if(portd.rd2 == 1){

              return 2;

          }
    }


    if(portd.rd1 == 1){
          delay_ms(10);
          if(portd.rd1 == 1){

              return 3;

          }
    }

    if(portd.rd0 == 1){
          delay_ms(10);
          if(portd.rd0 == 1){

              return 4;

          }
    }

    return 0;


}

int obterValorMatrizBotoes(int rb, int coluna){

    switch(rb){

        case 0:
            switch(coluna){
                case 1:
                    return 1;
                case 2:
                    return 5;
                    break;
                case 3:
                    return 9;
                    break;
                case 4:
                    return 13;
            }
            break;
        case 1:
            switch(coluna){
                  case 1:
                      return 2;
                  case 2:
                      return 6;
                      break;
                  case 3:
                      return 10;
                      break;
                  case 4:
                      return 14;
              }
              break;

        case 2:
              switch(coluna){
                  case 1:
                      return 3;
                  case 2:
                      return 7;
                      break;
                  case 3:
                      return 11;
                      break;
                  case 4:
                      return 15;
              }
              break;


    }

}

int obterBotaoPressionado(){
    int col;

    portb.rb0 = 1;
    col = obterColunaBotaoSelecionado();
    if(col > 0){

        return obterValorMatrizBotoes(0,col);

    }
    portb.rb0 = 0;

    portb.rb1 = 1;
    col = obterColunaBotaoSelecionado();
    if(col > 0){

        return obterValorMatrizBotoes(1,col);

    }
    portb.rb1 = 0;

    portb.rb2 = 1;
    col = obterColunaBotaoSelecionado();
    if(col > 0){

        return obterValorMatrizBotoes(2,col);

    }
    portb.rb2 = 0;

    //Se não for nenhuma nas três primeiras, é na última
    if(portd.rb3 == 1){
          delay_ms(10);
          if(portb.rd3 == 1){

              return 4;

          }
    }


    if(portd.rb2 == 1){
          delay_ms(10);
          if(portd.rb2 == 1){

              return 8;

          }
    }


    if(portd.rb1 == 1){
          delay_ms(10);
          if(portd.rb1 == 1){

              return 12;

          }
    }

    if(portd.rb0 == 1){
          delay_ms(10);
          if(portd.rb0 == 1){

              return 16;

          }
    }





}

/**
 * Transforma um número gerado no processador em um número que
 * possa ser exibido no display.
 * vamos diminuindo o valor casa a casa utilizando divisões.
 * O número inteiro vai guardar o resultado da divisão, e este será o numero representante da casa
 * Tendo o número que representa a casa, levamos ele de volta para sua casa e subtraimos ele do total,
 * assim, conseguimos eliminar uma casa e ir para a próxima.
 */
void exibeNumero(int numero){
    int dig_1 = 0;
    int dig_2 = 0;
    int dig_3 = 0;
    int dig_4 = 0;

    if(numero > 1000){
        dig_1 = numero / 1000;
        numero = numero - (dig_1 * 1000);
    }else{
        dig_1 = 0;
    }

    if(numero > 100){
        dig_2 = numero / 100;
        numero = numero - (dig_2 * 100);
    }else{
        dig_2 = 0;
    }

    if(numero > 10){
        dig_3 = numero / 10;
        numero = numero - (dig_3 * 10);
    }else{
         dig_3 = 0;
    }

    dig_4 = numero;

    mostraNumero(dig_1,4);
    mostraNumero(dig_2,3);
    mostraNumero(dig_3,2);
    mostraNumero(dig_4,1);

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

  trisb.rb0 = 0;
  trisb.rb1 = 0;
  trisb.rb2 = 0;
  trisb.rb3 = 0;

  trisd = 0;
  portd = 255;
}
