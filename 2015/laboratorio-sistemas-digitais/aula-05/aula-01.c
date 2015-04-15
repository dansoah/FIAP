Manda_para_LCD(char INS_DATA, char DATA_LCD_0){

  if (INS_DATA == 0){
     porte.re2 = 0;
  }
  if(INS_DATA != 0){
      porte.re2 = 1;
  }

  portd = DATA_LCD_0;

  porte.re1 = 1;
  delay_us(100);
  porte.re1 = 0;
  delay_us(100);


}


  void main(){

  trisd = 0;  //'configura todos os pinos do portd como saída
  trisb = 0;  //'configura todos os pinos do portb como saída
  trise = 0;  //'configura todos os pinos do porte como saida
  ADCON1 = 0X06;

  Manda_para_LCD (0, 0b00111000);
  Delay_ms(50);
  Manda_para_LCD (0, 0b00000110);
  Delay_ms(50);
  Manda_para_LCD (0, 0b00001111);
  Delay_ms(50);
  Manda_para_LCD (0, 0b00000001);
  Delay_ms(50);
  Manda_para_LCD (0, 0b00001100);
  Delay_ms(50);
  Manda_para_LCD (0, 0b00000001);
  Delay_ms(50);


  Manda_para_LCD (0, 0b10000000);
  Delay_ms(50);

  Manda_para_LCD (1, 0b00110001);
  Delay_ms(50);

  while (1){}
  }
