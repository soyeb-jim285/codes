<h1 style='text-align: center;'> E. Vlad and a Pair of Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vlad found two positive numbers $a$ and $b$ ($a,b>0$). He discovered that $a \oplus b = \frac{a + b}{2}$, where $\oplus$ means the [bitwise exclusive OR](http://tiny.cc/xor_wiki_eng) , and division is performed without rounding..

Since it is easier to remember one number than two, Vlad remembered only $a\oplus b$, let's denote this number as $x$. Help him find any suitable $a$ and $b$ or tell him that they do not exist.

### Input

The first line of the input data contains the single integer $t$ ($1 \le t \le 10^4$) — the number of test cases in the test. 

Each test case is described by a single integer $x$ ($1 \le x \le 2^{29}$) — the number that Vlad remembered.

### Output

### Output

 $t$ lines, each of which is the answer to the corresponding test case. As the answer, output $a$ and $b$ ($0 < a,b \le 2^{32}$), such that $x = a \oplus b = \frac{a + b}{2}$. If there are several answers, output any of them. If there are no matching pairs, output -1.

## Example

### Input


```text
6251061836
```
### Output

```text

3 1
-1
13 7
-1
25 11
50 22
```


#### Tags 

#1400 #OK #bitmasks #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_847_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
