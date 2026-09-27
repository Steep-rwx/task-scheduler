ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(rwx)  : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Определение вершины стека в самом конце SRAM с выравниванием по 8 байт */
_estack = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        *(.isr_vector)
        *(.text)
        *(.text.*)
        *(.init)
        *(.fini)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    /* Секции для ARM unwind / exidx (критично для rdimon/semihosting) */
    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH

    .ARM.exidx :
    {
        *(.ARM.exidx*)
    } > FLASH

    _sidata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _edata = .;
    } > SRAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        __bss_start__ = _sbss;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
        __bss_end__ = _ebss;
    } > SRAM

    /* Выделение памяти под Кучу (Heap) и Стек (Stack) */
    ._user_heap_stack :
    {
        . = ALIGN(8);
        PROVIDE(end = .);
        PROVIDE(__end__ = .);
        . = . + 0x400; /* Минимальный размер кучи 1KB для printf */
        . = ALIGN(8);
    } > SRAM
}