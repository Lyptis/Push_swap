# Push_swap
---

This project goal is to sort int sized numbers using 2 stacks and rules.
It will return all the rules needed to sort the numbers.

## Rules
---
>sa (swap_a) : Intervert the first two element of stack A

>sb (swap_b ) : Intervert the first two element of stack B

>ss : sa and sb at the same time.

>pa (push_a) : Take the first number on stack B and put it on A.

>pb (push_b) : Take the first number on stack A and put it on B.

>ra (rotate_a) : Rotate all numbers from A to one position up, so first become last

>rb (rotate_b) : Rotate all numbers from B to one position up, so first become last

>rr : ra and rb at the same time.

>rra (reverse_rotate_a) : Rotate all numbers from A to one position down, so last become first

>rrb (reverse_rotate_b) : Rotate all numbers from B to one position down, so last become first

>rrr : rra and rrb at the same time.

---
## Algorythm

---
The program use Radix sort; In short, it allow us to sort, using only digits (less significant to more significant).
[GeeksforGeeks video](https://youtu.be/nu4gDuFabIM).

We can use this method with binary, by using the bitwise operator `AND (&)`, and for each bits by slinding to the next bit with `shift right (>>)`.

## Running

---
The program can be executed by running `$>./push_swap [number_1] [number_2] [...]` or  `$>./push_swap "number_1 number_2 ..."`
It doesn't accept non-numerical numbers nor ASCII caracters. It doesn't allow same numbers.
