/*
	ADC_IN0		ARD A0		PA0
	ADC_IN8		ARD A1		PF10
	ADC_IN7		ARD A2		PF9
	ADC_IN6		ARD A3		PF8

	PF9 is ADC3_IN7 accessed by ARD A2
 */

#include "adc.h"


#define GPIO_F_EN		(1U<<5)
#define ADC3_EN			(1U<<10)
#define CR2_CONT		(1U<<1)
#define SEQ_LENGTH_1	0
#define CR2_AD_ON		(1U<<0)
#define CR2_SWSTART		(1U<<30)
#define CR1_EOCIE		(1U<<5)

void pf9_adc3_init(void)
{
	/***** Configure ADC GPIO Pin *****/

	/***** Enable Clock Access to GPIO F *****/
	// GPIO F is connected to AHB1 Bus
	// F is Pin 5 in the AHB1ENR
	RCC->AHB1ENR |= GPIO_F_EN;


	/***** Set PF9 as analog mode *****/
	// Moder for Pin 9 = 18, 19
	// Analog Mode = 0x11
	GPIOF->MODER |= (1U<<19);
	GPIOF->MODER |= (1U<<18);


	/***** Configure ADC Module *****/
	// Enable Clock Access to ADC3
	// ADC3 is connected to the APB2 Bus
	// APB2ENR Pin 10 = ADC3 Enable
	RCC->APB2ENR |= ADC3_EN;

	/***** Set Conversion-Mode to Continuous *****/
	// If Bit 1 (CONT) is set to 1, Continuous is Enabled
	ADC3->CR2 &=~ CR2_CONT;

	/***** Set sequencer length to 1 *****/
	// L occupies bits 20, 21, 22, 23
	ADC3->SQR1 = SEQ_LENGTH_1;

	/***** Set ADC Channel *****/
	// Setting ADC3's Channel 7 (0x111)
	// as First Priority (SQ1) in the SQR3 Register
	ADC3->SQR3 |= (1U<<2);
	ADC3->SQR3 |= (1U<<1);
	ADC3->SQR3 |= (1U<<0);

	/***** Enable ADC Module *****/
	ADC3->CR2 |= CR2_AD_ON;

	/***** Begin Conversion *****/
	ADC3->CR2 |= CR2_SWSTART;
}

uint32_t adc_get_data(void)
{
	// Wait for End-Of-Conversion Flag
	while (!(ADC3->SR & SR_EOC)) {}

	return (ADC3->DR);

	// Read & Return results
}

void pf9_adc3_interrupt_init(void)
{
	/***** Configure ADC GPIO Pin *****/

	/***** Enable Clock Access to GPIO F *****/
	// GPIO F is connected to AHB1 Bus
	// F is Pin 5 in the AHB1ENR
	RCC->AHB1ENR |= GPIO_F_EN;


	/***** Set PF9 as analog mode *****/
	// Moder for Pin 9 = 18, 19
	// Analog Mode = 0x11
	GPIOF->MODER |= (1U<<19);
	GPIOF->MODER |= (1U<<18);


	/***** Configure ADC Module *****/
	// Enable Clock Access to ADC3
	// ADC3 is connected to the APB2 Bus
	// APB2ENR Pin 10 = ADC3 Enable
	RCC->APB2ENR |= ADC3_EN;

	/***** Set Conversion-Mode to Continuous *****/
	// If Bit 1 (CONT) is set to 1, Continuous is Enabled
	ADC3->CR2 |= CR2_CONT;

	/***** Set sequencer length to 1 *****/
	// L occupies bits 20, 21, 22, 23
	ADC3->SQR1 = SEQ_LENGTH_1;

	/***** Set ADC Channel *****/
	// Setting ADC3's Channel 7 (0x111)
	// as First Priority (SQ1) in the SQR3 Register
	ADC3->SQR3 |= (1U<<2);
	ADC3->SQR3 |= (1U<<1);
	ADC3->SQR3 |= (1U<<0);

	/***** Enable ADC Module *****/
	ADC3->CR2 |= CR2_AD_ON;

	/***** Enable End-Of-Conversion Interrupt *****/
	ADC3->CR1 |= CR1_EOCIE;

	/***** Enable ADC Interrupt in NVIC *****/
	NVIC_EnableIRQ(ADC_IRQn);

	/***** Begin Conversion *****/
	ADC3->CR2 |= CR2_SWSTART;
}
