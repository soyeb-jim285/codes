<h1 style='text-align: center;'> D. Remove Two Letters</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dmitry has a string $s$, consisting of lowercase Latin letters.

Dmitry decided to remove two consecutive characters from the string $s$ and you are wondering how many different strings can be obtained after such an operation.

For example, Dmitry has a string "aaabcc". You can get the following different strings: "abcc"(by deleting the first two or second and third characters), "aacc"(by deleting the third and fourth characters),"aaac"(by deleting the fourth and the fifth character) and "aaab" (by deleting the last two).

## Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — number of test cases. 

The descriptions of the test cases follow.

The first line of the description of each test case contains an integer $n$ ($3 \le n \le 2 \cdot 10^5$).

The second line of the description of each test case contains a string $s$ of length $n$ consisting of lowercase Latin letters.

It is guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case print one integer — the number of distinct strings that can be obtained by removing two consecutive letters.

## Example

## Input


```

76aaabcc10aaaaaaaaaa6abcdef7abacaba6cccfff4abba5ababa
```
## Output


```

4
1
5
3
3
3
1

```
## Note

The first example is explained in the statement.

In the third example, the following strings are obtained: "cdef", "adef", "abef", "abcf", "abcd".

In the seventh example, any deletion will result in the string "aba".



#### tags 

#1200 #data_structures #greedy #hashing #strings 