# 42-push_swap

A 42 project focused on sorting a stack of integers using a limited set of operations. The goal is to implement an efficient algorithm that outputs the smallest possible sequence of valid operations.

**Allowed Operations**
- `sa` / `sb`: Swap the first two elements of stack A / B
- `ss`: `sa` and `sb` at the same time
- `pa` / `pb`: Push the top element from one stack to the other
- `ra` / `rb`: Rotate stack A / B up by one
- `rr`: `ra` and `rb` at the same time
- `rra` / `rrb`: Reverse rotate stack A / B down by one
- `rrr`: `rra` and `rrb` at the same time

## Learning Outcomes

- Understanding fundamentals of sorting algorithms and their time complexities (Big O notation)
- Stack data structures using circular doubly linked lists
- Designing efficient sorting strategies under strict operational limits
- Implementing cost-based decision-making and movement optimization
- Error handling in C

## Project Structure

```
42-push_swap/
├── main.c               # Main logic and entry point
├── add_args_to_stack.c  # Stack init and input validation
├── operations_*.c       # Stack push, swap and rotate operations
├── sorting_*.c          # Sorting algorithm and helper functions
├── *_utils.c            # General / linked list management functions
├── ft_split.c           # Split in case nbr list provided as single arg
├── push_swap.h          # Header file
├── Makefile             # Build automation
└── README.md
```

## Sorting Strategy

This implementation is based on the [Turk algorithm](https://github.com/alx-sch/push_swap?tab=readme-ov-file), which focuses on cost-based decisions:

- Pushing elements from stack A to B in an optimal order
- Calculating the lowest cost move for each element
- Using double rotations (`rr`, `rrr`) to minimize operations
- Pushing elements back to stack A in sorted order

I explored adapting classic sorting algorithms such as quicksort and mergesort prior to this, but most were not efficient enough within the project's constraints. Radix sort would have been viable but did not guarantee sorting all tests below the minimum operations required for full marks.

## Data Structure Design

Stacks were implemented using **circular doubly linked lists** to allow straightforward implementation of stack rotation in both directions.

I considered using arrays for their performance advantages and since the maximum stack size is known at compile time. However, since the project focuses on minimizing the number of operations rather than execution time, I chose a linked list approach to simplify the operations and practise implementing a more advanced type of linked list.

## Compilation

```bash
make            # Builds push_swap
make fclean     # Removes object files and push_swap
make re         # Rebuilds everything
```

## Usage

```bash
./push_swap 3 2 1
```

Output:
```
sa
rra
```

## Notes

> ⚠️ **Norminette Compliance**  
> This project follows the [42 Norminette](https://github.com/42School/norminette) — a strict C coding style guide. It enforces rules like max 25 lines per function, separate declarations/assignments, and consistent formatting. Code is written for readability and structure over brevity.
