HAL_TIM_Base_Start_IT(&htim2); // Starts timer

 while (1) {
   
 }

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == TIM2) { // If TIM2 equals configured period
      HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin); // LED on 1s, LED off 1s
  }
}
