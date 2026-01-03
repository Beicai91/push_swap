# Push_swap
Push_swap is an algorithmic project that aims to sort a stack of integers using a limited set of stack operations. The program receives a list of integers as input and outputs the smallest possible sequence of instructions required to sort them in ascending order.

The challenge lies in designing an efficient sorting strategy that minimizes the number of operations while respecting the constraints of stack-based manipulation. This project focuses on algorithm optimization, data structure manipulation, and complexity analysis.

## Technical notes
- Stack number <= 100
The algorithm uses a chunk-based strategy driven by pivot values extracted from a sorted copy of the input. For each pivot, all elements in stack A are scanned, and values below the current threshold are marked as belonging to the active chunk.

The program then repeatedly selects the marked element that can be brought to the top of stack A with the fewest rotations (`ra` or `rra`) and pushes it to stack B. This **greedy selection** minimizes the total number of operations during the transfer phase.

Using three pivot values, the input is effectively divided into four chunks. After the chunking phase, approximately 75% of the values (the lower three quartiles) have been moved to stack B, while the largest 25% remain in stack A.

In the final phase, a selection-sort–based strategy is used to firstly sort the remaining elements in stack A, then sort chunk by chunk stack B and remove elements in order to stack A. 

- Stack number > 100
For larger inputs, the program uses an **LSD radix sort** adapted to push_swap operations. Values are first normalized by assigning each node an index equal to its rank in the sorted order (0 for the smallest value up to N−1 for the largest). This avoids issues with negatives and reduces the range to a compact interval.

The sort then iterates through each bit position of the maximum index (from least significant to most significant). For every bit pass:

if the current bit of the top element’s index is 1, the element is kept in stack A using ra

if the bit is 0, the element is moved to stack B using pb

After processing all elements for that bit, all items in B are pushed back to A using pa. Repeating this process for all required bit positions sorts the stack in ascending order.

This method is efficient and predictable for large datasets, with a complexity of roughly **O(N · log N)** operations (based on the number of bits needed to represent N−1).

Radix sort produces a **consistent number of operations** because it processes every element once per bit position, independently of the initial order of the input. For a given input size, the number of bit passes is fixed, resulting in a predictable and stable operation count.