
#include <h_code/interrupt.h>

//define in tim.c
extern TIM_HandleTypeDef htim4;
// define in uart.c
extern UART_HandleTypeDef huart7;


// test parameters zone
const uint8_t transfer_data[3] = {0x55, 0x00, 0x77};
uint8_t receive_data;

// initial all interrupt
void intrrupt_initial(void)
{
	HAL_TIM_Base_Start_IT(&htim4);
}



// timer interrupt 500ms
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
//	if(htim == &htim4)
//	{
//		HAL_GPIO_TogglePin(GPIOM, BULE_LED_Pin | RED_LED_Pin);
//		HAL_GPIO_TogglePin(GPIOO, ORANGE_LED_Pin | GREEN_LED_Pin);
//	}

	HAL_GPIO_WritePin(GPIOM, BULE_LED_Pin, GPIO_PIN_SET);		// set dir pin to high
	// transfer 1 byte
//	HAL_UART_Transmit(&huart7, &transfer_data, 1, HAL_MAX_DELAY);
	// transfer array
	HAL_UART_Transmit_IT(&huart7, transfer_data, ((uint16_t)sizeof(transfer_data)));	// send data
	//wait tx finish

}


// uart interrupt tx
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_GPIO_WritePin(GPIOM, BULE_LED_Pin, GPIO_PIN_RESET);		// set dir pin to low
}

//uart interrupt rx
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == UART7)
	{
		// Restart reception
		HAL_UART_Receive_IT(&huart7, &receive_data, 1);
	}
}




































