HAL_TIM_Base_Start_IT(&htim2); // Starts timer

 while (1) {
   
 }

volatile uint32_t ms = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == TIM2) {
	   ms++; // Check debugger to see ms grow 
  }
}
