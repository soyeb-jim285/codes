<h1 style='text-align: center;'> B. Sequence Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tema and Vika are playing the following game.

First, Vika comes up with a sequence of positive integers $a$ of length $m$ and writes it down on a piece of paper. Then she takes a new piece of paper and writes down the sequence $b$ according to the following rule: 

* First, she writes down $a_1$.
* Then, she writes down only those $a_i$ ($2 \le i \le m$) such that $a_{i - 1} \le a_i$. Let the length of this sequence be denoted as $n$.

For example, from the sequence $a=[4, 3, 2, 6, 3, 3]$, Vika will obtain the sequence $b=[4, 6, 3]$.

She then gives the piece of paper with the sequence $b$ to Tema. He, in turn, tries to guess the sequence $a$.

Tema considers winning in such a game highly unlikely, but still wants to find at least one sequence $a$ that could have been originally chosen by Vika. Help him and output any such sequence.

## Note

 that the length of the sequence you output should not exceed the input sequence length by more than two times.

### Input

Each test consists of multiple test cases. The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. This is followed by a description of the test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the sequence $b$.

The second line of each test case contains $n$ integers $b_1, b_2, b_3, \dots, b_n$ ($1 \le b_i \le 10^9$) — the elements of the sequence.

The sum of the values of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output two lines. In the first line, output a single integer $m$ — the length of the sequence ($n \le m \le 2 \cdot n$). In the second line, output $m$ integers $a_1, a_2, a_3, \dots, a_m$ ($1 \le a_i \le 10^9$) — the assumed sequence that Vika could have written on the first piece of paper.

If there are multiple suitable sequences, you can output any of them.

## Example

### Input


```text
634 6 331 2 351 7 9 5 7114421 151 2 2 1 1
```
### Output

```text

6
4 3 2 6 3 3
3
1 2 3
6
1 7 9 3 5 7
1
144
2
1 1
6
1 2 2 1 1 1
```
## Note

The first sample is explained in the problem statement.

In the second sample, Vika could have chosen the original sequence.



#### Tags 

#800 #OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_894_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
