default: build

CFILES = src/*.c
OFILES = build/main
HFILES = build/main.hex

build:
	avr-gcc -DF_CPU=16000000UL -mmcu=atmega328p $(CFILES) -o $(OFILES)

burn: build
	avr-objcopy -O ihex -R .eeprom $(OFILES) $(HFILES)
	avrdude -F -V -c arduino -p m328p -P /dev/ttyACM0 -b 115200 -U flash:w:$(HFILES)

clean:
	rm -f $(OFILES) $(HFILES)