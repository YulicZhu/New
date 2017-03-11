################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/sd/file_handler/file_handle.c" \

C_SRCS += \
../Sources/sd/file_handler/file_handle.c \

OBJS += \
./Sources/sd/file_handler/file_handle_c.obj \

OBJS_QUOTED += \
"./Sources/sd/file_handler/file_handle_c.obj" \

C_DEPS += \
./Sources/sd/file_handler/file_handle_c.d \

OBJS_OS_FORMAT += \
./Sources/sd/file_handler/file_handle_c.obj \

C_DEPS_QUOTED += \
"./Sources/sd/file_handler/file_handle_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/sd/file_handler/file_handle_c.obj: ../Sources/sd/file_handler/file_handle.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/sd/file_handler/file_handle.args" -o "Sources/sd/file_handler/file_handle_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/sd/file_handler/%.d: ../Sources/sd/file_handler/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


