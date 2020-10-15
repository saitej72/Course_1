#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Make file which supports the Host (Linux) and the Cross platform: ARM
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#		<FILE>.o - Builds <FILE>.o object file
#	   	<FILE>.i - Generate the preprocessed output of the <FILE>.i
#   		<FILE>.asm - Generate assembly output of <FILE>.asm	
#	      
#      		compile-all : Compiles all files, doesn't build
#	 	build: Compile all object files and link into a final executable
#	 	clean: removes all generated files.
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

#Common Flags
FLAGS = -Wall \
	-Werror\
	-g \
	-O0\
	-std=c99
TARGET = c1m4
INFO=VERBOS

ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = ld
	CFLAGS = $(FLAGS)
	CPPFLAGS = -DHOST -DVERBOSE $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SIZE = size
	OBJDUMP = objdump
endif

ifeq ($(PLATFORM),MSP432)
	# Architectures Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	OTHER_SPECS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CPPFLAGS = -DMSP432 -D$(INFO) $(INCLUDES)
	CFLAGS = $(FLAGS) $(OTHER_SPECS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)

#Had to use this because other than memory.* and main.* other files are not getting deleted.  
FILES = *.asm *.i *.o *.d

# using -c flag to stop before linking
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -S to generate assembly file
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -E to generate preprocessed file , so i only need CPPFLAGS
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

#using -E -M to generate dependency files  
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

# compile-all will generate all object files for all source files without linking
.PHONY: compile-all
compile-all:$(OBJS)
		$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o
.PHONY: build
build: $(DEPS)
build: $(TARGET).out 

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(FILES) $(ASMS) $(PRES) $(TARGET).out $(TARGET).map 


