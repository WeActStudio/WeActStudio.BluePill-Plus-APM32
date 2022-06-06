/*!
 * @file        usbd_storage_disk.c
 *
 * @brief       usb device storage disk operations functions
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

#include "usbd_storage_disk.h"
#include "usbd_msc_scsi.h"

uint32_t dataBuf[STORAGE_BLK_SIZ * 1];

/** USB Mass storage Standard Inquiry Data */
const uint8_t s_inquirydata[] = {
    0x00,
    0x80,
    0x02,
    0x02,
    (USBD_STD_INQUIRY_LENGTH - 5),
    0x00,
    0x00,
    0x00,
    /** Manufacturer : 8 bytes */
    'G', 'e', 'e', 'h', 'y', ' ', ' ', ' ',
    /** Product : 16 Bytes */
    'S', 't', 'o', 'r', 'a', 'g', 'e', ' ',
    'd', 'i', 's', 'k', ' ', ' ', ' ', ' ',
    /** Version : 4 Bytes */
    '1', '.', '0', '0',
};

uint8_t STORAGE_Init(uint8_t lun);
uint8_t STORAGE_ReadCapacity(uint8_t lun, uint32_t *blockNum, uint32_t *blockSize);
uint8_t STORAGE_CheckReady(uint8_t lun);
uint8_t STORAGE_CheckWPR(uint8_t lun);
uint8_t STORAGE_ReadData(uint8_t lun, uint8_t *buf, uint32_t blkAddr, uint16_t blkLen);
uint8_t STORAGE_WriteData(uint8_t lun, uint8_t *buf, uint32_t blkAddr, uint16_t blkLen);

STORAGE_Callback_T g_storageCallBack =
{
    STORAGE_Init,            //!< Initialization Handler
    STORAGE_ReadCapacity,    //!< ReadCapacity Handler
    STORAGE_CheckReady,      //!< CheckReady Handler
    STORAGE_CheckWPR,        //!< Check Write Protected Handler
    STORAGE_ReadData,        //!< Read Handler
    STORAGE_WriteData,       //!< Write Handler
    (uint8_t *)s_inquirydata //!< Inquiry Data pointer
};

/*!
 * @brief  Initialize the medium.
 *
 * @param  lun: Logical unit number
 *
 * @retval SCSI_OK or SCSI_FAILL
 */
uint8_t STORAGE_Init(uint8_t lun)
{
    return SCSI_OK;
}

/*!
 * @brief  Read medium capacity and block size
 *
 * @param  lun: Logical unit number
 *
 * @param  blockNum: number of physical block
 *
 * @param  blockSize: size of a physical block
 *
 * @retval SCSI_OK or SCSI_FAILL
 */
uint8_t STORAGE_ReadCapacity(uint8_t lun, uint32_t *blockNum, uint32_t *blockSize)
{
    *blockNum = STORAGE_BLK_NBR;
    *blockSize = STORAGE_BLK_SIZ;

    return SCSI_OK;
}

/*!
 * @brief  return medium ready Status
 *
 * @param  lun: Logical unit number
 *
 * @retval SCSI_OK or SCSI_FAILL
 */
uint8_t STORAGE_CheckReady(uint8_t lun)
{
    return SCSI_OK;
}

/*!
 * @brief  return medium write-protected Status
 *
 * @param  lun: Logical unit number
 *
 * @retval SCSI_OK or SCSI_FAILL
 */
uint8_t STORAGE_CheckWPR(uint8_t lun)
{
    return SCSI_OK;
}

/*!
 * @brief  Read data from the medium
 *
 * @param  lun: Logical unit number
 *
 * @param  buf: Pointer to the buffer to get data
 *
 * @param  blkAddr: block address of first physical block to be read
 *
 * @param  blkLen: number of physical block to be read
 *
 * @retval SCSI_OK or SCSI_FAILL
 */
uint8_t STORAGE_ReadData(uint8_t lun, uint8_t *buf, uint32_t blkAddr, uint16_t blkLen)
{
    uint32_t n;

    if ((blkAddr * STORAGE_BLK_SIZ * blkLen) < sizeof(dataBuf))
    {
        for(n = 0; n < (blkLen * STORAGE_BLK_SIZ) / 4; n++)
        {
            ((uint32_t*)buf)[n] = dataBuf[(blkAddr * STORAGE_BLK_SIZ) / 4 + n];
        }
    }

    return SCSI_OK;
}

/*!
 * @brief  Write data to the medium
 *
 * @param  lun: Logical unit number
 *
 * @param  buf: Pointer to the buffer to write data
 *
 * @param  blkAddr: block address of first physical block to be write
 *
 * @param  blkLen: number of physical block to be write
 *
 * @retval SCSI_OK or SCSI_FAILL
 */
uint8_t STORAGE_WriteData(uint8_t lun, uint8_t *buf, uint32_t blkAddr, uint16_t blkLen)
{
    uint32_t n;
    uint32_t base = blkAddr * STORAGE_BLK_SIZ / 4;

    if ((blkAddr * STORAGE_BLK_SIZ * blkLen) < sizeof(dataBuf))
    {
        for(n = 0; n < blkLen*STORAGE_BLK_SIZ / 4; n++)
        {
           dataBuf[base + n] = ((uint32_t*)buf)[n];
        }
    }
    return SCSI_OK;
}
