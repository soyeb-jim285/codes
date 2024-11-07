<h1 style='text-align: center;'> F. Vitaly and Advanced Useless Algorithms</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vitaly enrolled in the course Advanced Useless Algorithms. The course consists of $n$ tasks. Vitaly calculated that he has $a_i$ hours to do the task $i$ from the day he enrolled in the course. That is, the deadline before the $i$-th task is $a_i$ hours. The array $a$ is sorted in ascending order, in other words, the job numbers correspond to the order in which the assignments are turned in.

Vitaly does everything conscientiously, so he wants to complete each task by $100$ percent, or more. Initially, his completion rate for each task is $0$ percent.

Vitaly has $m$ training options, each option can be used not more than once. The $i$th option is characterized by three integers: $e_i, t_i$ and $p_i$. If Vitaly uses the $i$th option, then after $t_i$ hours (from the current moment) he will increase the progress of the task $e_i$ by $p_i$ percent. 

For example, let Vitaly have $3$ of tasks to complete. Let the array $a$ have the form: $a = [5, 7, 8]$. Suppose Vitaly has $5$ of options: $[e_1=1, t_1=1, p_1=30]$, $[e_2=2, t_2=3, p_2=50]$, $[e_3=2, t_3=3, p_3=100]$, $[e_4=1, t_4=1, p_4=80]$, $[e_5=3, t_5=3, p_5=100]$. 

Then, if Vitaly prepares in the following way, he will be able to complete everything in time: 

* Vitaly chooses the $4$-th option. Then in $1$ hour, he will complete the $1$-st task at $80$ percent. He still has $4$ hours left before the deadline for the $1$-st task.
* Vitaly chooses the $3$-rd option. Then in $3$ hours, he will complete the $2$-nd task in its entirety. He has another $1$ hour left before the deadline for the $1$-st task and $4$ hours left before the deadline for the $3$-rd task.
* Vitaly chooses the $1$-st option. Then after $1$ hour, he will complete the $1$-st task for $110$ percent, which means that he will complete the $1$-st task just in time for the deadline.
* Vitaly chooses the $5$-th option. He will complete the $3$-rd task for $2$ hours, and after another $1$ hour, Vitaly will complete the $3$-rd task in its entirety.

Thus, Vitaly has managed to complete the course completely and on time, using the $4$ options.

Help Vitaly — print the options for Vitaly to complete the tasks in the correct order. Please note: each option can be used not more than once. If there are several possible answers, it is allowed to output any of them.

## Input

The first line of input data contains an integer $T$ ($1 \le T \le 10^4$) —the number of input test cases in the test.

The descriptions of the input test case follow.

The first line of each test case description contains two integers $n$ and $m$ ($1 \le n,m \le 10^5$) —the number of jobs and the number of training options, respectively.

The next line contains $n$ numbers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the time before the deadline of job $i$. The array values — are non-decreasing, that is $a_1 \le a_2 \le \dots \le a_n$.

The following $m$ lines contain triples of numbers $e_i, t_i, p_i$ ($1 \le e_i \le n$, $1 \le t_i \le 10^9$, $1 \le p_i \le 100$) — if Vitaly chooses this option, then after $t_i$ hours he will increase the progress of the task $e_i$ by $p_i$ percent. The options are numbered from $1$ to $m$ in order in the input data.

It is guaranteed that the sum of $n+m$ on all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print on the first line the number $k$, meaning that for $k$ of options, Vitaly will be able to complete each task by $100$ percent or more on time. The options should not be repeated. Or print -1 if Vitaly is unable to complete all tasks in time.

If there is an answer, on the next line print $k$ of different integers from $1$ to $m$ — the numbers of the options in the order you want. If there is more than one answer, it is allowed to print any of them.

## Examples

## Input


```

53 55 7 81 1 302 3 502 3 1001 1 803 3 1001 5511 36 911 8 401 42 831 3 451 13 402 99 202 8 642 7 641 20 562 8 762 20 481 2 891 3 382 18 661 7 513 27 18 331 5 803 4 372 5569452312 7035659751 928391659 661 915310 822 87017081 921 415310 542 567745964 82
```
## Output


```

4
1 4 3 5 
3
2 4 5 
4
6 7 1 2 
-1
4
2 4 3 5 

```
## Input


```

33 920 31 401 9 643 17 1003 9 593 18 573 20 492 20 822 14 951 8 752 16 672 620 362 2 662 20 931 3 461 10 642 8 492 18 401 110000000001 1000000000 100
```
## Output


```

-1
4
3 4 1 5 
1
1 

```


#### tags 

#2200 #dp #greedy #implementation 