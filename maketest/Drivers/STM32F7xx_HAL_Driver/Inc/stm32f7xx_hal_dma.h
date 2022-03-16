/**
  ******************************************************************************
  * @file    stm32f7xx_hal_dma.h
  * @author  MCD Application Team
  * @brief   Header file of DMA HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _STM32F7xx_HAL_DMA_H_
#define _STM32F7xx_HAL_DMA_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "C:\dev\Projects\maketest\maketest\Drivers\STM32F7xx_HAL_Driver\Inc\stm32f7xx_hal_def.h"

typedef struct
{
  uint32_t Channel;              /*!< Specifies the channel used for the specified stream. 
                                      This parameter can be a value of @ref DMAEx_Channel_selection                  */

  uint32_t Direction;            /*!< Specifies if the data will be transferred from memory to peripheral, 
                                      from memory to memory or from peripheral to memory.
                                      This parameter can be a value of @ref DMA_Data_transfer_direction              */

  uint32_t PeriphInc;            /*!< Specifies whether the Peripheral address register should be incremented or not.
                                      This parameter can be a value of @ref DMA_Peripheral_incremented_mode          */

  uint32_t MemInc;               /*!< Specifies whether the memory address register should be incremented or not.
                                      This parameter can be a value of @ref DMA_Memory_incremented_mode              */

  uint32_t PeriphDataAlignment;  /*!< Specifies the Peripheral data width.
                                      This parameter can be a value of @ref DMA_Peripheral_data_size                 */

  uint32_t MemDataAlignment;     /*!< Specifies the Memory data width.
                                      This parameter can be a value of @ref DMA_Memory_data_size                     */

  uint32_t Mode;                 /*!< Specifies the operation mode of the DMAy Streamx.
                                      This parameter can be a value of @ref DMA_mode
                                      @note The circular buffer mode cannot be used if the memory-to-memory
                                            data transfer is configured on the selected Stream                        */

  uint32_t Priority;             /*!< Specifies the software priority for the DMAy Streamx.
                                      This parameter can be a value of @ref DMA_Priority_level                       */

  uint32_t FIFOMode;             /*!< Specifies if the FIFO mode or Direct mode will be used for the specified stream.
                                      This parameter can be a value of @ref DMA_FIFO_direct_mode
                                      @note The Direct mode (FIFO mode disabled) cannot be used if the 
                                            memory-to-memory data transfer is configured on the selected stream       */

  uint32_t FIFOThreshold;        /*!< Specifies the FIFO threshold level.
                                      This parameter can be a value of @ref DMA_FIFO_threshold_level                  */

  uint32_t MemBurst;             /*!< Specifies the Burst transfer configuration for the memory transfers. 
                                      It specifies the amount of data to be transferred in a single non interruptible 
                                      transaction.
                                      This parameter can be a value of @ref DMA_Memory_burst 
                                      @note The burst mode is possible only if the address Increment mode is enabled. */

  uint32_t PeriphBurst;          /*!< Specifies the Burst transfer configuration for the peripheral transfers. 
                                      It specifies the amount of data to be transferred in a single non interruptible 
                                      transaction. 
                                      This parameter can be a value of @ref DMA_Peripheral_burst
                                      @note The burst mode is possible only if the address Increment mode is enabled. */
}DMA_InitTypeDef;


typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,  /*!< DMA not yet initialized or disabled */
  HAL_DMA_STATE_READY             = 0x01U,  /*!< DMA initialized and ready for use   */
  HAL_DMA_STATE_BUSY              = 0x02U,  /*!< DMA process is ongoing              */
  HAL_DMA_STATE_TIMEOUT           = 0x03U,  /*!< DMA timeout state                   */
  HAL_DMA_STATE_ERROR             = 0x04U,  /*!< DMA error state                     */
  HAL_DMA_STATE_ABORT             = 0x05U,  /*!< DMA Abort state                     */
}HAL_DMA_StateTypeDef;


typedef enum
{
  HAL_DMA_FULL_TRANSFER      = 0x00U,    /*!< Full transfer     */
  HAL_DMA_HALF_TRANSFER      = 0x01U,    /*!< Half Transfer     */
}HAL_DMA_LevelCompleteTypeDef;


typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID          = 0x00U,    /*!< Full transfer     */
  HAL_DMA_XFER_HALFCPLT_CB_ID      = 0x01U,    /*!< Half Transfer     */
  HAL_DMA_XFER_M1CPLT_CB_ID        = 0x02U,    /*!< M1 Full Transfer  */
  HAL_DMA_XFER_M1HALFCPLT_CB_ID    = 0x03U,    /*!< M1 Half Transfer  */
  HAL_DMA_XFER_ERROR_CB_ID         = 0x04U,    /*!< Error             */
  HAL_DMA_XFER_ABORT_CB_ID         = 0x05U,    /*!< Abort             */
  HAL_DMA_XFER_ALL_CB_ID           = 0x06U     /*!< All               */
}HAL_DMA_CallbackIDTypeDef;


typedef struct __DMA_HandleTypeDef
{
  DMA_Stream_TypeDef         *Instance;                                                    /*!< Register base address                  */

  DMA_InitTypeDef            Init;                                                         /*!< DMA communication parameters           */ 

  HAL_LockTypeDef            Lock;                                                         /*!< DMA locking object                     */  

  __IO HAL_DMA_StateTypeDef  State;                                                        /*!< DMA transfer state                     */

  void                       *Parent;                                                      /*!< Parent object state                    */ 

  void                       (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);     /*!< DMA transfer complete callback         */

  void                       (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma); /*!< DMA Half transfer complete callback    */

  void                       (* XferM1CpltCallback)( struct __DMA_HandleTypeDef * hdma);   /*!< DMA transfer complete Memory1 callback */
  
  void                       (* XferM1HalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);   /*!< DMA transfer Half complete Memory1 callback */
  
  void                       (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);    /*!< DMA transfer error callback            */
  
  void                       (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);    /*!< DMA transfer Abort callback            */  

 __IO uint32_t               ErrorCode;                                                    /*!< DMA Error code                          */
  
 uint32_t                    StreamBaseAddress;                                            /*!< DMA Stream Base Address                */

 uint32_t                    StreamIndex;                                                  /*!< DMA Stream Index                       */
 
}DMA_HandleTypeDef;

#define HAL_DMA_ERROR_NONE                       0x00000000U    /*!< No error                               */
#define HAL_DMA_ERROR_TE                         0x00000001U    /*!< Transfer error                         */
#define HAL_DMA_ERROR_FE                         0x00000002U    /*!< FIFO error                             */
#define HAL_DMA_ERROR_DME                        0x00000004U    /*!< Direct Mode error                      */
#define HAL_DMA_ERROR_TIMEOUT                    0x00000020U    /*!< Timeout error                          */
#define HAL_DMA_ERROR_PARAM                      0x00000040U    /*!< Parameter error                        */
#define HAL_DMA_ERROR_NO_XFER                    0x00000080U    /*!< Abort requested with no Xfer ongoing   */
#define HAL_DMA_ERROR_NOT_SUPPORTED              0x00000100U    /*!< Not supported mode                     */

#define DMA_PERIPH_TO_MEMORY                     0x00000000U      /*!< Peripheral to memory direction */
#define DMA_MEMORY_TO_PERIPH                     DMA_SxCR_DIR_0   /*!< Memory to peripheral direction */
#define DMA_MEMORY_TO_MEMORY                     DMA_SxCR_DIR_1   /*!< Memory to memory direction     */

#define DMA_PINC_ENABLE                          DMA_SxCR_PINC    /*!< Peripheral increment mode enable  */
#define DMA_PINC_DISABLE                         0x00000000U      /*!< Peripheral increment mode disable */

#define DMA_MINC_ENABLE                          DMA_SxCR_MINC    /*!< Memory increment mode enable  */
#define DMA_MINC_DISABLE                         0x00000000U      /*!< Memory increment mode disable */

