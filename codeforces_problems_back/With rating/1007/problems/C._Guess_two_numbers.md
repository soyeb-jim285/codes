<h1 style='text-align: center;'> C. Guess two numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Vasya and Vitya play a game. Vasya thought of two integers $a$ and $b$ from $1$ to $n$ and Vitya tries to guess them. Each round he tells Vasya two numbers $x$ and $y$ from $1$ to $n$. If both $x=a$ and $y=b$ then Vitya wins. Else Vasya must say one of the three phrases: 

1. $x$ is less than $a$;
2. $y$ is less than $b$;
3. $x$ is greater than $a$ or $y$ is greater than $b$.

Vasya can't lie, but if multiple phrases are true, he may choose any of them. For example, if Vasya thought of numbers $2$ and $4$, then he answers with the phrase $3$ to a query $(3, 4)$, and he can answer with the phrase $1$ or phrase $3$ to a query $(1, 5)$.

Help Vitya win in no more than $600$ rounds. 

## Input

The first line contains a single integer $n$ ($1 \leq n \leq 10^{18}$) — the upper limit of the numbers.

## Interaction

First, you need to read the number $n$, after that you can make queries.

To make a query, print two integers: $x$ and $y$ ($1 \leq x, y \leq n$), then flush the output.

After each query, read a single integer $ans$ ($0 \leq ans \leq 3$).

If $ans > 0$, then it is the number of the phrase said by Vasya.

If $ans = 0$, it means that you win and your program should terminate.

If you make more than $600$ queries or make an incorrect query, you will get Wrong Answer.

Your solution will get Idleness Limit Exceeded, if you don't print anything or forget to flush the output.

To flush you need to do the following right after printing a query and a line end: 

* fflush(stdout) in C++;
* System.out.flush() in Java;
* stdout.flush() in Python;
* flush(output) in Pascal;
* For other languages see documentation.

Hacks format

For hacks, use the following format:

In the first line, print a single integer $n$ ($1 \leq n \leq 10^{18}$) — the upper limit of the numbers.

In the second line, print two integers $a$ and $b$ ($1 \leq a, b \leq n$) — the numbers which Vasya thought of.

In the third line, print a single integer $m$ ($1 \leq m \leq 10^5$) — the number of instructions for the interactor.

In each of the next $m$ lines, print five integers: $x_i$, $y_i$, $r^{12}_i$, $r^{13}_i$, and $r^{23}_i$ ($1 \leq x_i, y_i \leq n$), where $r^{ST}_i$ equals to either number $S$ or number $T$.

While answering the query $x\,\, y$, the interactor finds a number $i$ from $1$ to $n$ with the minimal value $|x-x_i| + |y-y_i|$. If multiple numbers can be chosen, the least $i$ is preferred. Then the interactor answers to the query, but if there are two phrases $S$ and $T$ that can be given, then $r^{ST}_i$ is chosen.

For example, the sample test data file contains the following: 


```
  
5  
2 4  
2  
2 5 1 1 2  
4 1 2 3 3  

```
## Example

## Input


```
5  
3  
3  
2  
1  
0
```
Output
```
4 3  
3 4  
3 3  
1 5  
2 4
```
## Note

Let's analyze the sample test. The chosen numbers are $2$ and $4$. The interactor was given two instructions.

For the query $(4, 3)$, it can return $2$ or $3$. Out of the two instructions the second one is chosen, so the interactor returns $a^{23}_2=3$.

For the query $(3, 4)$, it can return only $3$.

For the query $(3, 3)$, it can return $2$ or $3$. Out of the two instructions the first one is chosen (since in case of equal values, the least number is preferred), so the interactor returns $a^{23}_1=2$.

For the query $(1, 5)$, it can return $1$ or $3$. Out of the two instructions the first one is chosen, so the interactor returns $a^{13}_1=1$.

In the fifth query $(2, 4)$, the numbers are guessed correctly, the player wins.



#### tags 

#3000 #binary_search #interactive 