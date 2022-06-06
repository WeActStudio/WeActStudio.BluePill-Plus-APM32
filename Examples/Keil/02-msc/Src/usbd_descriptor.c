/*!
 * @file        usbd_descriptor.c
 *
 * @brief       USB descriptor
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

#include "usbd_descriptor.h"
#include "usbd_core.h"

extern uint8_t g_usbDeviceDescriptor[USB_DEVICE_DESCRIPTOR_SIZE];
extern uint8_t g_usbConfigDescriptor[USB_CONFIG_DESCRIPTOR_SIZE];
extern uint8_t g_usbLandIDString[USB_LANGID_STRING_SIZE];
extern uint8_t g_usbVendorString[USB_VENDOR_STRING_SIZE];
extern uint8_t g_usbProductString[USB_PRODUCT_STRING_SIZE];
extern uint8_t g_usbSerialString[USB_SERIAL_STRING_SIZE];

/** Device descriptor */
USBD_Descriptor_T g_deviceDescriptor = {g_usbDeviceDescriptor, USB_DEVICE_DESCRIPTOR_SIZE};
/** Config descriptor */
USBD_Descriptor_T g_configDescriptor = {g_usbConfigDescriptor, USB_CONFIG_DESCRIPTOR_SIZE};
/** String descriptor */
USBD_Descriptor_T g_stringDescriptor[SRTING_DESC_NUM] =
{
    {g_usbLandIDString, USB_LANGID_STRING_SIZE},
    {g_usbVendorString, USB_VENDOR_STRING_SIZE},
    {g_usbProductString, USB_PRODUCT_STRING_SIZE},
    {g_usbSerialString, USB_SERIAL_STRING_SIZE}
};

/**
 * @brief   Device descriptor
 */
uint8_t g_usbDeviceDescriptor[USB_DEVICE_DESCRIPTOR_SIZE] =
{
    /** bLength */
    0x12,
    /** bDescriptorType */
    USBD_DESC_DEVICE,
    /** bcdUSB */
    0x00, 0x02,
    /** bDeviceClass */
    0x00,
    /** bDeviceSubClass */
    0x00,
    /** bDeviceProtocol */
    0x00,
    /** bMaxPacketSize */
    USB_EP0_PACKET_SIZE,
    /** idVendor =  314b*/
    0x4B, 0x31,
    /** idProduct = 0109 */
    0x09, 0x02,
    /** bcdDevice = 2.00 */
    0x00, 0x02,
    /** Index of string descriptor describing manufacturer */
    1,
    /** Index of string descriptor describing product */
    2,
    /** Index of string descriptor describing the device serial number */
    3,
    /** bNumConfigurations */
    1,
};

/**
 * @brief   Configuration descriptor
 */
uint8_t g_usbConfigDescriptor[USB_CONFIG_DESCRIPTOR_SIZE] =
{
    /** bLength */
    0x09,
    /** bDescriptorType */
    USBD_DESC_CONFIGURATION,
    /** wTotalLength */
    USB_CONFIG_DESCRIPTOR_SIZE & 0xFF, USB_CONFIG_DESCRIPTOR_SIZE >> 8,

    /** bNumInterfaces */
    0x01,
    /** bConfigurationValue */
    0x01,
    /** iConfiguration */
    0x01,
    /** bmAttributes */
    0xC0,
    /** MaxPower */
    0x32,

    /** bLength */
    0x09,
    /** bDescriptorType */
    USBD_DESC_INTERFACE,
    /** bInterfaceNumber */
    0x00,
    /** bAlternateSetting */
    0x00,
    /** bNumEndpoints */
    0x02,
    /** bInterfaceClass */
    0x08,
    /** bInterfaceSubClass */
    0x06,
    /** bInterfaceProtocol */
    0x50,
    /** iInterface */
    0x05,

    /** bLength */
    0x07,
    /** bDescriptorType: Endpoint */
    USBD_DESC_ENDPOINT,
    /** bEndpointAddress */
    0x81,
    /** bmAttributes */
    0x02,
    /** wMaxPacketSize: */
    0x40,0x00,
    /** bInterval: */
    0x00,

    /** bLength */
    0x07,
    /** bDescriptorType: Endpoint */
    USBD_DESC_ENDPOINT,
    /** bEndpointAddress */
    0x01,
    /** bmAttributes */
    0x02,
    /** wMaxPacketSize: */
    0x40,0x00,
    /** bInterval: */
    0x00,
};

/**
 * @brief   language ID string
 */
uint8_t g_usbLandIDString[USB_LANGID_STRING_SIZE] =
{
    /** Size */
    USB_LANGID_STRING_SIZE,
    /** bDescriptorType */
    USBD_DESC_STRING,
    0x09,0x04
};

/**
 * @brief   Vendor string
 */
uint8_t g_usbVendorString[USB_VENDOR_STRING_SIZE] =
{
    /** Size */
    USB_VENDOR_STRING_SIZE,
    /** bDescriptorType */
    USBD_DESC_STRING,
    'G', 0, 'e', 0, 'e', 0, 'h', 0, 'y', 0,
};

/**
 * @brief   Product string
 */
uint8_t g_usbProductString[USB_PRODUCT_STRING_SIZE] =
{
    USB_PRODUCT_STRING_SIZE,
    USBD_DESC_STRING,

#ifdef USB_OTG_FS
    'A', 0, 'P', 0, 'M', 0, '3', 0, '2', 0,
    ' ', 0, 'F', 0, 'S', 0, ' ', 0, 'M', 0,
    'S', 0, 'C', 0
#else
    'A', 0, 'P', 0, 'M', 0, '3', 0, '2', 0,
    ' ', 0, 'H', 0, 'S', 0, ' ', 0, 'M', 0,
    'S', 0, 'C', 0
#endif
};

/**
 * @brief   Serial string
 */
uint8_t g_usbSerialString[USB_SERIAL_STRING_SIZE] =
{
    USB_SERIAL_STRING_SIZE,
    USBD_DESC_STRING,

    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0
};