#define DMA_PDATAALIGN_BYTE                      0x00000000U        /*!< Peripheral data alignment: Byte     */
#define DMA_PDATAALIGN_HALFWORD                  DMA_SxCR_PSIZE_0   /*!< Peripheral data alignment: HalfWord */
#define DMA_PDATAALIGN_WORD                      DMA_SxCR_PSIZE_1   /*!< Peripheral data alignment: Word     */

#define DMA_MDATAALIGN_BYTE                      0x00000000U        /*!< Memory data alignment: Byte     */
#define DMA_MDATAALIGN_HALFWORD                  DMA_SxCR_MSIZE_0   /*!< Memory data alignment: HalfWord */
#define DMA_MDATAALIGN_WORD                      DMA_SxCR_MSIZE_1   /*!< Memory data alignment: Word     */

#define DMA_NORMAL                               0x00000000U       /*!< Normal mode                  */
#define DMA_CIRCULAR                             DMA_SxCR_CIRC     /*!< Circular mode                */
#define DMA_PFCTRL                               DMA_SxCR_PFCTRL   /*!< Peripheral flow control mode */

#define DMA_PRIORITY_LOW                         0x00000000U    /*!< Priority level: Low       */
#define DMA_PRIORITY_MEDIUM                      DMA_SxCR_PL_0  /*!< Priority level: Medium    */
#define DMA_PRIORITY_HIGH                        DMA_SxCR_PL_1  /*!< Priority level: High      */
#define DMA_PRIORITY_VERY_HIGH                   DMA_SxCR_PL    /*!< Priority level: Very High */

#define DMA_FIFOMODE_DISABLE                     0x00000000U       /*!< FIFO mode disable */
#define DMA_FIFOMODE_ENABLE                      DMA_SxFCR_DMDIS   /*!< FIFO mode enable  */

#define DMA_FIFO_THRESHOLD_1QUARTERFULL          0x00000000U       /*!< FIFO threshold 1 quart full configuration  */
#define DMA_FIFO_THRESHOLD_HALFFULL              DMA_SxFCR_FTH_0   /*!< FIFO threshold half full configuration     */
#define DMA_FIFO_THRESHOLD_3QUARTERSFULL         DMA_SxFCR_FTH_1   /*!< FIFO threshold 3 quarts full configuration */
#define DMA_FIFO_THRESHOLD_FULL                  DMA_SxFCR_FTH     /*!< FIFO threshold full configuration          */

#define DMA_MBURST_SINGLE                        0x00000000U
#define DMA_MBURST_INC4                          DMA_SxCR_MBURST_0
#define DMA_MBURST_INC8                          DMA_SxCR_MBURST_1
#define DMA_MBURST_INC16                         DMA_SxCR_MBURST

#define DMA_PBURST_SINGLE                        0x00000000U
#define DMA_PBURST_INC4                          DMA_SxCR_PBURST_0
#define DMA_PBURST_INC8                          DMA_SxCR_PBURST_1
#define DMA_PBURST_INC16                         DMA_SxCR_PBURST

#define DMA_IT_TC                                DMA_SxCR_TCIE
#define DMA_IT_HT                                DMA_SxCR_HTIE
#define DMA_IT_TE                                DMA_SxCR_TEIE
#define DMA_IT_DME                               DMA_SxCR_DMEIE
#define DMA_IT_FE                                0x00000080U

#define DMA_FLAG_FEIF0_4                         0x00000001U
#define DMA_FLAG_DMEIF0_4                        0x00000004U
#define DMA_FLAG_TEIF0_4                         0x00000008U
#define DMA_FLAG_HTIF0_4                         0x00000010U
#define DMA_FLAG_TCIF0_4                         0x00000020U
#define DMA_FLAG_FEIF1_5                         0x00000040U
#define DMA_FLAG_DMEIF1_5                        0x00000100U
#define DMA_FLAG_TEIF1_5                         0x00000200U
#define DMA_FLAG_HTIF1_5                         0x00000400U
#define DMA_FLAG_TCIF1_5                         0x00000800U
#define DMA_FLAG_FEIF2_6                         0x00010000U
#define DMA_FLAG_DMEIF2_6                        0x00040000U
#define DMA_FLAG_TEIF2_6                         0x00080000U
#define DMA_FLAG_HTIF2_6                         0x00100000U
#define DMA_FLAG_TCIF2_6                         0x00200000U
#define DMA_FLAG_FEIF3_7                         0x00400000U
#define DMA_FLAG_DMEIF3_7                        0x01000000U
#define DMA_FLAG_TEIF3_7                         0x02000000U
#define DMA_FLAG_HTIF3_7                         0x04000000U
#define DMA_FLAG_TCIF3_7                         0x08000000U

