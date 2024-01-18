# Project: 0x19. C - Stacks, Queues - LIFO, FIFO

## Overview

The Monty project is a simple interpreter for a subset of the Monty Bytecode language. It processes Monty bytecode files, executes the instructions, and produces the desired output. This README file provides essential information about the project, its functionalities, and how to use it.


## Resources

#### Read or watch:

* [Google](https://intranet.alxswe.com/rltoken/tn1X658KGumYYq_szFJI5w)
* [How do I use extern to share variables between source files in C?](https://intranet.alxswe.com/rltoken/0KVWTdE8xXy__jUfBfakCw)
* [Stacks and Queues in C](https://intranet.alxswe.com/rltoken/udmomL4F4mF630D2Z-ltqg)
* [Stack operations](https://intranet.alxswe.com/rltoken/fj_-SJXW-pWxgAnstsARoQ)
* [Queue operations](https://intranet.alxswe.com/rltoken/6Y_GVoIH_rV45xd7w0a9FA)
## Learning Objectives

### General

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

## Features

The Monty project supports the following opcodes:

- `push`: Pushes an element to the stack.
- `pall`: Prints all the values on the stack, starting from the top.
- `pint`: Prints the value at the top of the stack.
- `pop`: Removes the top element from the stack.
- `nop`: Does nothing.
- `swap`: Swaps the top two elements of the stack.
- `add`: Adds the top two elements of the stack.
- `sub`: Subtracts the top element of the stack from the second top element.
- `mul`: Multiplies the top two elements of the stack.
- `div`: Divides the second top element of the stack by the top element.
- `mod`: Computes the remainder of the division of the second top element by the top element.
- `pchar`: Prints the character at the top of the stack.
- `pstr`: Prints the string starting at the top of the stack.
- `rotl`: Rotates the stack to the top.
- `rotr`: Rotates the stack to the bottom.

## Getting Started

### Prerequisites

Before using the Monty interpreter, make sure you have the following installed on your system:

- GCC compiler

### Installation

1. Clone the Monty repository:

   ```bash
   git clone https://github.com/Isaiah-woko/monty.git

gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty