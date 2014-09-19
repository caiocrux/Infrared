CC=avr-gcc
MCU=atmega328p
CFLAGS= -g -Os
TARGET=infrared

bin: main.o usart.o interrupt.o timer.o
	$(CC) $(CFLAGS) -mmcu=$(MCU) main.o usart.o interrupt.o timer.o -o $(TARGET)

hex :
	avr-objcopy -O ihex -R .eeprom $(TARGET) $(TARGET).hex 

flash:
	avrdude -v -v -v -c arduino -p m328p -P /dev/ttyUSB0 -b57600 -U flash:w:$(TARGET).hex
	
main.o:src/main.c
	$(CC) $(CFLAGS) -mmcu=$(MCU) -c src/main.c

usart.o: src/usart.c include/usart.h
	$(CC) $(CFLGS) -mmcu=$(MCU) -c src/usart.c

interrupt.o: src/interrupt.c include/interrupt.h
	$(CC) $(CFLGS) -mmcu=$(MCU) -c src/interrupt.c

timer.o: src/timer.c include/timer.h
	$(CC) $(CFLGS) -mmcu=$(MCU) -c src/timer.c

clean:
	rm -f *.o $(TARGET)*






