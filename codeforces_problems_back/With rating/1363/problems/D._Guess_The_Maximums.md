<h1 style='text-align: center;'> D. Guess The Maximums</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Ayush devised a new scheme to set the password of his lock. The lock has $k$ slots where each slot can hold integers from $1$ to $n$. The password $P$ is a sequence of $k$ integers each in the range $[1, n]$, $i$-th element of which goes into the $i$-th slot of the lock.

To set the password of his lock, Ayush comes up with an array $A$ of $n$ integers each in the range $[1, n]$ (not necessarily distinct). He then picks $k$ non-empty mutually disjoint subsets of indices $S_1, S_2, ..., S_k$ $(S_i \underset{i \neq j} \cap S_j = \emptyset)$ and sets his password as $P_i = \max\limits_{j \notin S_i} A[j]$. In other words, the $i$-th integer in the password is equal to the maximum over all elements of $A$ whose indices do not belong to $S_i$.

You are given the subsets of indices chosen by Ayush. You need to guess the password. To make a query, you can choose a non-empty subset of indices of the array and ask the maximum of all elements of the array with index in this subset. You can ask no more than 12 queries.

## Input

The first line of the input contains a single integer $t$ $(1 \leq t \leq 10)$ — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ $(2 \leq n \leq 1000, 1 \leq k \leq n)$ — the size of the array and the number of subsets. $k$ lines follow. The $i$-th line contains an integer $c$ $(1 \leq c \lt n)$ — the size of subset $S_i$, followed by $c$ distinct integers in the range $[1, n]$  — indices from the subset $S_i$.

It is guaranteed that the intersection of any two subsets is empty.

## Interaction

To ask a query print a single line: 

* In the beginning print "? c " (without quotes) where $c$ $(1 \leq c \leq n)$ denotes the size of the subset of indices being queried, followed by $c$ distinct space-separated integers in the range $[1, n]$.

For each query, you will receive an integer $x$ — the maximum of value in the array among all the indices queried. If the subset of indices queried is invalid or you exceeded the number of queries (for example one of the indices is greater than $n$) then you will get $x = -1$. In this case, you should terminate the program immediately.

When you have guessed the password, print a single line "! " (without quotes), followed by $k$ space-separated integers  — the password sequence.

Guessing the password does not count towards the number of queries asked.

After this, you should read a string. If you guess the password correctly, you will receive the string "Correct". In this case, you should continue solving the remaining test cases. If the guessed password is incorrect, you will receive the string "Incorrect". In this case, you should terminate the program immediately.

The interactor is not adaptive. The array $A$ does not change with queries.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To hack the solution use the following test format:

The first line of the input should contain a single integer $t$ $(1 \leq t \leq 10)$ — the number of test cases. 

The first line of each test case should contain two integers $n$ and $k$ $(2 \leq n \leq 1000, 1 \leq k \leq n)$ — the size of the array and the number of subsets. The next line should consist of $n$ space separated integers in the range $[1, n]$ — the array $A$. $k$ lines should follow. The $i$-th line should contain an integer $c$ $(1 \leq c \lt n)$ — the size of subset $S_i$, followed by $c$ distinct integers in the range $[1, n]$  — indices from the subset $S_i$.

The intersection of any two subsets has to be empty.

## Example

## Input


```

1
4 2
2 1 3
2 2 4

1

2

3

4

Correct
```
Output
```

? 1 1

? 1 2

? 1 3

? 1 4

! 4 3
```
## Note

The array $A$ in the example is $[1, 2, 3, 4]$. The length of the password is $2$. The first element of the password is the maximum of $A[2]$, $A[4]$ (since the first subset contains indices $1$ and $3$, we take maximum over remaining indices). The second element of the password is the maximum of $A[1]$, $A[3]$ (since the second subset contains indices $2$, $4$).

Do not forget to read the string "Correct" / "Incorrect" after guessing the password.



#### tags 

#2100 #binary_search #implementation #interactive #math 