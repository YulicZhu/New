################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Button_INT.c" \
"../Sources/DIGTUBE_LED.c" \
"../Sources/Exceptions.c" \
"../Sources/IntcInterrupts.c" \
"../Sources/MODULE_Init.c" \
"../Sources/WRITE_SD.c" \
"../Sources/adc.c" \
"../Sources/ivor_branch_table.c" \
"../Sources/main.c" \
"../Sources/pwm_mc.c" \
"../Sources/spi.c" \

C_SRCS += \
../Sources/Button_INT.c \
../Sources/DIGTUBE_LED.c \
../Sources/Exceptions.c \
../Sources/IntcInterrupts.c \
../Sources/MODULE_Init.c \
../Sources/WRITE_SD.c \
../Sources/adc.c \
../Sources/ivor_branch_table.c \
../Sources/main.c \
../Sources/pwm_mc.c \
../Sources/spi.c \

OBJS += \
./Sources/Button_INT_c.obj \
./Sources/DIGTUBE_LED_c.obj \
./Sources/Exceptions_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/MODULE_Init_c.obj \
./Sources/WRITE_SD_c.obj \
./Sources/adc_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \
./Sources/pwm_mc_c.obj \
./Sources/spi_c.obj \

OBJS_QUOTED += \
"./Sources/Button_INT_c.obj" \
"./Sources/DIGTUBE_LED_c.obj" \
"./Sources/Exceptions_c.obj" \
"./Sources/IntcInterrupts_c.obj" \
"./Sources/MODULE_Init_c.obj" \
"./Sources/WRITE_SD_c.obj" \
"./Sources/adc_c.obj" \
"./Sources/ivor_branch_table_c.obj" \
"./Sources/main_c.obj" \
"./Sources/pwm_mc_c.obj" \
"./Sources/spi_c.obj" \

C_DEPS += \
./Sources/Button_INT_c.d \
./Sources/DIGTUBE_LED_c.d \
./Sources/Exceptions_c.d \
./Sources/IntcInterrupts_c.d \
./Sources/MODULE_Init_c.d \
./Sources/WRITE_SD_c.d \
./Sources/adc_c.d \
./Sources/ivor_branch_table_c.d \
./Sources/main_c.d \
./Sources/pwm_mc_c.d \
./Sources/spi_c.d \

OBJS_OS_FORMAT += \
./Sources/Button_INT_c.obj \
./Sources/DIGTUBE_LED_c.obj \
./Sources/Exceptions_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/MODULE_Init_c.obj \
./Sources/WRITE_SD_c.obj \
./Sources/adc_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \
./Sources/pwm_mc_c.obj \
./Sources/spi_c.obj \

C_DEPS_QUOTED += \
"./Sources/Button_INT_c.d" \
"./Sources/DIGTUBE_LED_c.d" \
"./Sources/Exceptions_c.d" \
"./Sources/IntcInterrupts_c.d" \
"./Sources/MODULE_Init_c.d" \
"./Sources/WRITE_SD_c.d" \
"./Sources/adc_c.d" \
"./Sources/ivor_branch_table_c.d" \
"./Sources/main_c.d" \
"./Sources/pwm_mc_c.d" \
"./Sources/spi_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Button_INT_c.obj: ../Sources/Button_INT.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Button_INT.args" -o "Sources/Button_INT_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/DIGTUBE_LED_c.obj: ../Sources/DIGTUBE_LED.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/DIGTUBE_LED.args" -o "Sources/DIGTUBE_LED_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Exceptions_c.obj: ../Sources/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Exceptions.args" -o "Sources/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/IntcInterrupts_c.obj: ../Sources/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/IntcInterrupts.args" -o "Sources/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/MODULE_Init_c.obj: ../Sources/MODULE_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MODULE_Init.args" -o "Sources/MODULE_Init_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/WRITE_SD_c.obj: ../Sources/WRITE_SD.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/WRITE_SD.args" -o "Sources/WRITE_SD_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/adc_c.obj: ../Sources/adc.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/adc.args" -o "Sources/adc_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ivor_branch_table_c.obj: ../Sources/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ivor_branch_table.args" -o "Sources/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/pwm_mc_c.obj: ../Sources/pwm_mc.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/pwm_mc.args" -o "Sources/pwm_mc_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/spi_c.obj: ../Sources/spi.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/spi.args" -o "Sources/spi_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


