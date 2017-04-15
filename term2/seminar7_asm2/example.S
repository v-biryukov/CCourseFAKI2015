.data
scanf_format:
        .string "%d"

printf_format:
        .string "%d"

printf_newline:
        .string "\n"

a:
        .long 0
b:
        .long 0


.text
.globl main
main:
        movl  $0, %eax

        pushl $a
        pushl $scanf_format
        call  scanf
        addl  $8, %esp

        pushl $b
        pushl $scanf_format
        call  scanf
        addl  $8, %esp

        movl $0, %edx
        movl a, %eax
        movl b, %ebx
        cdq
        idiv %ebx

        pushl %eax
        pushl $printf_format
        call  printf
        addl  $8, %esp

        movl  $0, %eax
        ret
