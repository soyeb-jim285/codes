<h1 style='text-align: center;'> A. Don't Try to Count</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a string $x$ of length $n$ and a string $s$ of length $m$ ($n \cdot m \le 25$), consisting of lowercase Latin letters, you can apply any number of operations to the string $x$.

In one operation, you append the current value of $x$ to the end of the string $x$. ## Note

 that the value of $x$ will change after this.

For example, if $x =$"aba", then after applying operations, $x$ will change as follows: "aba" $\rightarrow$ "abaaba" $\rightarrow$ "abaabaabaaba".

After what minimum number of operations $s$ will appear in $x$ as a substring? A substring of a string is defined as a contiguous segment of it.

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two numbers $n$ and $m$ ($1 \le n \cdot m \le 25$) — the lengths of strings $x$ and $s$, respectively.

The second line of each test case contains the string $x$ of length $n$.

The third line of each test case contains the string $s$ of length $m$.

## Output

For each test case, output a single number — the minimum number of operations after which $s$ will appear in $x$ as a substring. If this is not possible, output $-1$.

## Example

## Input


```

121 5aaaaaa5 5eforcforce2 5abababa3 5abaababa4 3babbbbb5 1aaaaaa4 2aabbba2 8bkkbkbkbkb12 2fjdgmujlconttf2 2aaaa3 5abbbabba1 19mmmmmmmmmmmmmmmmmmmm
```
## Output


```

3
1
2
-1
1
0
1
3
1
0
2
5

```
## Note

In the first test case of the example, after $2$ operations, the string will become "aaaa", and after $3$ operations, it will become "aaaaaaaa", so the answer is $3$.

In the second test case of the example, after applying $1$ operation, the string will become "$\text{e}\color{red}{\text{force}}\text{forc}$", where the substring is highlighted in red.

In the fourth test case of the example, it can be shown that it is impossible to obtain the desired string as a substring.



#### tags 

#800 #brute_force #strings 