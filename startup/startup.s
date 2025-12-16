; Reset and Vector Table

.syntax unified
.cpu cortex-m4
.thumb

.global Reset_Handler

.section .isr_vector,"a",%progbits
.word 0x20020000    /* Initialization of stack pointer */
.word Reset_Handler

.section .text
Reset_Handler:
  bl  main
  b   .