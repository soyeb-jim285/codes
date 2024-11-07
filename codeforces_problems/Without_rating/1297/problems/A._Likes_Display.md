<h1 style='text-align: center;'> A. Likes Display</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp is working on the implementation of displaying likes on the Codehorses social network. The number of likes should be displayed in a format that will be easy to read by users. It was decided that for large numbers of likes the format should be like 123K (one hundred twenty-three thousand) or like 56M (fifty-six million).

The following displaying strategy has been approved:

* the number will be displayed either as an integer number from 0 to 999, or as a positive integer number of thousands (from 1K to 999K), or as a positive integer number of millions (from 1M on),
* the specified exact number of likes $n$ when displaying should be rounded to the nearest view from the case above (if rounding is ambiguous, it must be rounded up): for example, $1785$ should be rounded to 2K instead of 1K, $4500000$ should be rounded to 5M.

Help Polycarp implement this part of the functionality: for a given non-negative integer number of likes $n$, print its view in the Codehorses interface.

### Input

The first line contains an integer $t$ ($1 \le t \le 1000$) — the number of test cases in the input. The following are descriptions of the $t$ input test cases, one per line.

The description of each test case consists of a single line that contains a non-negative integer $n$ ($0 \le n \le 2\cdot10^9$) — the number of likes.

### Output

Print $t$ answers to the given test cases in the order from the input. Each printed value must have one of the following types:

* either an integer from 0 to 999 which corresponds just to the number of likes,
* or a number of thousands from 1K to 999K,
* or a number of millions from 1M to 2000M.

The answer is equal to a view which is the closest (by difference) to the given number $n$. If this rounding is ambiguous, then round answer up (to a greater value).

## Example

### Input


```text
9
999
123
0
1782
31415926
1500
999999
35499710
2000000000
```
### Output


```text
999
123
0
2K
31M
2K
1M
35M
2000M
```
## Note

Let's describe some test cases: 

* $1782$ can be displayed either as 1K or as 2K but 2K is the nearest view;
* $1500$ have same difference with 1K and 2K so it should be rounded up;
* $999999$ should be displayed as 1M since it's closer to it than to 999K.


#### Tags 

#NOT OK #*special #implementation 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_3.md)
- [Kotlin Heroes: Episode 3 (en)](../blogs/Kotlin_Heroes:_Episode_3_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
