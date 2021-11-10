#define F_CPU 8000000UL

#include <avr/io.h>

void PORT_INIT(void);
void ADC_INIT(void);
void TIMER_INIT(void);
uint16_t ADC_CONVERSION(void);

int main(void){
	PORT_INIT();
	ADC_INIT();
	TIMER_INIT();
	uint16_t result = 0;
	
	while(1){
		result = ADC_CONVERSION();
		OCR1A = 1000 + result*4.2228739;			///< Convert ADC result to a PWM signal corresponding to an angle.
	}
}

/*!
 *	@brief Initialize Ports.
 */

void PORT_INIT(void){
	DDRD |= (1<<PD5);						///< Set OC1A as output to generate PWM signal.
}

/*!
 *	@brief Initialize ADC.
 */

void ADC_INIT(void){
	ADMUX = (1<<REFS0);						///< Set ADC reference to AVCC and analog input mode to single-ended input of ADC0.
	ADCSRA = ((1<<ADEN)|(1<<ADPS2)|(1<<ADPS1));			///< Enable ADC and set ADC prescalar to 64.
}

/*!
 *	@brief Initialize timer/counter1 to generate a 50 Hz Fast PWM signal at OC1A.
 */

void TIMER_INIT(void){
	TCCR1A = (1<<COM1A1)|(1<<WGM11);				///< Select Fast PWM mode with ICR1 as TOP. Clear OC1A on compare match and Set OC1A at BOTTOM (non-inverting mode).
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS11);			///< Select Fast PWM mode with ICR1 as TOP and set prescalar value of 8.
	ICR1 = 19999;							///< Set TOP value to determine frequency of the PWM signal.
}

/*!
 *	@brief Perform an ADC conversion.
 *	@return Result of ADC conversion (uint16_t).
 */

uint16_t ADC_CONVERSION(void){
	ADCSRA |= (1<<ADSC);						///< Start ADC conversion.
	while(ADCSRA & (1<<ADSC));					///< Wait until conversion is complete.
	return ADC;							///< Return result of conversion.
}
