<h1 style='text-align: center;'> C. Remove Adjacent</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of lowercase Latin letters. Let the length of $s$ be $|s|$. You may perform several operations on this string.

In one operation, you can choose some index $i$ and remove the $i$-th character of $s$ ($s_i$) if at least one of its adjacent characters is the previous letter in the Latin alphabet for $s_i$. For example, the previous letter for b is a, the previous letter for s is r, the letter a has no previous letters. ## Note

 that after each removal the length of the string decreases by one. So, the index $i$ should satisfy the condition $1 \le i \le |s|$ during each operation.

For the character $s_i$ adjacent characters are $s_{i-1}$ and $s_{i+1}$. The first and the last characters of $s$ both have only one adjacent character (unless $|s| = 1$).

Consider the following example. Let $s=$ bacabcab.

1. During the first move, you can remove the first character $s_1=$ b because $s_2=$ a. Then the string becomes $s=$ acabcab.
2. During the second move, you can remove the fifth character $s_5=$ c because $s_4=$ b. Then the string becomes $s=$ acabab.
3. During the third move, you can remove the sixth character $s_6=$'b' because $s_5=$ a. Then the string becomes $s=$ acaba.
4. During the fourth move, the only character you can remove is $s_4=$ b, because $s_3=$ a (or $s_5=$ a). The string becomes $s=$ acaa and you cannot do anything with it.

Your task is to find the maximum possible number of characters you can remove if you choose the sequence of operations optimally.

## Input

The first line of the input contains one integer $|s|$ ($1 \le |s| \le 100$) — the length of $s$.

The second line of the input contains one string $s$ consisting of $|s|$ lowercase Latin letters.

## Output

Print one integer — the maximum possible number of characters you can remove if you choose the sequence of moves optimally.

## Examples

## Input


```

8
bacabcab

```
## Output


```

4

```
## Input


```

4
bcda

```
## Output


```

3

```
## Input


```

6
abbbbb

```
## Output


```

5

```
## Note

The first example is described in the problem statement. ## Note

 that the sequence of moves provided in the statement is not the only, but it can be shown that the maximum possible answer to this test is $4$.

In the second example, you can remove all but one character of $s$. The only possible answer follows.

1. During the first move, remove the third character $s_3=$ d, $s$ becomes bca.
2. During the second move, remove the second character $s_2=$ c, $s$ becomes ba.
3. And during the third move, remove the first character $s_1=$ b, $s$ becomes a.


#### tags 

#1600 #brute_force #constructive_algorithms #greedy #strings 