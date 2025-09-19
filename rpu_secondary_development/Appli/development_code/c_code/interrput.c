
#include <h_code/interrupt.h>

extern TIM_HandleTypeDef htim4;

// initial all interrupt
void intrrupt_initial(void)
{
	HAL_TIM_Base_Start_IT(&htim4);
}



// timer interrupt 500ms
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim4)
	{
		HAL_GPIO_TogglePin(GPIOM, BULE_LED_Pin | RED_LED_Pin);
		HAL_GPIO_TogglePin(GPIOO, ORANGE_LED_Pin | GREEN_LED_Pin);
	}
}







































