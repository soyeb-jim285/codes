<h1 style='text-align: center;'> D. Bit Guessing Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Kira has a hidden positive integer $n$, and Hayato needs to guess it.

Initially, Kira gives Hayato the value $\mathrm{cnt}$ — the number of unit bits in the binary notation of $n$. To guess $n$, Hayato can only do operations of one kind: choose an integer $x$ and subtract it from $n$. 
## Note

 that after each operation, the number $n$ changes. Kira doesn't like bad requests, so if Hayato tries to subtract a number $x$ greater than $n$, he will lose to Kira. After each operation, Kira gives Hayato the updated value $\mathrm{cnt}$ — the number of unit bits in the binary notation of the updated value of $n$.

Kira doesn't have much patience, so Hayato must guess the original value of $n$ after no more than $30$ operations.

Since Hayato is in elementary school, he asks for your help. Write a program that guesses the number $n$. Kira is an honest person, so he chooses the initial number $n$ before all operations and does not change it afterward.

### Input

The input data contains several test cases. The first line contains one integer $t$ ($1 \le t \le 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains the number $\mathrm{cnt}$ — the initial number of unit bits in the binary notation $n$.

The hidden integer $n$ satisfies the following constraint: $1 \le n \le 10^9$.

## Interaction

To guess $n$, you can perform the operation at most $30$ times. To do that, print a line with the following format: "- x" ($1 \le x \le 10^9$).

After this operation, the number $x$ is subtracted from $n$, and therefore $n$ is changed. If the number $x$ is greater than the current value of $n$, then the request is considered invalid.

After the operation read a line containing a single non-negative integer $\mathrm{cnt}$ — the number of unit bits in the binary notation of the current $n$ after the operation.

When you know the initial value of $n$, print one line in the following format: "! n" ($1 \le n \le 10^9$).

After that, move on to the next test case, or terminate the program if there are none.

If your program performs more than $30$ operations for one test case, subtracts a number $x$ greater than $n$, or makes an incorrect request, then response to the request will be -1, after receiving such response, your program must exit immediately to receive the Wrong Answer verdict. Otherwise, you can get any other verdict.

After printing a query or the answer, do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To make a hack, use the following format.

The first line should contain a single integer $t$ ($1 \leq t \leq 500$).

Each test case should contain one integer $n$ ($1 \leq n \leq 10^9$) on a separate line.

## Example

### Input


```text

3

1

0

1

1

0

2

1

0
```
#Output
```text

- 1

! 1

- 1

- 1

! 2

- 2

- 1

! 3
```
## Note

For example, the number of unit bits in number $6$ is $2$, because binary notation of $6$ is $110$. For $13$ the number of unit bits is $3$, because $13_{10} = 1101_2$.

In the first test case, $n = 1$, so the input is the number $1$. After subtracting one from $n$, it becomes zero, so the number of unit bits in it is $0$.

In the third test case, $n = 3$, which in binary representation looks like $3_{10} = 11_2$, so the input is the number of ones, that is $2$. After subtracting $2$, $n = 1$, so the number of unit bits is now $1$. After subtracting one from $n$, it becomes equal to zero.

## Note

 that the blank lines in the input and output examples are shown for clarity and are not present in the actual interaction.



#### Tags 

#1800 #NOT OK #binary_search #bitmasks #constructive_algorithms #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_846_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
