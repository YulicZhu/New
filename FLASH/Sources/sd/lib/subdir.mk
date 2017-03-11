################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/sd/lib/ccsbcs.c" \
"../Sources/sd/lib/diskio.c" \
"../Sources/sd/lib/ff.c" \

C_SRCS += \
../Sources/sd/lib/ccsbcs.c \
../Sources/sd/lib/diskio.c \
../Sources/sd/lib/ff.c \

OBJS += \
./Sources/sd/lib/ccsbcs_c.obj \
./Sources/sd/lib/diskio_c.obj \
./Sources/sd/lib/ff_c.obj \

OBJS_QUOTED += \
"./Sources/sd/lib/ccsbcs_c.obj" \
"./Sources/sd/lib/diskio_c.obj" \
"./Sources/sd/lib/ff_c.obj" \

C_DEPS += \
./Sources/sd/lib/ccsbcs_c.d \
./Sources/sd/lib/diskio_c.d \
./Sources/sd/lib/ff_c.d \

OBJS_OS_FORMAT += \
./Sources/sd/lib/ccsbcs_c.obj \
./Sources/sd/lib/diskio_c.obj \
./Sources/sd/lib/ff_c.obj \

C_DEPS_QUOTED += \
"./Sources/sd/lib/ccsbcs_c.d" \
"./Sources/sd/lib/diskio_c.d" \
"./Sources/sd/lib/ff_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/sd/lib/ccsbcs_c.obj: ../Sources/sd/lib/ccsbcs.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/sd/lib/ccsbcs.args" -o "Sources/sd/lib/ccsbcs_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/sd/lib/%.d: ../Sources/sd/lib/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/sd/lib/diskio_c.obj: ../Sources/sd/lib/diskio.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/sd/lib/diskio.args" -o "Sources/sd/lib/diskio_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/sd/lib/ff_c.obj: ../Sources/sd/lib/ff.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/sd/lib/ff.args" -o "Sources/sd/lib/ff_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


