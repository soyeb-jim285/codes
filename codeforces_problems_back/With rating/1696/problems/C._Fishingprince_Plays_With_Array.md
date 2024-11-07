<h1 style='text-align: center;'> C. Fishingprince Plays With Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Fishingprince is playing with an array $[a_1,a_2,\dots,a_n]$. He also has a magic number $m$.

He can do the following two operations on it:

* Select $1\le i\le n$ such that $a_i$ is divisible by $m$ (that is, there exists an integer $t$ such that $m \cdot t = a_i$). Replace $a_i$ with $m$ copies of $\frac{a_i}{m}$. The order of the other elements doesn't change. For example, when $m=2$ and $a=[2,3]$ and $i=1$, $a$ changes into $[1,1,3]$.
* Select $1\le i\le n-m+1$ such that $a_i=a_{i+1}=\dots=a_{i+m-1}$. Replace these $m$ elements with a single $m \cdot a_i$. The order of the other elements doesn't change. For example, when $m=2$ and $a=[3,2,2,3]$ and $i=2$, $a$ changes into $[3,4,3]$.

## Note

 that the array length might change during the process. The value of $n$ above is defined as the current length of the array (might differ from the $n$ in the input).

Fishingprince has another array $[b_1,b_2,\dots,b_k]$. Please determine if he can turn $a$ into $b$ using any number (possibly zero) of operations.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1\le n\le 5\cdot 10^4$, $2\le m\le 10^9$).

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\le a_i\le 10^9$).

The third line of each test case contains one integer $k$ ($1\le k\le 5\cdot 10^4$).

The fourth line of each test case contains $k$ integers $b_1,b_2,\ldots,b_k$ ($1\le b_i\le 10^9$).

It is guaranteed that the sum of $n+k$ over all test cases does not exceed $2\cdot 10^5$.

## Output

For each testcase, print Yes if it is possible to turn $a$ into $b$, and No otherwise. You can print each letter in any case (upper or lower).

## Example

## Input


```

55 21 2 2 4 241 4 4 26 21 2 2 8 2 221 168 33 3 3 3 3 3 3 346 6 6 68 33 9 6 3 12 12 36 12169 3 2 2 2 3 4 12 4 12 4 12 4 12 4 48 33 9 6 3 12 12 36 12712 2 4 3 4 12 56
```
## Output


```

Yes
Yes
No
Yes
No

```
## Note

In the first test case of the sample, we can do the second operation with $i=2$: $[1,\color{red}{2,2},4,2]\to [1,\color{red}{4},4,2]$.

In the second testcase of the sample, we can:

* do the second operation with $i=2$: $[1,\color{red}{2,2},8,2,2]\to [1,\color{red}{4},8,2,2]$.
* do the second operation with $i=4$: $[1,4,8,\color{red}{2,2}]\to [1,4,8,\color{red}{4}]$.
* do the first operation with $i=3$: $[1,4,\color{red}{8},4]\to [1,4,\color{red}{4,4},4]$.
* do the second operation with $i=2$: $[1,\color{red}{4,4},4,4]\to [1,\color{red}{8},4,4]$.
* do the second operation with $i=3$: $[1,8,\color{red}{4,4}]\to [1,8,\color{red}{8}]$.
* do the second operation with $i=2$: $[1,\color{red}{8,8}]\to [1,\color{red}{16}]$.


#### tags 

#1400 #constructive_algorithms #greedy #implementation #math 