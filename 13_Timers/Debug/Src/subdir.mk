################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/gpio.c \
../Src/led.c \
../Src/main.c \
../Src/rcc.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/systick.c \
../Src/tim.c \
../Src/uart.c 

OBJS += \
./Src/adc.o \
./Src/gpio.o \
./Src/led.o \
./Src/main.o \
./Src/rcc.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/systick.o \
./Src/tim.o \
./Src/uart.o 

C_DEPS += \
./Src/adc.d \
./Src/gpio.d \
./Src/led.d \
./Src/main.d \
./Src/rcc.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/systick.d \
./Src/tim.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F746NGHx -DSTM32F7 -DSTM32F746xx -c -I../Inc -I"C:/Users/Joe/Documents/STM32 Bare-Metal Workspace/chip_headers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Joe/Documents/STM32 Bare-Metal Workspace/chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/main.o: ../Src/main.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F746NGHx -DSTM32F7 -DSTM32F746xx -c -I../Inc -I"C:/Users/Joe/Documents/STM32 Bare-Metal Workspace/chip_headers/CMSIS/Include" -I"C:/Users/Joe/Documents/STM32 Bare-Metal Workspace/chip_headers/CMSIS/Device/ST/STM32F7xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/adc.d ./Src/adc.o ./Src/adc.su ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/led.d ./Src/led.o ./Src/led.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/rcc.d ./Src/rcc.o ./Src/rcc.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/systick.d ./Src/systick.o ./Src/systick.su ./Src/tim.d ./Src/tim.o ./Src/tim.su ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

