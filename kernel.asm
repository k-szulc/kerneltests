;;kerne.asm
bits 32
section .text
	;multiboot spec
	align 4
	dd 0x1BADB002 	;magic
	dd 0x00 	;flags
	dd - ( 0x1BADB002 - 0x00)	;checksum m+f+c should be zero

global start
global keyboard_handler
global read_port
globabl write_port
global load_idt


extern kmain
extern keyboard_handler_main

read_port:
	mov edx, [esp + 4]

	in al,dx
	ret

write_port:
	mov edx, [exp + 4]


keyboard_handler:
	call keyboard_handler_main
	iretd

start:
	cli	;block interrupts
	mov esp, stack_space ;set stack pointer
	call kmain
	hlt	;halt the CPU

section .bss
resb 8192	;8KB for stack
stack_space:
