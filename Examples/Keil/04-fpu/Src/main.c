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

#include "sc_math.h"
#include "sc_dot.h"

#include "apm32f10x_rcm.h"

float a, b, s, x, y, z, ans[100], X[100] = {0, 0, 0,};
float PI = 3.14159;

uint8_t databuff;

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
    printf("FPU Test\r\n");
    
    RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_FPU);
    RCM->CFG |= BIT27;
    
    printf("SIN:");
    
    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        ans[databuff] = sc_math_sin(s);
        databuff++;
    }

    ans[databuff] = sc_math_sin(0);
    databuff++;

    for (s = PI; s > 0; s = s - 0.1)
    {
        ans[databuff] = sc_math_sin(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("COS:\r\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        ans[databuff] = sc_math_cos(s);
        databuff++;
    }

    ans[databuff] = sc_math_cos(0);
    databuff++;

    for (s = PI; s > 0; s = s - 0.1)
    {
        ans[databuff] = sc_math_cos(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("TAN:\r\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        ans[databuff] = sc_math_tan(s);
        databuff++;
    }

    ans[databuff] = sc_math_tan(0);
    databuff++;

    for (s = PI; s > 0; s = s - 0.1)
    {
        ans[databuff] = sc_math_tan(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("ATAN:\r\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        ans[databuff] = sc_math_atan(s);
        databuff++;
    }

    ans[databuff] = sc_math_atan(0);
    databuff++;

    for (s = PI; s > 0; s = s - 0.1)
    {
        ans[databuff] = sc_math_atan(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("ASIN:\r\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -1; s <= 1; s = s + 0.1)
    {
        ans[databuff] = sc_math_asin(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("ACOS:\r\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -1; s <= 1; s = s + 0.1)
    {
        ans[databuff] = sc_math_acos(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("ATAN2:\r\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        a = s;
        b = s + 0.1;
        ans[databuff] = sc_math_atan2(b, a);
        databuff++;
    }

    a = s;
    b = s + 0.1;
    ans[databuff] = sc_math_atan2(0, 0);
    databuff++;


    for (s = PI; s > 0; s = s - 0.1)
    {
        a = s;
        b = s - 0.1;
        ans[databuff] = sc_math_atan2(b, a);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("invsqrt:\r\n");
    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_invsqrt(databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("mac:\r\n");

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        x = s;
        y = s + 1;
        z = s + 2;
        ans[databuff] = sc_math_mac(x, y, z);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%f\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("sum_N:\r\n");
    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        X[databuff] = s;
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_sum_N(X, databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("sub_N:\r\n");

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        X[databuff] = 100 - s;
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_sub_N(X, databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("prdct:\r\n");

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        X[databuff] = s + 1;
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_prdct(X, databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }

    printf("\r\n");
    printf("\r\n");
    printf("sumsq:\r\n");
    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        X[databuff] = 100 - s;
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_sumsq(X, databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\r\n", ans[databuff]);
        databuff++;
    }
    
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
