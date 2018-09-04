################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Module/File/SCL/SCL.cpp 

OBJS += \
./src/Module/File/SCL/SCL.o 

CPP_DEPS += \
./src/Module/File/SCL/SCL.d 


# Each subdirectory must supply rules for building sources it contributes
src/Module/File/SCL/%.o: ../src/Module/File/SCL/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


