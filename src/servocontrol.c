#include <stdint.h>
#include "servocontrol.h"
#include "drivers/adc/adc.h"
#include "drivers/pwm/pwm.h"
#include "drivers/gpio/gpio.h"

#define SERVO_PORT GPIO_PORTB
#define SERVO_PIN  1

#define LED_LEFT_PORT GPIO_PORTB
#define LED_LEFT_PIN  3

#define LED_RIGHT_PORT GPIO_PORTD
#define LED_RIGHT_PIN  3

#define POT_CHANNEL 0

void ServoControl_Init(void)
{
    ADC_Init();

    GPIO_Init(SERVO_PORT, SERVO_PIN, GPIO_OUTPUT);
    PWM_Init(SERVO_PORT, SERVO_PIN, 50);

    GPIO_Init(LED_LEFT_PORT, LED_LEFT_PIN, GPIO_OUTPUT);
    PWM_Init(LED_LEFT_PORT, LED_LEFT_PIN, 500);

    GPIO_Init(LED_RIGHT_PORT, LED_RIGHT_PIN, GPIO_OUTPUT);
    PWM_Init(LED_RIGHT_PORT, LED_RIGHT_PIN, 500);
}

void ServoControl_Update(void)
{
    uint16_t adc_value;
    uint8_t servo_duty;
    uint8_t left_led_duty = 0;
    uint8_t right_led_duty = 0;

    adc_value = ADC_Read(POT_CHANNEL);

    servo_duty = 13 + ((adc_value * (26 - 13)) / 1023);
    PWM_SetDutyCycle(SERVO_PORT, SERVO_PIN, servo_duty);

    if (adc_value < 450)
    {
        left_led_duty = ((480 - adc_value) * 255) / 480;
        right_led_duty = 0;
    }
    else if (adc_value > 570)
    {
        right_led_duty = ((adc_value - 540) * 255) / (1023 - 540);
        left_led_duty = 0;
    }
    else
    {
        left_led_duty = 0;
        right_led_duty = 0;
    }

    PWM_SetDutyCycle(LED_LEFT_PORT, LED_LEFT_PIN, left_led_duty);
    PWM_SetDutyCycle(LED_RIGHT_PORT, LED_RIGHT_PIN, right_led_duty);
}