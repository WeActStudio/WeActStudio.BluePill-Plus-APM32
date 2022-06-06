/*!
 * @file        ubsd_descriptor.h
 *
 * @brief       MSC descriptor head file
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

#ifndef USBD_DESCRIPTOR_H_
#define USBD_DESCRIPTOR_H_

#include "usbd_core.h"

#define USB_DEVICE_DESCRIPTOR_SIZE          (18)
#define USB_CONFIG_DESCRIPTOR_SIZE          (32)
#define USB_LANGID_STRING_SIZE              (4)
#define USB_VENDOR_STRING_SIZE              (12)
#define USB_PRODUCT_STRING_SIZE             (26)
#define USB_SERIAL_STRING_SIZE              (26)
#define USB_USER_STRING_1_SIZE              (94)
#define USB_USER_STRING_2_SIZE              (72)
#define SRTING_DESC_NUM                     (4)

extern USBD_Descriptor_T g_deviceDescriptor;
extern USBD_Descriptor_T g_configDescriptor;
extern USBD_Descriptor_T g_stringDescriptor[SRTING_DESC_NUM];

#endif
