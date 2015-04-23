void main() {
     trisa = 0b00011111;
     adcon0 = 0b00010001;  //Define AN2 como sinal de entrada (Bits 5 - 3)
     adcon1 = 0b01000011;  /* Define:
                            *  Voltagem de referencia como AN3 [ LIGADO NO AN1 ]
                            *  AN1 [TRIMPOT] como entrada analógica
                            *  AN2 [Saída do sensor] como entrada anaógica
                            */
     while(1);
     
}
