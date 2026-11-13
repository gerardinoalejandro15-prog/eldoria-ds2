TARGET := eldoria
BUILD := build
SOURCES := source
DATA := data
INCLUDES := include

ARCH := -mthumb -mthumb-interwork

CFLAGS := -g -Wall -O2 $(ARCH)
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions
ASFLAGS := $(ARCH)

LDFLAGS := -specs=ds_arm9.specs
LIBS := -lnds9

include $(DEVKITPRO)/libnds/Makefile
