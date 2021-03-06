;1. ELABORAR UM FIRMWARE COM AS SEGUINTES CARACTERÍSTICAS:
;- BOTÃO RB3 PRESSIONADO = LED D0 ACESO
;- BOTÃO RB3 LIBERADO = LED D0 APAGADO
;- BOTÃO RB4 PRESSIONADO = LED D1 APAGADO
;- BOTÃO RB4 LIBERADO = LED D1 ACESO

#INCLUDE <P18F452.INC>

#DEFINE btnRB3 PORTB,3
#DEFINE btnRB4 PORTB,4

#DEFINE ledD0 PORTD,0
#DEFINE ledD1 PORTD,1

ORG 0x00

GOTO SETUP

SETUP
	CLRF PORTD
	MOVLW B'00011000'
	MOVWF TRISB
	MOVLW B'00000000'
	MOVWF TRISD

CHECK_RB3
	BTFSC btnRB3
	GOTO SWITCH_OFF_D0
	GOTO SWITCH_ON_D0

SWITCH_OFF_D0
	BCF ledD0
	GOTO CHECK_RB4

SWITCH_ON_D0
	BSF ledD0
	GOTO CHECK_RB4

CHECK_RB4
	BTFSC btnRB4
	GOTO SWITCH_ON_D1
	GOTO SWITCH_OFF_D1

SWITCH_OFF_D1
	BCF ledD1
	GOTO CHECK_RB3

SWITCH_ON_D1
	BSF ledD1
	GOTO CHECK_RB3

END
