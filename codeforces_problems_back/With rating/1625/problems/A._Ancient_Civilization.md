<h1 style='text-align: center;'> A. Ancient Civilization</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Martian scientists explore Ganymede, one of Jupiter's numerous moons. Recently, they have found ruins of an ancient civilization. The scientists brought to Mars some tablets with writings in a language unknown to science.

They found out that the inhabitants of Ganymede used an alphabet consisting of two letters, and each word was exactly $\ell$ letters long. So, the scientists decided to write each word of this language as an integer from $0$ to $2^{\ell} - 1$ inclusively. The first letter of the alphabet corresponds to zero bit in this integer, and the second letter corresponds to one bit.

The same word may have various forms in this language. Then, you need to restore the initial form. The process of doing it is described below.

Denote the distance between two words as the amount of positions, in which these words differ. For example, the distance between $1001_2$ and $1100_2$ (in binary) is equal to two, as these words have different letters in the second and the fourth positions, counting from left to right. Further, denote the distance between words $x$ and $y$ as $d(x, y)$.

Let the word have $n$ forms, the $i$-th of which is described with an integer $x_i$. All the $x_i$ are not necessarily different, as two various forms of the word can be written the same. Consider some word $y$. Then, closeness of the word $y$ is equal to the sum of distances to each of the word forms, i. e. the sum $d(x_i, y)$ over all $1 \le i \le n$.

The initial form is the word $y$ with minimal possible nearness.

You need to help the scientists and write the program which finds the initial form of the word given all its known forms. ## Note

 that the initial form is not necessarily equal to any of the $n$ given forms.

## Input

The first line contains an integer $t$ ($1 \le t \le 100$) — the number of test cases. The following are descriptions of the test cases.

The first line contains two integers $n$ and $\ell$ ($1 \le n \le 100$, $1 \le \ell \le 30$) — the amount of word forms, and the number of letters in one word.

The second line contains $n$ integers $x_i$ ($0 \le x_i \le 2^\ell - 1$) — word forms. The integers are not necessarily different.

## Output

For each test, print a single integer, the initial form of the word, i. e. such $y$ ($0 \le y \le 2^\ell - 1$) that the sum $d(x_i, y)$ over all $1 \le i \le n$ is minimal possible. ## Note

 that $y$ can differ from all the integers $x_i$.

If there are multiple ways to restore the initial form, print any.

## Example

## Input


```

73 518 9 213 518 18 181 115 301 2 3 4 56 1099 35 85 46 78 552 10 18 85 16 42 15 83 65 78 42
```
## Output


```

17
18
1
1
39
0
2

```
## Note

In the first test case, the words can be written as $x_1 = 10010_2$, $x_2 = 01001_2$ and $x_3 = 10101_2$ in binary. Let $y = 10001_2$. Then, $d(x_1, y) = 2$ (the difference is in the fourth and the fifth positions), $d(x_2, y) = 2$ (the difference is in the first and the second positions), $d(x_3, y) = 1$ (the difference is in the third position). So, the closeness is $2 + 2 + 1 = 5$. It can be shown that you cannot achieve smaller closeness.

In the second test case, all the forms are equal to $18$ ($10010_2$ in binary), so the initial form is also $18$. It's easy to see that closeness is equal to zero in this case.



#### tags 

#800 #bitmasks #greedy #math 