<h1 style='text-align: center;'> C. Binary String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a string $s$ consisting of characters 0 and/or 1.

You have to remove several (possibly zero) characters from the beginning of the string, and then several (possibly zero) characters from the end of the string. The string may become empty after the removals. The cost of the removal is the maximum of the following two values:

* the number of characters 0 left in the string;
* the number of characters 1 removed from the string.

What is the minimum cost of removal you can achieve?

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of one line containing the string $s$ ($1 \le |s| \le 2 \cdot 10^5$), consisting of characters 0 and/or 1.

The total length of strings $s$ in all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print one integer — the minimum cost of removal you can achieve.

## Example

### Input


```text
510111011010010010010010000111111000001111
```
### Output

```text

1
3
0
0
0

```
## Note

Consider the test cases of the example:

1. in the first test case, it's possible to remove two characters from the beginning and one character from the end. Only one 1 is deleted, only one 0 remains, so the cost is $1$;
2. in the second test case, it's possible to remove three characters from the beginning and six characters from the end. Two characters 0 remain, three characters 1 are deleted, so the cost is $3$;
3. in the third test case, it's optimal to remove four characters from the beginning;
4. in the fourth test case, it's optimal to remove the whole string;
5. in the fifth test case, it's optimal to leave the string as it is.


#### Tags 

#1600 #OK #binary_search #greedy #strings #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_128_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
