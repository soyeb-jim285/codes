<h1 style='text-align: center;'> E. Palindromic Doubles</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A subsequence is a sequence that can be obtained from another sequence by removing some elements without changing the order of the remaining elements.

A palindromic sequence is a sequence that is equal to the reverse of itself.

You are given a sequence of $n$ integers $a_1, a_2, \dots, a_n$. Any integer value appears in $a$ no more than twice.

What is the length of the longest palindromic subsequence of sequence $a$?

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of testcases.

Then the descriptions of $t$ testcases follow.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 250\,000$) — the number of elements in the sequence.

The second line of each testcase contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$).

Any integer value appears in $a$ no more than twice. The sum of $n$ over all testcases doesn't exceed $250\,000$.

### Output

For each testcase print a single integer — the length of the longest palindromic subsequence of sequence $a$.

## Example

### Input


```text
5
6
2 1 3 1 5 2
6
1 3 3 4 4 1
1
1
2
1 1
7
4 4 2 5 7 2 3
```
### Output


```text
5
4
1
2
3
```
## Note

Here are the longest palindromic subsequences for the example testcases: 

* 2 1 3 1 5 2
* 1 3 3 4 4 1 or 1 3 3 4 4 1
* 1
* 1 1
* 4 4 2 5 7 2 3 or 4 4 2 5 7 2 3


#### Tags 

#2200 #NOT OK #*special #data_structures #dp 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_6.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
