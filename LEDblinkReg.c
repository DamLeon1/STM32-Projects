  RCC->AHB2ENR |= (1 << 0); // CLOCK

  GPIOA->MODER &= (3 << (5 * 2)); // Clear bits
 	GPIOA->MODER |= (1 << (5 * 2)); // Set bits

 	GPIOA->PUPDR &= ~(3 << (5 * 2)); // Clear
 	GPIOA->PUPDR |=  (1 << (5 * 2)); // Set

while (1) {

 	GPIOA->ODR |= (1 << 5); // Pin set high
 	HAL_Delay(1000);
 	GPIOA->ODR &= ~(1 << 5); // Pin set low
 	HAL_Delay(1000);
}
