default: build

build:
	avr-gcc -DF_CPU=16000000UL -mmcu=atmega328p src/*.c -o build/main

burn: build
	avr-objcopy -O ihex -R .eeprom build/main build/main.hex
	avrdude -F -V -c arduino -p m328p -P /dev/ttyACM0 -b 115200 -U flash:w:build/main.hex

clean:
	rm -f build/main build/main.hex