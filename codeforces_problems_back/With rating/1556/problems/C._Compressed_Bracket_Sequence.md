<h1 style='text-align: center;'> C. Compressed Bracket Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/4dacc2b6c600f0d295a93deebd87f431174eec7c.png) William has a favorite bracket sequence. Since his favorite sequence is quite big he provided it to you as a sequence of positive integers $c_1, c_2, \dots, c_n$ where $c_i$ is the number of consecutive brackets "(" if $i$ is an odd number or the number of consecutive brackets ")" if $i$ is an even number.

For example for a bracket sequence "((())()))" a corresponding sequence of numbers is $[3, 2, 1, 3]$.

You need to find the total number of continuous subsequences (subsegments) $[l, r]$ ($l \le r$) of the original bracket sequence, which are regular bracket sequences.

A bracket sequence is called regular if it is possible to obtain correct arithmetic expression by inserting characters "+" and "1" into this sequence. For example, sequences "(())()", "()" and "(()(()))" are regular, while ")(", "(()" and "(()))(" are not.

## Input

The first line contains a single integer $n$ $(1 \le n \le 1000)$, the size of the compressed sequence.

The second line contains a sequence of integers $c_1, c_2, \dots, c_n$ $(1 \le c_i \le 10^9)$, the compressed sequence.

## Output

## Output

 a single integer — the total number of subsegments of the original bracket sequence, which are regular bracket sequences.

It can be proved that the answer fits in the signed 64-bit integer data type.

## Examples

## Input


```

5
4 1 2 3 1

```
## Output


```

5

```
## Input


```

6
1 3 2 1 2 4

```
## Output


```

6

```
## Input


```

6
1 1 1 1 2 2

```
## Output


```

7

```
## Note

In the first example a sequence (((()(()))( is described. This bracket sequence contains $5$ subsegments which form regular bracket sequences:

1. Subsequence from the $3$rd to $10$th character: (()(()))
2. Subsequence from the $4$th to $5$th character: ()
3. Subsequence from the $4$th to $9$th character: ()(())
4. Subsequence from the $6$th to $9$th character: (())
5. Subsequence from the $7$th to $8$th character: ()

In the second example a sequence ()))(()(()))) is described.

In the third example a sequence ()()(()) is described.



#### tags 

#1800 #brute_force #implementation 