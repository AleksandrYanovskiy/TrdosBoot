################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Module/File/BAD/BAD.cpp 

OBJS += \
./src/Module/File/BAD/BAD.o 

CPP_DEPS += \
./src/Module/File/BAD/BAD.d 


# Each subdirectory must supply rules for building sources it contributes
src/Module/File/BAD/%.o: ../src/Module/File/BAD/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


