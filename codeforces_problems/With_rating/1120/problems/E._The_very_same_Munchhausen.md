<h1 style='text-align: center;'> E. The very same Munchhausen</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A positive integer $a$ is given. Baron Munchausen claims that he knows such a positive integer $n$ that if one multiplies $n$ by $a$, the sum of its digits decreases $a$ times. In other words, $S(an) = S(n)/a$, where $S(x)$ denotes the sum of digits of the number $x$. 

Find out if what Baron told can be true.

##### Input

The only line contains a single integer $a$ ($2 \le a \le 10^3$).

##### Output

If there is no such number $n$, print $-1$.

Otherwise print any appropriate positive integer $n$. Your number must not consist of more than $5\cdot10^5$ digits. We can show that under given constraints either there is no answer, or there is an answer no longer than $5\cdot10^5$ digits.

## Examples

##### Input


```text
2
```
##### Output


```text
6
```
##### Input


```text
3
```
##### Output


```text
6669
```
##### Input


```text
10
```
##### Output


```text
-1
```


#### Tags 

#2600 #NOT OK #brute_force 

## Blogs
- [All Contest Problems](../Codeforces_Round_543_(Div._1,_based_on_Technocup_2019_Final_Round).md)
- [A (en)](../blogs/A_(en).md)
- [Announcement #2 (ru)](../blogs/Announcement_2_(ru).md)
- [T (en)](../blogs/T_(en).md)
- [Tutorial #2 (ru)](../blogs/Tutorial_2_(ru).md)
