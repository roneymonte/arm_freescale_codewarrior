/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

void delay (unsigned  int atraso);
void delay (unsigned  int atraso)
{
	unsigned int contador = 0;
	for (contador=0;contador<atraso;contador++);
}

int main(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	PORTD_PCR1 = PORT_PCR_MUX(1);
	
	// coloca o estado do led em 1
	GPIOB_PSOR |= (1<<18)|(1<<19);
	GPIOD_PSOR |= (1<<1);
	
	//Data Direction para os LEDs
	GPIOB_PDDR |= (1<<18);	// Configura o bit 18 como output (1) Vermelho
	GPIOB_PDDR |= (1<<19);	// Configura o bit 19 como output (1) Verde
	GPIOD_PDDR |= (1<<1);	// Configura o bit 1 como output (1)  Azul
	
	GPIOB_PCOR = (1<<18);
	GPIOB_PCOR = (1<<19);
	GPIOD_PCOR = (1<<1);
	delay (1000000);delay (1000000);delay (1000000);delay (1000000);
	delay (1000000);delay (1000000);delay (1000000);delay (1000000);
    GPIOB_PTOR = (1<<18);
    GPIOB_PTOR = (1<<19);
    GPIOD_PTOR = (1<<1);
    delay (250000);
    GPIOB_PTOR = (1<<18);
    GPIOB_PTOR = (1<<19);
    GPIOD_PTOR = (1<<1);
    delay (250000);
    GPIOB_PTOR = (1<<18);
    GPIOB_PTOR = (1<<19);
    GPIOD_PTOR = (1<<1);
    delay (250000);
    GPIOB_PTOR = (1<<18);
    GPIOB_PTOR = (1<<19);
    GPIOD_PTOR = (1<<1);
    delay (250000);
	
	  for (;;) {
		  
	      GPIOB_PTOR = (1<<18);
	      GPIOB_PTOR = (1<<19);
	      GPIOD_PTOR = (1<<1);
	      
	      delay (1000000);
		  
	      GPIOB_PCOR = (1<<18);	// liga (PSOR) vermelho
	      GPIOB_PSOR = (1<<19);	// desliga (PTOR) Verde
	      GPIOD_PSOR = (1<<1);	// desliga (PTOR) Azul
	      
	      delay (1000000);

	      GPIOB_PSOR = (1<<18);	// desliga (PSOR) vermelho
	      GPIOB_PCOR = (1<<19);	// liga (PTOR) Verde
	      GPIOD_PSOR = (1<<1);	// desliga (PTOR) Azul
	      
	      delay (1000000);

	      GPIOB_PSOR = (1<<18);	// desliga (PSOR) vermelho
	      GPIOB_PSOR = (1<<19);	// desliga (PTOR) Verde
	      GPIOD_PCOR = (1<<1);	// liga (PTOR) Azul
	      
	      delay (1000000);

	      GPIOB_PTOR = (1<<18);
	      GPIOB_PTOR = (1<<19);
	      GPIOD_PTOR = (1<<1);
	      
	      delay (1000000);


	  }
	
	return 0;
}
