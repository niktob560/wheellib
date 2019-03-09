MAINFILENAME=main
MCU=atmega2560
CFLAGS=-c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -fno-devirtualize -fno-use-cxa-atexit -mmcu=$(MCU) -DF_CPU=$(XTAL) 

all: main

main: avr-api wheel platform
	avr-g++ $(CFLAGS) "$(MAINFILENAME).cpp" -o "$(MAINFILENAME).o"
	avr-gcc -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=$(MCU)  -o "$(MAINFILENAME).elf" "$(MAINFILENAME).o" -lm
	avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "$(MAINFILENAME).elf" "$(MAINFILENAME).eep"
	avr-objcopy -O ihex -R .eeprom  "$(MAINFILENAME).elf" "$(MAINFILENAME).hex"

wheel: avr-api
	avr-g++ $(CFLAGS) wheel.cpp

platform: avr-api
	avr-g++ $(CFLAGS) platform.cpp

avr-api:
	make -C ./avr-api lib

clean:
	rm -rf ./*.o ./*.d ./*.eep ./*.elf ./*.hex  
	make -C ./avr-api clean

size:
	avr-size -B $(MAINFILENAME).hex
