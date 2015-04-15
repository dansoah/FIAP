int btn_add_status = 0;
int btn_dec_status = 0;
int contador = 0;

int decrementIsPressed(){
    if(portb.rb1 == 1 && portb.rb0 == 1){

        return 1;

    }

    return 0;
}

int incrementIsPressed(){
    if(portb.rb1 == 1 && portb.rb0 == 0){
    
        return 1;
    
    }
    
    return 0;
}

int resetIsPressed(){
    if(portb.rb0 == 1 && portb.rb1 == 0){

        return 1;

    }

    return 0;
}

void main() {

    //Definindo portas D como saída
    trisd = 0b00000000;
    portd = 0x00;

    //Definindo rb0 como entrada
    trisb.rb0 = 1;
    portb.rb0 = 1;
    
    //Definindo rb1 como entrada
    trisb.rb1 = 1;
    portb.rb1 = 1;


    while(1){

        //Fazendo incremento
        if(incrementIsPressed()==1){
            
            delay_ms(10);
            if(incrementIsPressed() == 1){
                if(btn_add_status == 0){
                     contador++;
                     btn_add_status = 1;
                }
                if(contador > 255)
                    contador = 0;
                portd = contador;
            }else{
                btn_add_status = 0;
            }

        
        }
        
        //Fazendo decremento
        if(decrementIsPressed() == 1){
        
            delay_ms(10);
            if(decrementIsPressed() == 1){
				
				if(btn_dec_status == 0){
                     contador--;
                     btn_dec_status = 1;
                }
                if(contador < 0)
                    contador = 255;
                portd = contador;
            
            }
        
        }else{
			btn_dec_status = 0;
		}
        
        //Fazendo reset
        if(resetIsPressed() == 1){
        
            delay_ms(20);
            if(resetIsPressed() == 1){
                contador = 0;
                portd = contador;
                btn_add_status = 1;

            }else{
            
                btn_add_status = 0;
            
            }
        
        }

    }

}
