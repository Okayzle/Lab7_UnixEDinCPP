################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/doc.cpp \
../src/ed.cpp \
../src/line.cpp \
../src/object.cpp 

OBJS += \
./src/doc.o \
./src/ed.o \
./src/line.o \
./src/object.o 

CPP_DEPS += \
./src/doc.d \
./src/ed.d \
./src/line.d \
./src/object.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


