<h1 style='text-align: center;'> B. Fibonacci Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In all schools in Buryatia, in the $1$ class, everyone is told the theory of Fibonacci strings.

"A block is a subsegment of a string where all the letters are the same and are bounded on the left and right by the ends of the string or by letters other than the letters in the block. A string is called a Fibonacci string if, when it is divided into blocks, their lengths in the order they appear in the string form the Fibonacci sequence ($f_0 = f_1 = 1$, $f_i = f_{i-2} + f_{i-1}$), starting from the zeroth member of this sequence. A string is called semi-Fibonacci if it possible to reorder its letters to get a Fibonacci string."

Burenka decided to enter the Buryat State University, but at the entrance exam she was given a difficult task. She was given a string consisting of the letters of the Buryat alphabet (which contains exactly $k$ letters), and was asked if the given string is semi-Fibonacci. The string can be very long, so instead of the string, she was given the number of appearances of each letter ($c_i$ for the $i$-th letter) in that string. Unfortunately, Burenka no longer remembers the theory of Fibonacci strings, so without your help she will not pass the exam.

### Input

The first line contains one integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The following is a description of the input data sets.

The first line of each test case contains one integer $k$ ($1 \leq k \leq 100$) — the number of letters in the alphabet.

The second line of each test case contains $k$ integers $c_1, c_2, \ldots, c_k$ ($1 \leq c_i \leq 10^9$) — the number of occurrences of each letter in the string.

### Output

For each test case print the string "YES" if the corresponding string is semi-Fibonacci, and "NO" if it is not.

You can print "YES" and "NO" in any case (for example, the strings "yEs", "yes", "Yes" will be recognized as a positive answer).

## Example

### Input


```text
61121 121 233 1 327 5626 8 3 4 13 34
```
### Output

```text

YES
YES
NO
YES
NO
YES

```
## Note

In the first test case, a one-character string is semi-Fibonacci, being itself a Fibonacci string.

In the second test case, a string of two different characters is Fibonacci.

In the third test case, the string "abb" (let the first of the alphabet letter be a, the second letter b) is not a semi-Fibonacci string, since no permutation of its letters ("abb", "bab", and "bba") is a Fibonacci string.

In the fourth test case, two permutations of the letters of the string "abaccac" (the first letter is a, the second letter is b, the third letter is c) are Fibonacci strings — "abaaccc" and "cbccaaa".



#### Tags 

#2000 #NOT OK #greedy #implementation #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_814_(Div._1).md)
- [Codeforces Round #814](../blogs/Codeforces_Round_814.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
