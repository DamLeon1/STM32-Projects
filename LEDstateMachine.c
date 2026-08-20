typedef enum {
 	OFF, SLOW, FAST
 } LED_State;
 RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOCEN);


 GPIOA->MODER &= ~(3 << (5 * 2));
 GPIOA->MODER |= (1 << (5 * 2));


 GPIOC->MODER &= ~(3 << (13 * 2));
 GPIOC->PUPDR &= ~(3 << (13 * 2));


 LED_State currentState = OFF;
 uint8_t currentButtonState = !(GPIOC->IDR & (1 << 13));
 static uint8_t lastButtonState = 0;
 
 while (1) {
	  currentButtonState = !(GPIOC->IDR & (1 << 13));
	  if (currentButtonState && !lastButtonState) {
	      switch (currentState) {
	    	  case OFF:
	    		  currentState = SLOW;
	    		  break;
	    	  case SLOW:
	    		  currentState = FAST;
	    		  break;
	    	  case FAST:
	    		  currentState = OFF;
	    		  break;
	      }
	    }


	  uint32_t currentTime = HAL_GetTick();
	  static uint32_t lastToggleTime = 0;


	  switch (currentState) {
	      	case OFF:
	          	GPIOA->BSRR = (1 << (5 + 16)); // Force PA5 LOW (Off)
	          	break;
	      	case SLOW:
	      		if (currentTime - lastToggleTime >= 500) {
	      		    GPIOA->ODR ^= (1 << 5);          // Toggle LED
	      		    lastToggleTime = currentTime;    // Reset timestamp
	      		}
	          	break;
	      	case FAST:
	      		if (currentTime - lastToggleTime >= 100) {
	      		    GPIOA->ODR ^= (1 << 5);          // Toggle LED
	      		    lastToggleTime = currentTime;    // Reset timestamp
	      		}
	          	break;
	  }
	  lastButtonState = currentButtonState;
 }
