    global main
    extern printf

    section .text
main:
    push rbp
    mov rbp, rsp

    mov rdi, fmt
    mov rax, 0
    call printf

    mov rax, 0
    mov rsp, rbp
    pop rbp
    ret

    section .rodata
fmt:
    db "Hello, ALX", 10, 0
