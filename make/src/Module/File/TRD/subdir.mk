################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Module/File/TRD/TRD.cpp 

OBJS += \
./src/Module/File/TRD/TRD.o 

CPP_DEPS += \
./src/Module/File/TRD/TRD.d 


# Each subdirectory must supply rules for building sources it contributes
src/Module/File/TRD/%.o: ../src/Module/File/TRD/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


