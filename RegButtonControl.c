  RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOCEN);


	GPIOC->MODER &= ~(3 << (13 * 2)); // Input mode for button
	GPIOC->PUPDR &= ~(3 << (13 * 2)); // Optional: disable pull up/down


	GPIOC->MODER &= ~(3 << (5 * 2)); // Clear bits for LED
	GPIOC->MODER |= (1 << (5 * 2)); // Set bits for LED


 while (1) {
 
	 if ((GPIOC->IDR & (1 << 13)) == 0) { // Check if button is pressed, 0 is low
		 GPIOA->ODR |= (1 << 5); // LED on when button pressed
	 }
	 else {
		 GPIOA->ODR &= ~(1 << 5); // LED off when button not pressed
	 }
 }
