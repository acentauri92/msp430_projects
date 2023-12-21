#Compiler root. MSP430 GCC downlaoded from TI's website
#https://www.ti.com/tool/MSP430-GCC-OPENSOURCE#downloads
MSP_ROOT_DIR := /home/dheeraj/msp430/msp430-gcc-9.3.1.11_linux64
MSP_GCC_BIN_DIR := $(MSP_ROOT_DIR)/bin

#Support files downloaded fromthe same TI GCC website 
MSP_SUPPORT_FILES_DIR := /home/dheeraj/msp430/msp430-gcc-support-files
MSP_INCLUDE_DIR := $(MSP_SUPPORT_FILES_DIR)/include

#Code composer studio
TI_CCS_DIR := /home/dheeraj/ti/ccs1250/ccs
DEBUG_BIN_DIR := $(TI_CCS_DIR)/ccs_base/DebugServer/bin
DEBUG_DRIVERS_DIR := $(TI_CCS_DIR)/ccs_base/DebugServer/drivers

LIBS_DIR := $(MSP_INCLUDE_DIR)

#MCU definition
MCU := msp430fr2433

#Source and include file folders
SRC_DIR			:= src
INCLUDES_DIR	:= inc
BUILD_DIR		:= build
OBJ_DIR			:= build/obj

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c))

#Tool definitions
CC := $(MSP_GCC_BIN_DIR)/msp430-elf-gcc
DEBUG := LD_LIBRARY_PATH=$(DEBUG_DRIVERS_DIR) $(DEBUG_BIN_DIR)/mspdebug

#Includes
CFLAGS = $(addprefix -I, $(INCLUDES_DIR) $(MSP_INCLUDE_DIR))

#Warnings
WFLAGS := -Wall -Wextra -Wshadow -Werror
#Compiler flags
CFLAGS += -mmcu=$(MCU) $(WFLAGS)

LDFLAGS := -mmcu=$(MCU) -L$(MSP_INCLUDE_DIR)

#Targets
TARGET := blink

.PHONY: $(TARGET) clean flash

.all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(BUILD_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir build

$(OBJ_DIR):
	mkdir -p build/obj

clean:
	rm -rf $(BUILD_DIR)

flash:
	$(DEBUG) tilib "prog $(BUILD_DIR)/$(TARGET)"

