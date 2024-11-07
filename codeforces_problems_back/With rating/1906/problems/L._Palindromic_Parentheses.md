<h1 style='text-align: center;'> L. Palindromic Parentheses</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Construct a parentheses sequence consisting of $N$ characters such that it is balanced and the length of its longest palindromic subsequence (LPS) is exactly $K$. Determine whether such a construction is possible. If there are several possible sequences, construct any of them.

A parentheses sequence consists of only character ( and ). A parentheses sequence is balanced if each character ( has a corresponding character ) and the pairs of parentheses are properly nested. For example, (), (()), (())(), and ((())()) are balanced. However, )(, ((), and ()) are not balanced.

A sequence is palindromic if it reads the same backwards as forwards. For example, ((, ), ())(, and (()(( are palindromic. However, (), )(, and (()) are not palindromic.

A subsequence can be derived from another sequence by removing zero or more characters without changing the order of the remaining characters. For example, (, ))), ())(, and (())() are subsequence of (())(). However, )(( and ((())) are not subsequence of (())().

The longest palindromic subsequence (LPS) of a sequence is a subsequence with the maximum number of characters, derived from that sequence and it is palindromic. For example, the LPS of sequence (())() is ())(, which can be obtained by removing the second and sixth characters. Therefore, the length of the LPS of (())() is $4$.

## Input

## Input

 consists of two integers $N$ $K$ ($2 \leq N \leq 2000; 1 \leq K \leq N$). $N$ is an even number.

## Output

If there is no such parentheses sequence such that it is balanced and the length of its LPS is exactly $K$, then output -1.

Otherwise, output a string of $N$ characters, representing the parentheses sequence. If there are several possible answers, output any of them.

## Examples

## Input


```

6 4

```
## Output


```

(())()
```
## Input


```

6 3

```
## Output


```

(()())
```
## Input


```

4 1

```
## Output


```

-1
```
## Input


```

14 11

```
## Output


```

()((())()())()
```
## Note

Explanation for the sample input/output #2

The LPS of (()()) is either ((( by removing all ) characters, or ))) by removing all ( characters.

The output ((())) also satisfies the requirements.

Explanation for the sample input/output #3

The only possible balanced parentheses sequences are (()) and ()(). The length of the LPS of (()) and ()() are $2$ and $3$, respectively.

Explanation for the sample input/output #4

The LPS of ()((())()())() is )())()())(), which can be obtained by removing the first, fourth, and fifth characters.



#### tags 

#2500 #constructive_algorithms 