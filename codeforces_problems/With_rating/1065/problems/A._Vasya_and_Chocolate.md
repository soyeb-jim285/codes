<h1 style='text-align: center;'> A. Vasya and Chocolate</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a special offer in Vasya's favourite supermarket: if the customer buys $a$ chocolate bars, he or she may take $b$ additional bars for free. This special offer can be used any number of times.

Vasya currently has $s$ roubles, and he wants to get as many chocolate bars for free. Each chocolate bar costs $c$ roubles. Help Vasya to calculate the maximum possible number of chocolate bars he can get!

### Input

The first line contains one integer $t$ ($1 \le t \le 100$) — the number of testcases.

Each of the next $t$ lines contains four integers $s, a, b, c~(1 \le s, a, b, c \le 10^9)$ — the number of roubles Vasya has, the number of chocolate bars you have to buy to use the special offer, the number of bars you get for free, and the cost of one bar, respectively.

### Output

Print $t$ lines. $i$-th line should contain the maximum possible number of chocolate bars Vasya can get in $i$-th test.

## Example

### Input


```text
2  
10 3 1 1  
1000000000 1 1000000000 1  

```
### Output


```text
13  
1000000001000000000  

```
## Note

In the first test of the example Vasya can buy $9$ bars, get $3$ for free, buy another bar, and so he will get $13$ bars.

In the second test Vasya buys $1000000000$ bars and gets $1000000000000000000$ for free. So he has $1000000001000000000$ bars.



#### Tags 

#800 #NOT OK #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_52_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
- [https://codeforces.com/blog/entry/62357](../blogs/https:_codeforces.com_blog_entry_62357.md)
