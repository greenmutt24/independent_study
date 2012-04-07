CC=/usr/bin/avr-gcc
MEGA=644
CFLAGS=-g -Os -Wall -mcall-prologues -std=c99 -mmcu=atmega$(MEGA)
OBJ2HEX=/usr/bin/avr-objcopy 
PROG=/usr/bin/avrdude
TARGET=rc

program : $(TARGET).hex
	$(PROG) -c avrispv2 -p m$(MEGA) -P /dev/ttyACM0 -e
	$(PROG) -c avrispv2 -p m$(MEGA) -P /dev/ttyACM0 -U flash:w:$(TARGET).hex

%.obj : %.o
	$(CC) $(CFLAGS) $< -o $@

%.hex : %.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

clean :
	rm -f *.hex *.obj *.o
