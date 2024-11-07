<h1 style='text-align: center;'> D. Invertible Bracket Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters '1' and '+' between the original characters of the sequence. For example:

* bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)");
* bracket sequences ")(", "(" and ")" are not.

Let's define the inverse of the bracket sequence as follows: replace all brackets '(' with ')', and vice versa (all brackets ')' with '('). For example, strings "()((" and ")())" are inverses of each other.

You are given a regular bracket sequence $s$. Calculate the number of pairs of integers $(l,r)$ ($1 \le l \le r \le |s|$) such that if you replace the substring of $s$ from the $l$-th character to the $r$-th character (inclusive) with its inverse, $s$ will still be a regular bracket sequence.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The only line of each test case contains a non-empty regular bracket sequence; it consists only of characters '(' and/or ')'.

Additional constraint on the input: the total length of the regular bracket sequences over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, print a single integer — the number of pairs $(l,r)$ meeting the conditions from the statement.

## Example

## Input


```

4(())()()()()(()())(())
```
## Output


```

1
0
3
13

```
## Note

In the first example, there is only one pair: 

* $(2, 3)$: (()) $\rightarrow$ ()().

In the second example, there are no pairs.

In the third example, there are three pairs: 

* $(2, 3)$: ()()() $\rightarrow$ (())();
* $(4, 5)$: ()()() $\rightarrow$ ()(());
* $(2, 5)$: ()()() $\rightarrow$ (()());


#### tags 

#2000 #binary_search #combinatorics #data_structures #divide_and_conquer #implementation #two_pointers 