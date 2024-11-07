<h1 style='text-align: center;'> D. Array Painting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of $n$ integers, where each integer is either $0$, $1$, or $2$. Initially, each element of the array is blue.

Your goal is to paint each element of the array red. In order to do so, you can perform operations of two types:

* pay one coin to choose a blue element and paint it red;
* choose a red element which is not equal to $0$ and a blue element adjacent to it, decrease the chosen red element by $1$, and paint the chosen blue element red.

What is the minimum number of coins you have to spend to achieve your goal?

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 2$).

## Output

Print one integer — the minimum number of coins you have to spend in order to paint all elements red.

## Examples

## Input


```

3
0 2 0

```
## Output


```

1

```
## Input


```

4
0 0 1 1

```
## Output


```

2

```
## Input


```

7
0 1 0 0 1 0 2

```
## Output


```

4

```
## Note

In the first example, you can paint all elements red with having to spend only one coin as follows:

1. paint the $2$-nd element red by spending one coin;
2. decrease the $2$-nd element by $1$ and paint the $1$-st element red;
3. decrease the $2$-nd element by $1$ and paint the $3$-rd element red.

In the second example, you can paint all elements red spending only two coins as follows:

1. paint the $4$-th element red by spending one coin;
2. decrease the $4$-th element by $1$ and paint the $3$-rd element red;
3. paint the $1$-st element red by spending one coin;
4. decrease the $3$-rd element by $1$ and paint the $2$-nd element red.


#### tags 

#1700 #constructive_algorithms #greedy #two_pointers 