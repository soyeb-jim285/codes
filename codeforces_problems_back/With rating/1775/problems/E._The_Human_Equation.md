<h1 style='text-align: center;'> E. The Human Equation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya and his friend, the robot Petya++, went to BFDMONCON, where the costume contest is taking place today. 

 ![](images/cdea85548d2da96953bb847ca29d2c80c6098c59.png) While walking through the festival, they came across a scientific stand named after Professor Oak and Golfball, where they were asked to solve an interesting problem.

Given a sequence of numbers $a_1, a_2, \dots, a_n$ you can perform several operations on this sequence.

Each operation should look as follows. You choose some subsequence$^\dagger$. Then you call all the numbers at odd positions in this subsequence northern, and all the numbers at even positions in this subsequence southern. In this case, only the position of the number in the subsequence is taken into account, not in the original sequence.

For example, consider the sequence $1, 4, 2, 8, 5, 7, 3, 6, 9$ and its subsequence (shown in bold) $1, \mathbf{4}, \mathbf{2}, 8, \mathbf{5}, 7, 3, \mathbf{6}, 9$. Then the numbers $4$ and $5$ are northern, and the numbers $2$ and $6$ are southern.

After that, you can do one of the following: 

* add $1$ to all northern numbers and subtract $1$ from all south numbers; or
* add $1$ to all southern numbers and subtract $1$ from all northern numbers.

Thus, from the sequence $1, \mathbf{4}, \mathbf{2}, 8, \mathbf{5}, 7, 3, \mathbf{6}, 9$, if you choose the subsequence shown in bold, you can get either $1, \mathbf{5}, \mathbf{1}, 8, \mathbf{6}, 7, 3, \mathbf{5}, 9$ or $1, \mathbf{3}, \mathbf{3}, 8, \mathbf{4}, 7, 3, \mathbf{7}, 9$.

Then the operation ends. ## Note

 also that all operations are independent, i. e. the numbers are no longer called northern or southern when one operation ends.

It is necessary to turn all the numbers of the sequence into zeros using the operations described above. Since there is very little time left before the costume contest, the friends want to know, what is the minimum number of operations required for this.

The friends were unable to solve this problem, so can you help them?

$^\dagger$ A sequence $c$ is a subsequence of a sequence $d$ if $c$ can be obtained from $d$ by the deletion of several (possibly, zero or all) elements.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 2\cdot 10^5$) — the length of the sequence.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$) — the description of the sequence itself.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

## Output

For each test case, print one integer in a single line — the minimum number of operations it takes to turn all the numbers into zeros.

## Example

## Input


```

531 2 -351 0 0 -1 -162 -4 3 -5 4 151 -1 1 -1 170 0 0 0 0 0 0
```
## Output


```

3
2
6
1
0

```
## Note

In the first test case, the sequence of operations is as follows: $\mathbf{1}, 2, \mathbf{-3} \longrightarrow 0, \mathbf{2}, \mathbf{-2} \longrightarrow 0, \mathbf{1}, \mathbf{-1} \longrightarrow 0, 0, 0$.

In the second test case, the sequence looks like this: $\mathbf{1}, 0, 0, \mathbf{-1}, -1 \longrightarrow 0, 0, 0, 0, \mathbf{-1} \longrightarrow 0, 0, 0, 0, 0$.

In the fourth test case, simply select the entire sequence as a subsequence, then subtract one from the northern numbers and add one to the southern numbers. Thus, the sequence will be nulled in one operation.

In the fifth test case, you don't need to do any operations, since the sequence already consists of zeros.



#### tags 

#2100 #greedy #implementation 