#define __HAL_DMA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DMA_STATE_RESET)


#define __HAL_DMA_GET_FS(__HANDLE__)      (((__HANDLE__)->Instance->FCR & (DMA_SxFCR_FS)))

#define __HAL_DMA_ENABLE(__HANDLE__)      ((__HANDLE__)->Instance->CR |=  DMA_SxCR_EN)


#define __HAL_DMA_DISABLE(__HANDLE__)     ((__HANDLE__)->Instance->CR &=  ~DMA_SxCR_EN)


#define __HAL_DMA_GET_TC_FLAG_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_TCIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_TCIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_TCIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_TCIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_TCIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_TCIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_TCIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_TCIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_TCIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_TCIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_TCIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_TCIF2_6 :\
   DMA_FLAG_TCIF3_7)
   
#define __HAL_DMA_GET_HT_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_HTIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_HTIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_HTIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_HTIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_HTIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_HTIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_HTIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_HTIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_HTIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_HTIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_HTIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_HTIF2_6 :\
   DMA_FLAG_HTIF3_7)


#define __HAL_DMA_GET_TE_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_TEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_TEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_TEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_TEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_TEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_TEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_TEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_TEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_TEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_TEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_TEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_TEIF2_6 :\
   DMA_FLAG_TEIF3_7)


#define __HAL_DMA_GET_FE_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_FEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_FEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_FEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_FEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_FEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_FEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_FEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_FEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_FEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_FEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_FEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_FEIF2_6 :\
   DMA_FLAG_FEIF3_7)


#define __HAL_DMA_GET_DME_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_DMEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_DMEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_DMEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_DMEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_DMEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_DMEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_DMEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_DMEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_DMEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_DMEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_DMEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_DMEIF2_6 :\
   DMA_FLAG_DMEIF3_7)


#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)\
(((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA2_Stream3)? (DMA2->HISR & (__FLAG__)) :\
 ((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Stream7)? (DMA2->LISR & (__FLAG__)) :\
 ((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Stream3)? (DMA1->HISR & (__FLAG__)) : (DMA1->LISR & (__FLAG__)))

#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) \
(((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA2_Stream3)? (DMA2->HIFCR = (__FLAG__)) :\
 ((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Stream7)? (DMA2->LIFCR = (__FLAG__)) :\
 ((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Stream3)? (DMA1->HIFCR = (__FLAG__)) : (DMA1->LIFCR = (__FLAG__)))


#define __HAL_DMA_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (((__INTERRUPT__) != DMA_IT_FE)? \
((__HANDLE__)->Instance->CR |= (__INTERRUPT__)) : ((__HANDLE__)->Instance->FCR |= (__INTERRUPT__)))


#define __HAL_DMA_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (((__INTERRUPT__) != DMA_IT_FE)? \
((__HANDLE__)->Instance->CR &= ~(__INTERRUPT__)) : ((__HANDLE__)->Instance->FCR &= ~(__INTERRUPT__)))


#define __HAL_DMA_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)  (((__INTERRUPT__) != DMA_IT_FE)? \
                                                        ((__HANDLE__)->Instance->CR & (__INTERRUPT__)) : \
                                                        ((__HANDLE__)->Instance->FCR & (__INTERRUPT__)))


#define __HAL_DMA_SET_COUNTER(__HANDLE__, __COUNTER__) ((__HANDLE__)->Instance->NDTR = (uint16_t)(__COUNTER__))

/**
  * @brief  Returns the number of remaining data units in the current DMAy Streamx transfer.
  * @param  __HANDLE__ DMA handle
  *   
  * @retval The number of remaining data units in the current DMA Stream transfer.
  */
#define __HAL_DMA_GET_COUNTER(__HANDLE__) ((__HANDLE__)->Instance->NDTR)


/* Include DMA HAL Extension module */
#include "C:\dev\Projects\maketest\maketest\Drivers\STM32F7xx_HAL_Driver\Inc\stm32f7xx_hal_dma_ex.h"   


HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma); 
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);

HAL_StatusTypeDef HAL_DMA_Start (DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel, uint32_t Timeout);
void              HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)(DMA_HandleTypeDef *_hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);


HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t             HAL_DMA_GetError(DMA_HandleTypeDef *hdma);

#define IS_DMA_DIRECTION(DIRECTION) (((DIRECTION) == DMA_PERIPH_TO_MEMORY ) || \
                                     ((DIRECTION) == DMA_MEMORY_TO_PERIPH)  || \
                                     ((DIRECTION) == DMA_MEMORY_TO_MEMORY)) 

#define IS_DMA_BUFFER_SIZE(SIZE) (((SIZE) >= 0x01U) && ((SIZE) < 0x10000U))

#define IS_DMA_PERIPHERAL_INC_STATE(STATE) (((STATE) == DMA_PINC_ENABLE) || \
                                            ((STATE) == DMA_PINC_DISABLE))

#define IS_DMA_MEMORY_INC_STATE(STATE) (((STATE) == DMA_MINC_ENABLE)  || \
                                        ((STATE) == DMA_MINC_DISABLE))

#define IS_DMA_PERIPHERAL_DATA_SIZE(SIZE) (((SIZE) == DMA_PDATAALIGN_BYTE)     || \
                                           ((SIZE) == DMA_PDATAALIGN_HALFWORD) || \
                                           ((SIZE) == DMA_PDATAALIGN_WORD))

#define IS_DMA_MEMORY_DATA_SIZE(SIZE) (((SIZE) == DMA_MDATAALIGN_BYTE)     || \
                                       ((SIZE) == DMA_MDATAALIGN_HALFWORD) || \
                                       ((SIZE) == DMA_MDATAALIGN_WORD ))

#define IS_DMA_MODE(MODE) (((MODE) == DMA_NORMAL )  || \
                           ((MODE) == DMA_CIRCULAR) || \
                           ((MODE) == DMA_PFCTRL)) 

#define IS_DMA_PRIORITY(PRIORITY) (((PRIORITY) == DMA_PRIORITY_LOW )   || \
                                   ((PRIORITY) == DMA_PRIORITY_MEDIUM) || \
                                   ((PRIORITY) == DMA_PRIORITY_HIGH)   || \
                                   ((PRIORITY) == DMA_PRIORITY_VERY_HIGH)) 

#define IS_DMA_FIFO_MODE_STATE(STATE) (((STATE) == DMA_FIFOMODE_DISABLE ) || \
                                       ((STATE) == DMA_FIFOMODE_ENABLE))

#define IS_DMA_FIFO_THRESHOLD(THRESHOLD) (((THRESHOLD) == DMA_FIFO_THRESHOLD_1QUARTERFULL ) || \
                                          ((THRESHOLD) == DMA_FIFO_THRESHOLD_HALFFULL)      || \
                                          ((THRESHOLD) == DMA_FIFO_THRESHOLD_3QUARTERSFULL) || \
                                          ((THRESHOLD) == DMA_FIFO_THRESHOLD_FULL))

#define IS_DMA_MEMORY_BURST(BURST) (((BURST) == DMA_MBURST_SINGLE) || \
                                    ((BURST) == DMA_MBURST_INC4)   || \
                                    ((BURST) == DMA_MBURST_INC8)   || \
                                    ((BURST) == DMA_MBURST_INC16))

#define IS_DMA_PERIPHERAL_BURST(BURST) (((BURST) == DMA_PBURST_SINGLE) || \
                                        ((BURST) == DMA_PBURST_INC4)   || \
                                        ((BURST) == DMA_PBURST_INC8)   || \
                                        ((BURST) == DMA_PBURST_INC16))

#ifdef __cplusplus
}
#endif

#endif /* _STM32F7xx_HAL_DMA_H_ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
