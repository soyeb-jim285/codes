<h1 style='text-align: center;'> E. Deleting Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

This is an interactive problem.

There is an unknown integer $x$ ($1\le x\le n$). You want to find $x$.

At first, you have a set of integers $\{1, 2, \ldots, n\}$. You can perform the following operations no more than $10000$ times:

* A $a$: find how many numbers are multiples of $a$ in the current set.
* B $a$: find how many numbers are multiples of $a$ in this set, and then delete all multiples of $a$, but $x$ will never be deleted (even if it is a multiple of $a$). In this operation, $a$ must be greater than $1$.
* C $a$: it means that you know that $x=a$. This operation can be only performed once.

Remember that in the operation of type B $a>1$ must hold.

Write a program, that will find the value of $x$.

## Input

The first line contains one integer $n$ ($1\le n\le 10^5$). The remaining parts of the input will be given throughout the interaction process.

## Interaction

In each round, your program needs to print a line containing one uppercase letter A, B or C and an integer $a$ ($1\le a\le n$ for operations A and C, $2\le a\le n$ for operation B). This line desribes operation you make.

If your operation has type C your program should terminate immediately.

Else your program should read one line containing a single integer, which is the answer to your operation.

After outputting each line, don't forget to flush the output. To do it use:

* fflush(stdout) in C/C++;
* System.out.flush() in Java;
* sys.stdout.flush() in Python;
* flush(output) in Pascal;
* See the documentation for other languages.

It is guaranteed, that the number $x$ is fixed and won't change during the interaction process.

Hacks:

To make a hack, use such input format:

The only line should contain two integers $n$, $x$ ($1 \leq x \leq n \leq 10^5$).

## Example

## Input


```

10

2

4

0
```
Output
```


B 4

A 2

A 8

C 4

```
## Note

## Note

 that to make the sample more clear, we added extra empty lines. You shouldn't print any extra empty lines during the interaction process.

In the first test $n=10$ and $x=4$.

Initially the set is: $\{1,2,3,4,5,6,7,8,9,10\}$.

In the first operation, you ask how many numbers are multiples of $4$ and delete them. The answer is $2$ because there are two numbers divisible by $4$: $\{4,8\}$. $8$ will be deleted but $4$ won't, because the number $x$ will never be deleted. Now the set is $\{1,2,3,4,5,6,7,9,10\}$.

In the second operation, you ask how many numbers are multiples of $2$. The answer is $4$ because there are four numbers divisible by $2$: $\{2,4,6,10\}$.

In the third operation, you ask how many numbers are multiples of $8$. The answer is $0$ because there isn't any number divisible by $8$ in the current set.

In the fourth operation, you know that $x=4$, which is the right answer.



#### tags 

#2600 #interactive #math #number_theory 