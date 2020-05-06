
CXXFLAGS=-Wall -I.

all: RPIserialCom

RPIserialCom: RPIserialCom.c
	@arm-rpizw-g++ $(CXXFLAGS) RPIserialCom.c -o RPIserialCom
	@chmod 777 RPIserialCom

.PHONY: clean
clean:
	@echo Removing executables...
	@rm -f RPIserialCom
	@echo Done

.PHONY: help
help:
	@echo Available targets:
	@echo all: Default target, compiles all source files into executables
	@echo bin/blinkLED: Compiles c code for blinking LED
	@echo bin/temperatur: Compiles c code for measuring temperature and displaying on terminal
	@echo bin/alarm: Compiles c code for alarm/temperature code
	@echo bin/net: Compiles c code for webpage based temperature display