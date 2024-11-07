<h1 style='text-align: center;'> E. Novice's Mistake</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One of the first programming problems by K1o0n looked like this: "Noobish_Monk has $n$ $(1 \le n \le 100)$ friends. Each of them gave him $a$ $(1 \le a \le 10000)$ apples for his birthday. Delighted with such a gift, Noobish_Monk returned $b$ $(1 \le b \le \min(10000, a \cdot n))$ apples to his friends. How many apples are left with Noobish_Monk?"

K1o0n wrote a solution, but accidentally considered the value of $n$ as a string, so the value of $n \cdot a - b$ was calculated differently. Specifically: 

* when multiplying the string $n$ by the integer $a$, he will get the string $s=\underbrace{n + n + \dots + n + n}_{a\ \text{times}}$
* when subtracting the integer $b$ from the string $s$, the last $b$ characters will be removed from it. If $b$ is greater than or equal to the length of the string $s$, it will become empty.

Learning about this, ErnKor became interested in how many pairs $(a, b)$ exist for a given $n$, satisfying the constraints of the problem, on which K1o0n's solution gives the correct answer.

"The solution gives the correct answer" means that it outputs a non-empty string, and this string, when converted to an integer, equals the correct answer, i.e., the value of $n \cdot a - b$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 100$)  — the number of test cases.

For each test case, a single line of input contains an integer $n$ ($1 \le n \le 100$).

It is guaranteed that in all test cases, $n$ is distinct.

## Output

For each test case, output the answer in the following format:

In the first line, output the integer $x$ — the number of bad tests for the given $n$.

In the next $x$ lines, output two integers $a_i$ and $b_i$ — such integers that K1o0n's solution on the test "$n$ $a_i$ $b_i$" gives the correct answer.

## Example

## Input


```

32310
```
## Output


```

3
20 18 
219 216 
2218 2214 
1
165 162 
1
1262 2519 

```
## Note

In the first example, $a = 20$, $b = 18$ are suitable, as "$\text{2}$" $\cdot 20 - 18 =$ "$\text{22222222222222222222}$"$- 18 = 22 = 2 \cdot 20 - 18$



#### tags 

#1700 #brute_force #constructive_algorithms #implementation #math #strings 