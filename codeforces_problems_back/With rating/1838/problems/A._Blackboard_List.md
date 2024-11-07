<h1 style='text-align: center;'> A. Blackboard List</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Two integers were written on a blackboard. After that, the following step was carried out $n-2$ times:

* Select any two integers on the board, and write the absolute value of their difference on the board.

After this process was complete, the list of $n$ integers was shuffled. You are given the final list. Recover one of the initial two numbers. You do not need to recover the other one.

You are guaranteed that the input can be generated using the above process.

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3 \le n \le 100$) — the size of the final list.

The next line of each test case contains $n$ integers $a_1, a_2, \ldots a_n$ ($-10^9 \le a_i \le 10^9$) — the shuffled list of numbers written on the blackboard.

It is guaranteed that the input was generated using the process described above.

## Output

For each test case, output a single integer $x$ — one of the two initial numbers on the blackboard.

If there are multiple solutions, print any of them.

## Example

## Input


```

939 2 7315 -4 114-9 1 11 -1053 0 0 0 378 16 8 0 8 16 840 0 0 01027 1 24 28 2 -1 26 25 28 276600000000 800000000 0 -200000000 1000000000 80000000030 -1000000000 1000000000
```
## Output


```

9
11
-9
3
8
0
-1
600000000
0

```
## Note

For the first test case, $a$ can be produced by starting with either $9$ and $2$, and then writing down $|9-2|=7$, or starting with $9$ and $7$ and writing down $|9-7|=2$. So $2$, $7$, and $9$ are all valid answers, because they all appear in at least one valid pair.

For the second test case, we can show that the two initial numbers must have been $-4$ and $11$.

For the fourth test case, the starting numbers could have been either $3$ and $3$, or $3$ and $0$, so $3$ and $0$ are both valid answers.

For the fifth test case, we can show that the starting numbers were $8$ and $16$.



#### tags 

#800 #constructive_algorithms #math 