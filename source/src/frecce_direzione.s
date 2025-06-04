.global frecce_direzione

frecce_direzione:
    
    push %ebp
    mov %esp, %ebp

    # input
    movl 8(%ebp), %eax           # %ebp+8 è indirizzo di key (variabile input)
    movl (%eax), %ecx            # %ecx contiene valore key

    # modifica
    cmpl $5, %ecx
    jg max
    cmpl $2, %ecx
    jl min
    jmp save_exit

max:
    movl $5, %ecx
    jmp save_exit

min:
    movl $2, %ecx
    jmp save_exit

save_exit:
    movl 12(%ebp), %eax          # %ebp+12 è indirizzo di frecce (variabile output)
    movl %ecx, (%eax)            # Salva il valore in frecce

exit:    
    movl %ebp, %esp
    pop %ebp
    ret
    