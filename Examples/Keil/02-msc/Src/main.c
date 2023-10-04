/*---------------------------------------
- WeAct Studio Official Link
- taobao: weactstudio.taobao.com
- aliexpress: weactstudio.aliexpress.com
- github: github.com/WeActStudio
- gitee: gitee.com/WeAct-TC
- blog: www.weact-tc.cn
---------------------------------------*/

#include "main.h"
#include "board.h"
#include "usbd_msc.h"
#include "systick.h"

/*!
 * @brief       Main program
 *
 * @param       None
 *
 * @retval      None
 *
 */
int main(void)
{
    systick_config();

    board_led_init();
    board_button_init();
    board_usart_init();

    printf("\r\nWeAct Studio Core Board\r\n");
    printf("weactstudio.taobao.com\r\n");
    printf("weactstudio.aliexpress.com\r\n");
    printf("wwww.weact-tc.cn\r\n\r\n");
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf("MSC Test\r\n");

    MSC_Init();

    while (1)
    {
        if (!board_button_state_get())
        {
            delay(100);
            board_led_toggle();
        }
        else
        {
            board_led_off();
        }
    }
}
