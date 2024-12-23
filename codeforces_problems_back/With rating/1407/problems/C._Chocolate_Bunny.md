<h1 style='text-align: center;'> C. Chocolate Bunny</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

We hid from you a permutation $p$ of length $n$, consisting of the elements from $1$ to $n$. You want to guess it. To do that, you can give us 2 different indices $i$ and $j$, and we will reply with $p_{i} \bmod p_{j}$ (remainder of division $p_{i}$ by $p_{j}$).

We have enough patience to answer at most $2 \cdot n$ queries, so you should fit in this constraint. Can you do it?

As a reminder, a permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

## Input

The only line of the input contains a single integer $n$ ($1 \le n \le 10^4$) — length of the permutation.

## Interaction

The interaction starts with reading $n$. 

Then you are allowed to make at most $2 \cdot n$ queries in the following way: 

* "? x y" ($1 \le x, y \le n, x \ne y$).

After each one, you should read an integer $k$, that equals $p_x \bmod p_y$. 

When you have guessed the permutation, print a single line "! " (without quotes), followed by array $p$ and quit.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Exit immediately after receiving "-1" and you will see Wrong answer verdict. Otherwise you can get an arbitrary verdict because your solution will continue to read from a closed stream.

Hack format

In the first line output $n$ ($1 \le n \le 10^4$). In the second line print the permutation of $n$ integers $p_1, p_2, \ldots, p_n$.

## Example

## Input


```

3

1

2

1

0
```
Output
```

? 1 2

? 3 2

? 1 3

? 2 1

! 1 3 2
```


#### tags 

#1600 #constructive_algorithms #interactive #math #two_pointers 