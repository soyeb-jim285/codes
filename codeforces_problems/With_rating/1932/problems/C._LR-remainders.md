<h1 style='text-align: center;'> C. LR-remainders</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $n$, a positive integer $m$, and a string of commands of length $n$. Each command is either the character 'L' or the character 'R'.

Process all $n$ commands in the order they are written in the string $s$. Processing a command is done as follows:

* First, output the remainder of the product of all elements of the array $a$ when divided by $m$.
* Then, if the command is 'L', remove the leftmost element from the array $a$, if the command is 'R', remove the rightmost element from the array $a$.

## Note

 that after each move, the length of the array $a$ decreases by $1$, and after processing all commands, it will be empty.

Write a program that will process all commands in the order they are written in the string $s$ (from left to right).

### Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases in the input. Then descriptions of $t$ test cases follow.

Each test case of the input is given by three lines.

The first line contains two integers $n$ and $m$ ($1 \le n \le 2\cdot10^5, 1 \le m \le 10^4$) — the initial length of the array $a$ and the value to take the remainder by.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^4$) — the elements of the array $a$.

The third line contains a string $s$ consisting of $n$ characters 'L' and 'R'.

It is guaranteed that the sum of the values of $n$ for all test cases in a test does not exceed $2\cdot10^5$.

### Output

For each test case, output $n$ integers $b_1, b_2, \dots, b_n$, where $b_i$ is the remainder when dividing the product of all elements of the current state of the array $a$ by $m$ at the beginning of the execution of the $i$-th command.

## Example

### Input


```text
44 63 1 4 2LRRL5 11 1 1 1 1LLLLL6 81 2 3 4 5 6RLLLRR1 1000010000R
```
### Output

```text

0 2 4 1 
0 0 0 0 0 
0 0 0 4 4 4 
0 

```
## Note

In the first test case of the example:

* $3 \cdot 1 \cdot 4 \cdot 2 \bmod 6 = 24 \bmod 6 = 0$;
* $s_1 = \text{L}$, so we remove the first element and get the array $[1, 4, 2]$;
* $1 \cdot 4 \cdot 2 \bmod 6 = 8 \bmod 6 = 2$;
* $s_2 = \text{R}$, so we remove the last element and get the array $[1, 4]$;
* $1 \cdot 4 \bmod 6 = 4 \bmod 6 = 4$;
* $s_3 = \text{R}$, so we remove the last element and get the array $[1]$;
* $1 \bmod 6 = 1$;
* $s_4 = \text{L}$, so we remove the first element and get an empty array.


#### Tags 

#1400 #NOT OK #brute_force #data_structures #implementation #math #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_927_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
