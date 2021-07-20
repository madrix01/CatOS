#pragma once

#include <drivers/console.h>	
#include <input.h>
#include <IDT.h>
#include <libs/stdlib.h>
#include "../../Kernel/Programs/console.cpp"

void print_prompt();
void BasicShell();
