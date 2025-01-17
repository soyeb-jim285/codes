<h1 style='text-align: center;'> G. Vabank</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gustaw is the chief bank manager in a huge bank. He has unlimited access to the database system of the bank, in a few clicks he can move any amount of money from the bank's reserves to his own private account. However, the bank uses some fancy AI fraud detection system that makes stealing more difficult.

Gustaw knows that the anti-fraud system just detects any operation that exceeds some fixed limit $M$ euros and these operations are checked manually by a number of clerks. Thus, any fraud operation exceeding this limit is detected, while any smaller operation gets unnoticed.

Gustaw doesn't know the limit $M$ and wants to find it out. In one operation, he can choose some integer $X$ and try to move $X$ euros from the bank's reserves to his own account. Then, the following happens. 

* If $X \le M$, the operation is unnoticed and Gustaw's account balance raises by $X$ euros.
* Otherwise, if $X > M$, the fraud is detected and cancelled. Moreover, Gustaw has to pay $X$ euros from his own account as a fine. If he has less than $X$ euros on the account, he is fired and taken to the police.

Initially Gustaw has $1$ euro on his account. Help him find the exact value of $M$ in no more than $105$ operations without getting him fired.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$).

For each test case, there is no input prior to your first query, but you can be sure that $M$ is integer, and $0 \le M \le 10^{14}$.

## Output

For each test case, when you know the exact value of $M$, print a single line with format "! $M$". After that your program should proceed to the next test case or terminate, if it is the last one.

## Interaction

When you want to make an operation, print a single line with format "? $X$", denoting that you try to move $X$ euros ($1 \le X \le 10^{14}$). As a response, read a single line that can take the following values: 

* "Lucky!", if $X \le M$. Your balance raises by $X$.
* "Fraudster!", if $X > M$. Your balance decreases by $X$.
* "Fired!", if $X > M$, but you can't pay $X$ euros of fine. In this case your program must terminate immediately. You also get this response if you exceed the number of queries.

You can make at most $105$ such queries in each test case.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To make a hack, prepare an input in the following format.

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Each test case is described with a line containing a single integer $M$ ($0 \le M \le 10^{14}$).

## Example

## Input


```

1

Lucky!

Lucky!

Lucky!

Lucky!

Lucky!

Fraudster!

```
## Output


```

? 1

? 2

? 3

? 4

? 5

? 6

! 5

```
## Note

In the example $M = 5$, so the operation with $X = 6$ is detected. At this moment, Gustaw's balance is $16$ euros, so he just pays fine.



#### tags 

#3200 #binary_search #interactive 