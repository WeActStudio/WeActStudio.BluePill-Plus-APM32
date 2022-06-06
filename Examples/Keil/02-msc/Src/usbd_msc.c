/*!
 * @file        usbd_msc.c
 *
 * @brief       MSC source file
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

#include "usbd_msc.h"
#include "usbd_init.h"
#include "usbd_descriptor.h"
#include "usbd_class_msc.h"
#include "usbd_msc_bot.h"

static void USBD_MSC_SetConfigurationHandler(void);
static void USBD_MSC_ClearFeatureHandler(void);

/** Standard Request handler */
USBD_StdReqCallback_T g_stdReqCallback =
{
    NULL,      //!< getConfigurationHandler;
    NULL,      //!< getDescriptorHandler;
    NULL,      //!< getInterfaceHandler;
    NULL,      //!< getStatusHandler;
    NULL,      //!< setAddressHandler;
    USBD_MSC_SetConfigurationHandler, //!< setConfigurationHandler;
    NULL,      //!< setDescriptorHandler;
    NULL,      //!< setFeatureHandler;
    NULL,      //!< setInterfaceHandler;
    USBD_MSC_ClearFeatureHandler //!< clearFeatureHandler;
};

static void USBD_MSC_SetConfigurationHandler(void)
{
    USBD_MSC_BOT_Reset();
}

/*!
 * @brief       handler clearFeature
 *
 * @param       None
 *
 * @retval      None
 */
static void USBD_MSC_ClearFeatureHandler(void)
{
    if (g_usbDev.reqData.byte.wValue[0] == USBD_FEATURE_ENDPOINT_HALT)
    {
        USBD_MSV_BOT_ClearFeatureHandler();
    }
}

/*!
 * @brief       MSC Out endpoint initialization call back
 *
 * @param       ep : endpoint number
 *
 * @retval      None
 */
void USBD_MSC_OutEpCallback(uint8_t ep)
{
    if (ep == (MSC_OUT_EP & 0x7f))
    {
        USBD_MSC_BOT_OutData(ep);
    }
}

/*!
 * @brief       MSC In endpoint initialization  call back
 *
 * @param       ep : endpoint number
 *
 * @retval      None
 */
void USBD_MSC_InEpCallback(uint8_t ep)
{
    if (ep == (MSC_IN_EP & 0x7f))
    {
        USBD_MSC_BOT_InData(ep);
    }
}

/*!
 * @brief       Reset
 *
 * @param       None
 *
 * @retval      None
 */
void MSC_Reset(void)
{
    USBD_EPConfig_T epConfig;

    /** Endpoint 1 IN */
    epConfig.epNum = USBD_EP_1;
    epConfig.epType = USBD_EP_TYPE_BULK;
    epConfig.epBufAddr = USB_EP1_TX_ADDR;
    epConfig.maxPackSize = 64;
    epConfig.epStatus = USBD_EP_STATUS_NAK;
    USBD_OpenInEP(&epConfig);

    epConfig.epBufAddr = USB_EP1_RX_ADDR;
    USBD_OpenOutEP(&epConfig);
}

/*!
 * @brief       MSC init
 *
 * @param       None
 *
 * @retval      None
 */
void MSC_Init(void)
{
    USBD_InitParam_T usbParam;

    USBD_InitParamStructInit(&usbParam);

    /** Descriptor */
    usbParam.pDeviceDesc = &g_deviceDescriptor;
    usbParam.pConfigurationDesc = &g_configDescriptor;
    usbParam.pStringDesc = (USBD_Descriptor_T *)g_stringDescriptor;
    usbParam.pStdReqCallback = &g_stdReqCallback;
    usbParam.classReqHandler = USBD_MSC_ClassHandler;

    usbParam.outEpHandler = USBD_MSC_OutEpCallback;
    usbParam.inEpHandler = USBD_MSC_InEpCallback;

    usbParam.resetHandler = MSC_Reset;

    USBD_Init(&usbParam);
}
