################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Fonts.c \
../Core/Src/SSD1331.c \
../Core/Src/encoder.c \
../Core/Src/gpio_f1.c \
../Core/Src/i2c.c \
../Core/Src/main.c \
../Core/Src/menu.c \
../Core/Src/menu_callbacks.c \
../Core/Src/spi.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/Fonts.o \
./Core/Src/SSD1331.o \
./Core/Src/encoder.o \
./Core/Src/gpio_f1.o \
./Core/Src/i2c.o \
./Core/Src/main.o \
./Core/Src/menu.o \
./Core/Src/menu_callbacks.o \
./Core/Src/spi.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/Fonts.d \
./Core/Src/SSD1331.d \
./Core/Src/encoder.d \
./Core/Src/gpio_f1.d \
./Core/Src/i2c.d \
./Core/Src/main.d \
./Core/Src/menu.d \
./Core/Src/menu_callbacks.d \
./Core/Src/spi.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Fonts.o: ../Core/Src/Fonts.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Fonts.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/SSD1331.o: ../Core/Src/SSD1331.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/SSD1331.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/encoder.o: ../Core/Src/encoder.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/encoder.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/gpio_f1.o: ../Core/Src/gpio_f1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/gpio_f1.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/i2c.o: ../Core/Src/i2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/i2c.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/menu.o: ../Core/Src/menu.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/menu.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/menu_callbacks.o: ../Core/Src/menu_callbacks.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/menu_callbacks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/spi.o: ../Core/Src/spi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/spi.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/system_stm32f1xx.o: ../Core/Src/system_stm32f1xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"D:/embedded_software_engineer/SW/STM32F1_radio/Core/Inc" -I"D:/embedded_software_engineer/SW/STM32F1_radio/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32f1xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

