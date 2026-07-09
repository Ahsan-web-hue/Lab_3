/*
 * gpio_hal.cpp
 *
 *  Created on: 05-Jul-2026
 *      Author: ABU MUSA TRADERS
 */

#include "gpio_hal.h"
#include "main.h"

bool GPIO::isInit = false;

//================ GPIO =================//

GPIO::GPIO()
{
    GPIO::init();
}

GPIO::~GPIO()
{
}

void GPIO::init(void)
{
    if (isInit)
        return;

    MX_GPIO_Init();
    isInit = true;
}

//================ Dout =================//

Dout::Dout(GPIO_TypeDef *GPIOx,
           uint16_t GPIO_Pin,
           GPIO_PinState state) : _GPIOx(GPIOx), _GPIO_Pin(GPIO_Pin)
{
    write(state);
}

Dout::~Dout()
{
}

void Dout::write(GPIO_PinState state)
{
    HAL_GPIO_WritePin(_GPIOx, _GPIO_Pin, state);
}

void Dout::toggle(void)
{
    HAL_GPIO_TogglePin(_GPIOx, _GPIO_Pin);
}

GPIO_PinState Dout::read(void)
{
    return HAL_GPIO_ReadPin(_GPIOx, _GPIO_Pin);
}
Din::Din(GPIO_TypeDef *GPIOx,
         uint16_t GPIO_Pin)
    : _GPIOx(GPIOx), _GPIO_Pin(GPIO_Pin)
{

}
Din::~Din(){

}
GPIO_PinState Din::read(void){
	return HAL_GPIO_ReadPin(_GPIOx, _GPIO_Pin);
}

