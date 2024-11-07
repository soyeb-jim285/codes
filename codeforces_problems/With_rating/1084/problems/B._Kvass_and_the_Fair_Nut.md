<h1 style='text-align: center;'> B. Kvass and the Fair Nut</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Fair Nut likes kvass very much. On his birthday parents presented him $n$ kegs of kvass. There are $v_i$ liters of kvass in the $i$-th keg. Each keg has a lever. You can pour your glass by exactly $1$ liter pulling this lever. The Fair Nut likes this drink very much, so he wants to pour his glass by $s$ liters of kvass. But he wants to do it, so kvass level in the least keg is as much as possible.

Help him find out how much kvass can be in the least keg or define it's not possible to pour his glass by $s$ liters of kvass.

##### Input

The first line contains two integers $n$ and $s$ ($1 \le n \le 10^3$, $1 \le s \le 10^{12}$) — the number of kegs and glass volume.

The second line contains $n$ integers $v_1, v_2, \ldots, v_n$ ($1 \le v_i \le 10^9$) — the volume of $i$-th keg.

##### Output

If the Fair Nut cannot pour his glass by $s$ liters of kvass, print $-1$. Otherwise, print a single integer — how much kvass in the least keg can be.

## Examples

##### Input


```text
3 3  
4 3 5  

```
##### Output


```text
3  

```
##### Input


```text
3 4  
5 3 4  

```
##### Output


```text
2  

```
##### Input


```text
3 7  
1 2 3  

```
##### Output


```text
-1  

```
## Note

In the first example, the answer is $3$, the Fair Nut can take $1$ liter from the first keg and $2$ liters from the third keg. There are $3$ liters of kvass in each keg.

In the second example, the answer is $2$, the Fair Nut can take $3$ liters from the first keg and $1$ liter from the second keg.

In the third example, the Fair Nut can't pour his cup by $7$ liters, so the answer is $-1$.



#### Tags 

#1200 #NOT OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_526_(Div._2).md)
- [Codeforces Round #526](../blogs/Codeforces_Round_526.md)
- [63753 (en)](../blogs/63753_(en).md)
- [63753 (ru)](../blogs/63753_(ru).md)
