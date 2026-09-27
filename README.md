# task-scheduler[TEST PROJECT]

Этот проект выложен только в качестве демонстрации текущего прогресса и для повторения использованных технологий

## Main goal:
Основная цель этого проекта была в изучении:
* System timer
* ASM вставки в код
* PSP и MSP
* IRQs and Handlers
* Макросов
* PendSV
---
* startup + linker scripts

## Аппаратная часть и среда разработки:
* Плата: STM32F411CEU6
* Отладчик: ST-Link v2
* Инструменты: STM32CubeIDE + arm-none-eabi-gcc, позже VSCode юзал

## Структура проекта:
* `Src/` и `Inc/` - исходный код
* `startup/` - стартап и линкер скрипты



## Сборник изученных вещей в этом проекте:
* Работа с документацией
* Header files
* Работа с регистрами
* Макросы
* Memory map
* Создание стэка
* do{} while(0);
* __attribute__ ((naked))
* extern word
* structures (union не была использована)
* Faults
* PSP и MSP
* Systick
* Assembly instructions (BL, POP, PUSH, MOV, MSR/MRS, STMDB, LDMIA)
* PendSV
* PRIMASK
* Startup file
* Linker script