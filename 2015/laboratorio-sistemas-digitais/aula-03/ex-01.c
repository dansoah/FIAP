//Controle de status do botão	
int btn_status = 0;

void main() {

    //Definindo portas D como saída
    trisd = 0b00000000;
    portd = 0x00;
    
    //Definindo rb0 como entrada
    trisb.rb0 = 1;
    portb.rb0 = 1;

    
    while(1){

        if(portb.RB0 == 1){

             delay_ms(10);
             if(portb.RB0 == 1){
                 if(btn_status == 0)
                     portd = ~portd;
                 btn_status = 1;
             }

        }else{

             btn_status = 0;
        }
        
        
    
    }

}
