RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOCEN);
 uint8_t led_state = 0;
 uint8_t button_current = 1;
 uint8_t button_prev = 1;


 GPIOC->MODER &= ~(3 << (13 * 2));
 GPIOC->PUPDR &= ~(3U << (13 * 2));
 GPIOC->PUPDR |=  (1U << (13 * 2));


 GPIOA->MODER &= ~(3 << (5 * 2));
 GPIOA->MODER |= (1 << (5 * 2));
 GPIOA->BSRR = (1U << (5 + 16)); // Start off LED off


 while (1) {
	  button_current = (GPIOC->IDR & (1U << 13)) ? 1 : 0;
	      /* Detect a NEW button press */
	      if (button_current == 0 && button_prev == 1) {
	          /* Toggle LED state */
	          led_state = !led_state;
	          if (led_state) {
	              /* LED ON */
	              GPIOA->BSRR = (1U << 5);
	          }
	          else {
	              /* LED OFF */
	              GPIOA->BSRR = (1U << (5 + 16));
	          }
	      }
	      /* Remember current button state */
	      button_prev = button_current;
 }
