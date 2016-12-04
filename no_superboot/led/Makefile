led.bin: start.o main.o led.o delay.o
	arm-linux-ld -Ttext 0xD0020010 -o led.elf $^
	arm-linux-objcopy -O binary led.elf led.bin
	arm-linux-objdump -D led.elf > led_elf.dis
	gcc mkv210_image.c -o mkmini210
	./mkmini210 led.bin 210.bin

%.o : %.S
	arm-linux-gcc -o $@ $< -c

%.o : %.c
	arm-linux-gcc -o $@ $< -c 

clean:
	rm *.o *.elf *.bin *.dis *.exe -f
