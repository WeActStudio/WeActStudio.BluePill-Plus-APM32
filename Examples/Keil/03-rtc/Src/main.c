/*---------------------------------------
- WeAct Studio Official Link
- taobao: weactstudio.taobao.com
- aliexpress: weactstudio.aliexpress.com
- github: github.com/WeActTC
- gitee: gitee.com/WeAct-TC
- blog: www.weact-tc.cn
---------------------------------------*/

#include "main.h"
#include "board.h"
#include "systick.h"

#include "apm32f10x_misc.h"
#include "apm32f10x_rcm.h"
#include "apm32f10x_pmu.h"
#include "apm32f10x_rtc.h"

void RTC_Config(void)
{
    RCM_EnableAPB1PeriphClock((RCM_APB1_PERIPH_T)RCM_APB1_PERIPH_PMU);
    PMU_EnableBackupAccess();

    RCM_EnableLSI();
    while(RCM_ReadStatusFlag(RCM_FLAG_LSIRDY) == RESET);
    RCM_ConfigRTCCLK(RCM_RTCCLK_LSI);
    RCM_EnableRTCCLK();

    RTC_WaitForSynchor();
    RTC_WaitForLastTask();

    RTC_EnableInterrupt(RTC_INT_SEC);
    RTC_WaitForLastTask();

    RTC_ConfigPrescaler(32767);
    RTC_WaitForLastTask();

    NVIC_EnableIRQRequest(RTC_IRQn, 0, 0);
}

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
    printf("RTC Test\r\n");
    
    RTC_Config();
    
    while (1)
    {
        if (board_button_state_get())
        {
            board_led_off();
        }
        delay(100);
    }
}
