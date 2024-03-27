# **Monty**
> **Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.**

## 1. Monty byte code files

* Files containing Monty byte codes usually have the ```.m``` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
 push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$

```

* Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$

```

## 2. Usage

All the files are compiled in the following form:

```
 gcc -Wall -Werror -Wextra -pedantic *.c -o monty.
```

To run the program:

```
 ./monty bytecode_file
```

Available operation codes:

| Opcode | Description |
|------------------- | --------------|
|_push_   | Pushes an element to the stack. e.g (push 1 # pushes 1 into the stack)|
|_pall_   | Prints all the values on the stack, starting from the to of the stack.|
|_pint_   | Prints the value at the top of the stack.|
|_pop_    | Removes the to element of the stack. |
|_swap_   | Swaps the top to elements of the stack.|
|_add_    | Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.|
|_nop_    | This opcode does not do anything.|
|_sub_    | Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|_div_    | Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|_mul_ | Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|_mod_    | Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|_#_      | When the first non-space of a line is a # the line will be trated as a comment.|
|_pchar_  | Prints the integer stored in the top of the stack as its ascii value representation.|
|_pstr_   | Prints the integers stored in the stack as their ascii value representation. It stops printing when the value is 0, when the stack is over and when the value of the element is a non-ascii value.|
|_rotl_   | Rotates the top of the stack to the bottom of the stack.|
|_rotr_   | Rotates the bottom of the stack to the top of the stack.|
|_stack_  | This is the default behavior. Sets the format of the data into a stack (LIFO).|
|_queue_  | Sets the format of the data into a queue (FIFO).|

