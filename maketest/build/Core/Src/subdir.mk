
# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
./Core/Src/main.cpp \
./Core/Src/tim.c \
./Core/Src/eth.c \
./Core/Src/gpio.c \
./Core/Src/stm32f7xx_hal_msp.c \
./Core/Src/stm32f7xx_it.c \
./Core/Src/syscalls.c \
./Core/Src/sysmem.c \
./Core/Src/system_stm32f7xx.c \
./Core/Src/usart.c \
./Core/Src/usb_otg.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/tim.o \
./Core/Src/eth.o \
./Core/Src/gpio.o \
./Core/Src/stm32f7xx_hal_msp.o \
./Core/Src/stm32f7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f7xx.o \
./Core/Src/usart.o \
./Core/Src/usb_otg.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/tim.d \
./Core/Src/eth.d \
./Core/Src/gpio.d \
./Core/Src/stm32f7xx_hal_msp.d \
./Core/Src/stm32f7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f7xx.d \
./Core/Src/usart.d \
./Core/Src/usb_otg.d 

MROOT = C:/dev/Projects/maketest/maketest/

Core/Src/main.o: ../Core/Src/main.cpp Core/Src/subdir.mk
	@echo 'started buiding main.cpp: $@'
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=c++11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c \
	-fno-rtti -fno-exceptions \
	-I"$(MROOT)" \
	-I"$(MROOT)Core/" \
	-I"$(MROOT)Core/Inc" \
	-I"$(MROOT)Drivers/STM32F7xx_HAL_Driver/Inc" \
	-I"$(MROOT)Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" \
	-I"$(MROOT)Drivers/CMSIS/Device/ST/STM32F7xx/Include" \
	-I"$(MROOT)Drivers/CMSIS/Include" \
	-Os -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -Wconversion -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=soft -mthumb -o "$@"
	@echo 'Finished building target main.cpp: $@'
	@echo 

# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	@echo 'started building target: $@'
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c \
	-I"$(MROOT)" \
	-I"$(MROOT)Core/" \
	-I"$(MROOT)Core/Inc" \
	-I"$(MROOT)Drivers/STM32F7xx_HAL_Driver/Inc" \
	-I"$(MROOT)Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" \
	-I"$(MROOT)Drivers/CMSIS/Device/ST/STM32F7xx/Include" \
	-I"$(MROOT)Drivers/CMSIS/Include" \
	-Os -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -Wconversion -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=soft -mthumb -o "$@"
	@echo 'Finished building target: $@'
	@echo 

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/eth.d ./Core/Src/eth.o ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/stm32f7xx_hal_msp.d ./Core/Src/stm32f7xx_hal_msp.o ./Core/Src/stm32f7xx_it.d ./Core/Src/stm32f7xx_it.o ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/system_stm32f7xx.d ./Core/Src/system_stm32f7xx.o ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usb_otg.d ./Core/Src/usb_otg.o

.PHONY: clean-Core-2f-Src

