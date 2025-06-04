.global on_off

.section .data
    on: .asciz "ON"     
    off: .asciz "OFF"   

.section .text
on_off:
    push %ebp              
    mov %esp, %ebp         

    mov 8(%ebp), %eax       # carica input

    cmpl $0x4e4f, (%eax)    # controlla sia ON
    jne switch_on          

    movl $0x46464f, (%eax)  # mette a OFF
    mov $0, %eax           
    jmp exit        

switch_on:
    movl $0x4e4f, (%eax)    # mette a ON
    mov $0, %eax           

exit:
    mov %ebp, %esp         
    pop %ebp               
    ret                    
