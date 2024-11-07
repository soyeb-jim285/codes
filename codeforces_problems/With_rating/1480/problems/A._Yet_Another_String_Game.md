<h1 style='text-align: center;'> A. Yet Another String Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Homer has two friends Alice and Bob. Both of them are string fans. 

One day, Alice and Bob decide to play a game on a string $s = s_1 s_2 \dots s_n$ of length $n$ consisting of lowercase English letters. They move in turns alternatively and Alice makes the first move.

In a move, a player must choose an index $i$ ($1 \leq i \leq n$) that has not been chosen before, and change $s_i$ to any other lowercase English letter $c$ that $c \neq s_i$.

When all indices have been chosen, the game ends. 

The goal of Alice is to make the final string lexicographically as small as possible, while the goal of Bob is to make the final string lexicographically as large as possible. Both of them are game experts, so they always play games optimally. Homer is not a game expert, so he wonders what the final string will be.

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
### Input

Each test contains multiple test cases. The first line contains $t$ ($1 \le t \le 1000$)  — the number of test cases. Description of the test cases follows.

The only line of each test case contains a single string $s$ ($1 \leq |s| \leq 50$) consisting of lowercase English letters.

### Output

For each test case, print the final string in a single line.

## Example

### Input


```text
3
a
bbbb
az
```
### Output


```text
b
azaz
by
```
## Note

In the first test case: Alice makes the first move and must change the only letter to a different one, so she changes it to 'b'.

In the second test case: Alice changes the first letter to 'a', then Bob changes the second letter to 'z', Alice changes the third letter to 'a' and then Bob changes the fourth letter to 'z'.

In the third test case: Alice changes the first letter to 'b', and then Bob changes the second letter to 'y'.



#### Tags 

#800 #OK #games #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_700_(Div._2).md)
- [Codeforces Round #700 (en)](../blogs/Codeforces_Round_700_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
