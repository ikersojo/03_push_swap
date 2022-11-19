# 03_push_swap
# Introduction
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

In addition to input stack a, and auxiliary stack b is allowed. The program will include the user input in stack a and generate an empty stack b. After the sorting algorithm, the integers in stack a will be sorted and stack b will be empty.

## Example:
```
./push_swap 9 4 3 2 1 98 71 672 -1 -4 -876

a:
-------
9
4
3
2
1
98
71
672
-1
-4
-876
-------

b:
-------
-------

##########################################
########### SORTING  ALGORITHM ###########
##########################################

a:
-------
-876
-4
-1
1
2
3
4
9
71
98
672
-------

b:
-------
-------
```

## Allowed instructions to be shown in the std output:
The allowed instructions for sorting are:
- swap in a, b or both: sa, sb and ss (this last one not used).
- rotate in a, b or both: ra, rb and rr.
- reverse rotate in a, b or both: rra, rrb and rrr.
- push to stack: pa and pb.

The sequence of instructions is the only output to be generated by the program. This then will be check by a provided program (checker_Mac). The number of instructions required will also be used to grade the project.

# Layout and sequence of the program
The main program is divided in 3 main blocks:
- libft: general purpose functions.
- main: it will handle user input and prepare both stacks.
- ./src: functions exclusive to the program (instructions and sorting algorithms).

The sequence followed is:
1. Get user input
2. Since there are several ways of inputing numbers as arguments, the program will compile all inputs ina single string and convert that back to a set of argc and argv (malloc-ed).
3. It will test all argvs as valid, not repeated integers.
4. If the test is positive it will generate the stack a with the values from the argvs and an empty stack b (t_intlst type).
5. It will then launch the sorting function, and return stacks a and b as requested (a sorted and b empty). In the process of sorting it will print to std output each instruction performed.
6. Finally it will free the memory allocated to both lists and to argvs.


## Libft:
Libft ([extended version](https://github.com/ikersojo/00_extended_libft)) will be used as the source for any transversal auxiliary functions (such as ft_printf).

### t_intlst variable type and functions:
The new type of variable will hold the actual int and the pointer to next element of the linked list. It will also store three additional values which will be generated after each sorting instruction, to derive the cost of sorting that particular element:
- src cost: the cost of rotating an element to the top of the list (so that it can be pushed).
- dst cost: the cost of rotating the dst list (so that after the pushing from src, the element is already sorted).
- total cost: this adds both costs plus the pushing itself.

Note that each cost will be derived considering the smart rotation capability. This means:
- the cost will optimize if is easier to rotate or reverse rotate.
- also, if the rartion is in the same direction, it will ue the instruction to rotate both lists at the same time.

## Handling user input:
One key aspect of the program is to confirm a valid user input. See [doc](https://github.com/ikersojo/03_push_swap/tree/main/doc) for further detail on the requirements. The strategy followed is to join in a single string all inputed arguments and then divide it by spaces in a new argv string array (deriving also a new argc value).
Each new argv item will be tested to be an integer and not being repeated.
If everything goes well, all values will be coopied as integers (using ft_atoi) in list a.
Now, everithing is ready to sort the list.

NOTE: since argv is now malloc-ed and replaced, it will need to be freed at the end.

# Sorting Algorithm
## Sorting 2 elements
If they are not already sorted, swap them (sa).

## Sorting 3 elements
A list of 3 elemnts can be sorted without the need of auxiliary stack b, with only 1 or 2 instructions.

## Sorting 5 elements
The strategy is to push the max and min elements to b, then sort the remaining 3 elemts on a, and push back max and min. when pushing back max, rotate it to the end.


# Extras
Additional / auxiliary features have been build to help check the behaviour of the program
- make print: it will compile the main function with the macro PR (for PRint), showing both lists before and after the sorting.
- random numbers generator: in order to check the behaviour of the program, a generator of random numbers has been built. Compile it with make and use it as follows to have a valid input to be copied when testing push_swap:

```
./random_nums_generator/random_nums <n off numbers desired>
```

# Score
TBD...

NOTE: Bonus not submited.

## Scoring criteria (number of instructions)
In addition to having the program fully functional and without errors, the following will be used to provide the final score: