/*!
 * @file        usb_bsp.c
 *
 * @brief       Borad source file
 *
 * @version     V1.0.0
 *
 * @date        2021-12-30
 *
 * @attention
 *
 *  Copyright (C) 2020-2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be usefull and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

#include "usb_bsp.h"

void USBD_HardWareInit(void)
{
    RCM_ConfigUSBCLK(RCM_USB_DIV_1_5);
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_USB);

    EINT_Config_T EINT_ConfigStruct;

    EINT_ConfigStruct.mode = EINT_MODE_INTERRUPT;
    EINT_ConfigStruct.line = EINT_LINE_18;
    EINT_ConfigStruct.trigger = EINT_TRIGGER_RISING;
    EINT_ConfigStruct.lineCmd = ENABLE;
    EINT_Config(&EINT_ConfigStruct);

#if USB_SELECT == USB1
    NVIC_EnableIRQRequest(USBD1_LP_CAN1_RX0_IRQn, 2, 0);
#else
    NVIC_EnableIRQRequest(USB2_LP_IRQn, 2, 0);
#endif

    NVIC_EnableIRQRequest(USBDWakeUp_IRQn, 1, 0);
}
