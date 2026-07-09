/*
 * gpio_hal.h
 *
 *  Created on: 05-Jul-2026
 *      Author: ABU MUSA TRADERS
 */

#ifndef INC_GPIO_HAL_H_
#define INC_GPIO_HAL_H_

#include "gpio.h"

class GPIO
{
public:
    GPIO();
    ~GPIO();

    static void init(void);

private:
    static bool isInit;
};

class Dout : public GPIO
{
public:
    Dout(GPIO_TypeDef *GPIOx,
         uint16_t GPIO_Pin,
         GPIO_PinState state = GPIO_PIN_SET);

    ~Dout();

    void write(GPIO_PinState state);
    void toggle(void);
    GPIO_PinState read(void);

private:
    GPIO_TypeDef *_GPIOx;
    uint16_t _GPIO_Pin;
};
class Din : public GPIO{

public:
	Din(GPIO_TypeDef *GPIOx,
			uint16_t GPIO_Pin);

	~Din();
	 GPIO_PinState read(void);

private:
    GPIO_TypeDef *_GPIOx;
    uint16_t _GPIO_Pin;

};

#endif /* INC_GPIO_HAL_H_ */
