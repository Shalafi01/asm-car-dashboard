.global gomme

.section .data
string:
    .asciz "Pressione gomme resettata\n"

.section .text
gomme:
    pushl %ebp
    movl %esp, %ebp

    subl $4, %esp
    movl $string, (%esp)

    call printf
    addl $4, %esp

    movl $0, %eax

    movl %ebp, %esp
    popl %ebp
    ret
