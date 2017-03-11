################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/sd/sd.c" \

C_SRCS += \
../Sources/sd/sd.c \

OBJS += \
./Sources/sd/sd_c.obj \

OBJS_QUOTED += \
"./Sources/sd/sd_c.obj" \

C_DEPS += \
./Sources/sd/sd_c.d \

OBJS_OS_FORMAT += \
./Sources/sd/sd_c.obj \

C_DEPS_QUOTED += \
"./Sources/sd/sd_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/sd/sd_c.obj: ../Sources/sd/sd.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/sd/sd.args" -o "Sources/sd/sd_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/sd/%.d: ../Sources/sd/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


