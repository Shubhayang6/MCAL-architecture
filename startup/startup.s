.syntax unified
.cpu cortex-m4
.thumb

/* ================= Vector Table ================= */
.section .isr_vector,"a",%progbits
.word 0x20020000    /* Initial stack pointer */
.word Reset_Handler

/* ================= Code Section ================= */
.section .text
.global Reset_Handler
.thumb_func
Reset_Handler:
  bl  main
  b   .