TARGET=rc
MCU=atmega644
CFILES=rc.c usart.c
PROG=/usr/bin/avrdude


# everything past this line need not be changed
# except maybe cflags, but that's it

CFLAGS=-Os -Wall -std=c99 -mcall-prologues
OFILES=${CFILES:.c=.o}

all: ${TARGET}.hex ${TARGET}.lst

program : $(TARGET).hex
	$(PROG) -c avrispv2 -p m644 -P /dev/ttyACM0 -e
	$(PROG) -c avrispv2 -p m644 -P /dev/ttyACM0 -U flash:w:$(TARGET).hex


# hexfile generation step
${TARGET}.hex: ${TARGET}.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

# linker step
${TARGET}.elf: ${OFILES}
	avr-gcc -mmcu=${MCU} -o $@ $^

# compile step
%.o: %.c
	avr-gcc ${CFLAGS} -mmcu=${MCU} -g -c -o $@ $<

clean:
	@rm -f *.o
	@rm -f "${TARGET}.hex"
	@rm -f "${TARGET}.elf"
	@rm -f "${TARGET}.lst"

# dumps the executable to a disassembly
${TARGET}.lst: ${TARGET}.elf
	avr-objdump -g -h -S $< > ${TARGET}.lst
