<h1 style='text-align: center;'> E. Rearrange Brackets</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example:

* bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)");
* bracket sequences ")(", "(" and ")" are not.

You are given a regular bracket sequence. In one move, you can remove a pair of adjacent brackets such that the left one is an opening bracket and the right one is a closing bracket. Then concatenate the resulting parts without changing the order. The cost of this move is the number of brackets to the right of the right bracket of this pair.

The cost of the regular bracket sequence is the smallest total cost of the moves required to make the sequence empty.

Actually, you are not removing any brackets. Instead, you are given a regular bracket sequence and an integer $k$. You can perform the following operation at most $k$ times: 

* extract some bracket from the sequence and insert it back at any position (between any two brackets, at the start or at the end; possibly, at the same place it was before).

After all operations are performed, the bracket sequence has to be regular. What is the smallest possible cost of the resulting regular bracket sequence?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $k$ ($0 \le k \le 5$) — the maximum number of operations you can perform.

The second line contains a non-empty regular bracket sequence, it consists only of characters '(' and ')'.

The total length of the regular bracket sequences over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

For each testcase, print a single integer — the smallest possible cost of the regular bracket sequence after you perform at most $k$ operations on it.

## Example

## Input


```

70()0(())1(())5()1(()()(()))2((())()(()())((())))3((())()(()())((())))
```
## Output


```

0
1
0
0
1
4
2

```


#### tags 

#2100 #brute_force #dp #greedy #sortings #strings 