<h1 style='text-align: center;'> A. Number Replacement</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An integer array $a_1, a_2, \ldots, a_n$ is being transformed into an array of lowercase English letters using the following prodecure:

While there is at least one number in the array: 

* Choose any number $x$ from the array $a$, and any letter of the English alphabet $y$.
* Replace all occurrences of number $x$ with the letter $y$.

For example, if we initially had an array $a = [2, 3, 2, 4, 1]$, then we could transform it the following way:

* Choose the number $2$ and the letter c. After that $a = [c, 3, c, 4, 1]$.
* Choose the number $3$ and the letter a. After that $a = [c, a, c, 4, 1]$.
* Choose the number $4$ and the letter t. After that $a = [c, a, c, t, 1]$.
* Choose the number $1$ and the letter a. After that $a = [c, a, c, t, a]$.

After the transformation all letters are united into a string, in our example we get the string "cacta".

Having the array $a$ and the string $s$ determine if the string $s$ could be got from the array $a$ after the described transformation?

### Input

The first line contains a single integer $t$ $(1 \leq t \leq 10^3$) — the number of test cases.

Then the description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 50$) — the length of the array $a$ and the string $s$.

The second line of each test case contains exactly $n$ integers: $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 50$) — the elements of the array $a$.

The third line of each test case contains a string $s$ of length $n$, consisting of lowercase English letters. 

### Output

For each test case, output "YES", if we can get the string $s$ from the array $a$, and "NO" otherwise. You can output each letter in any case.

## Example

### Input


```text
752 3 2 4 1cacta150a211 22ab41 2 2 1aaab51 2 3 2 1aaaaa61 10 2 9 3 8azzfdb71 2 3 4 1 1 2abababb
```
### Output

```text

YES
YES
YES
NO
YES
YES
NO

```
## Note

The first test case corresponds to the sample described in the statement.

In the second test case we can choose the number $50$ and the letter a.

In the third test case we can choose the number $11$ and the letter a, after that $a = [a, 22]$. Then we choose the number $22$ and the letter b and get $a = [a, b]$.

In the fifth test case we can change all numbers one by one to the letter a.



#### Tags 

#800 #OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_828_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
