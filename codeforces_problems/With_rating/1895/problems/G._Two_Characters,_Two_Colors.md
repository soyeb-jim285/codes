<h1 style='text-align: center;'> G. Two Characters, Two Colors</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a string consisting of characters 0 and/or 1. You have to paint every character of this string into one of two colors, red or blue.

If you paint the $i$-th character red, you get $r_i$ coins. If you paint it blue, you get $b_i$ coins.

After coloring the string, you remove every blue character from it, and count the number of inversions in the resulting string (i. e. the number of pairs of characters such that the left character in the pair is 1, and the right character in the pair is 0). For each inversion, you have to pay $1$ coin.

What is the maximum number of coins you can earn?

### Input

The first line of the input contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of four lines:

* the first line contains one integer $n$ ($1 \le n \le 4 \cdot 10^5$) — the length of the string;
* the second line contains $s$ — a string of $n$ characters, where each character is either 0 or 1;
* the third line contains $n$ integers $r_1, r_2, \dots, r_n$ ($1 \le r_i \le 10^{12}$);
* the fourth line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 10^{12}$).

Additional constraint on the input: the sum of values of $n$ over all test cases does not exceed $4 \cdot 10^5$.

### Output

For each test case, print one integer — the maximum number of coins you can earn.

## Example

### Input


```text
4701000106 6 6 7 7 6 63 3 5 4 7 6 75101119 8 5 7 54 4 7 8 41001000000007 7 6 5 2 2 5 3 8 38 6 9 6 6 8 9 7 7 98010100008 7 7 7 8 7 7 84 4 4 2 1 4 4 4
```
### Output

```text

43
36
76
52

```
## Note

Explanations for the test cases for the example (blue characters are underlined, red ones are not):

1. $0100\underline{0}1\underline{0}$;
2. $10\underline{11}1$;
3. $\underline{0}1\underline{00000000}$;
4. $0\underline{1}010000$.


#### Tags 

#3100 #NOT OK #binary_search #data_structures #dp #flows #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_157_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
