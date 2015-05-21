void LCD(char tipo, char dados){

    if(tipo == 0){
        porte.re2 = 0;
    }else{
        porte.re2 = 1;
    }

    portd = dados;

    //submit
    porte.re1 = 1;
    delay_us(100);
    porte.re1 = 0;
    delay_us(100);
    delay_ms(20);

}

void limpaLCD(){

    LCD(0,0b00000001);

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

    mostraNumero(dig_1);
    mostraNumero(dig_2);
    mostraNumero(dig_3);
    mostraNumero(dig_4);

}

/**
 * Desenha número no display da placa
 * numero: número a ser exibido
 * display: display a ser utilizado
 */
void mostraNumero(int numero){

    LCD(1,converterNumero(numero));

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

int setup(){

    trisd = 0; //Porta D será uma saída
    trisb.rb0 = 1; //rb0 será uma entrada
    trisb.rb1 = 1; //rb1 será uma entrada
    trise = 0; //Porta E será uma saída

    ADCON1 = 0x06; //Define modo de conversão analógica -> digital

}

int setupLCD(){


    LCD(0,0b00111000);
    LCD(0,0b00101000);
    LCD(0,0b00000110);
    LCD(0,0b00001111);
    LCD(0,0b00000001);
    LCD(0,0b00001100);
    LCD(0,0b00000001);
    clearLCD();
    LCD(0,0b10000000);


}

int stopIsPressed(){
    if(portb.rb0 == 1){

        return 1;

    }

    return 0;
}

int startIsPressed(){
    if(portb.rb1 == 1){

        return 1;

    }

    return 0;
}

int main(){
    int contador = 0;
    int stop = 0;

    setup();
    setupLCD();

    while(1 == 1){


        exibeNumero(contador);

        if(stop == 0)
            contador++;

        if(contador > 9999)
            contador = 0;

        if(resetIsPressed()){
            contador = 0;
        }

        if(stopIsPressed()){

            if(stop == 0)
                stop = 1;
            else
                stop = 0;
        }

        if(stop == 0)
            delay_ms(1000);
        else
            delay_ms(100);

    }


    return 0;
}
