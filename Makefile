MAINFILENAME=main
MCU=atmega2560
#MCU=atmega328p
CFLAGS=-c -O3 -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -fno-devirtualize -fno-use-cxa-atexit -mmcu=$(MCU) -DF_CPU=$(XTAL) -lstdc++


all: size

main: avr-api wheel platform
	avr-g++ $(CFLAGS) "$(MAINFILENAME).cpp" -o "$(MAINFILENAME).o"

arch: main avr-api
	#cp ./avr-api/core.a ./
	avr-gcc-ar rcs core.a wheel.o
	avr-gcc-ar rcs core.a wheelDynSpd.o
	avr-gcc-ar rcs core.a platform.o
	avr-gcc-ar rcs core.a wheelEmpty.o
	avr-gcc-ar rcs core.a userWheel.o

link: arch
	avr-gcc -Wall -Wextra -Os -g -flto -fuse-linker-plugin -ffunction-sections -fdata-sections -Wl,--gc-sections -mmcu=$(MCU) main.o core.a ./avr-api/core.a -o main.elf -L./avr-api -lm

objcopy: link
	avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "$(MAINFILENAME).elf" "$(MAINFILENAME).eep"
	avr-objcopy -O ihex -R .eeprom  "$(MAINFILENAME).elf" "$(MAINFILENAME).hex"





wheel: avr-api
	avr-g++ $(CFLAGS) wheel.cpp -o wheel.o
	avr-g++ $(CFLAGS) wheelDynSpd.cpp -o wheelDynSpd.o
	avr-g++ $(CFLAGS) wheelEmpty.cpp -o wheelEmpty.o
	avr-g++ $(CFLAGS) userWheel.cpp -o userWheel.o

platform: avr-api
	avr-g++ $(CFLAGS) platform.cpp -o platform.o



avr-api:
	make -C ./avr-api clean
	make -C ./avr-api lib



clean:
	rm -rf ./*.o ./*.d ./*.eep ./*.elf ./*.hex
	make -C ./avr-api clean

size: objcopy
	avr-size -C $(MAINFILENAME).elf --mcu=$(MCU)
