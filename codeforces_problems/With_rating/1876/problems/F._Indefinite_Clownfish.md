<h1 style='text-align: center;'> F. Indefinite Clownfish</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Pak Chanek has just bought an empty fish tank and he has been dreaming to fill it with his favourite kind of fish, clownfish. Pak Chanek likes clownfish because of their ability to change their genders on demand. Because of the size of his fish tank, Pak Chanek wants to buy exactly $k$ clownfish to fill the tank.

Pak Chanek goes to the local fish shop. The shop provides $n$ clownfish numbered from $1$ to $n$, with clownfish $i$ having a size of $a_i$. Initially, every clownfish in the store does not have an assigned gender, but has the ability to be assigned to two possible clownfish genders, female or male.

The store has a procedure which Pak Chanek should follow to buy clownfish. The shop owner will point at each clownfish sequentially from $1$ to $n$ and for each clownfish, she asks Pak Chanek whether to buy it or not. Each time Pak Chanek is asked, he must declare whether to buy the currently asked clownfish or not, before the shop owner moves on to the next clownfish. If Pak Chanek declares to buy the currently asked clownfish, he must also declare the gender to be assigned to that clownfish immediately. When assigning the gender for the currently asked clownfish, the following conditions must be satisfied: 

* If Pak Chanek assigns it to be female and he has bought a female clownfish before, then the size of the current one must be exactly $1$ bigger than the last female one.
* If Pak Chanek assigns it to be male and he has bought a male clownfish before, then the size of the current one must be exactly $1$ smaller than the last male one.

Pak Chanek wants to buy exactly $k$ clownfish such that: 

* There is at least one female clownfish and one male clownfish.
* Among the $k$ clownfish Pak Chanek buys, the mean size of the female clownfish is equal to the mean size of the male clownfish.

Let $l$ and $r$ respectively be the minimum and maximum index of a clownfish Pak Chanek buys. What is the minimum possible value of $r-l$?

##### Input

The first line contains two integers $n$ and $k$ ($2 \leq k \leq n \leq 2\cdot10^5$) — the number of clownfish in the shop and the number of clownfish Pak Chanek has to buy.

The second line contains $n$ integers $a_1,a_2,a_3,\ldots,a_n$ ($1\leq a_i\leq n$) — the size of each clownfish.

##### Output

An integer representing the minimum possible value of $r-l$. If it is impossible to buy exactly $k$ clownfish and satisfy the problem's condition, print $-1$.

## Examples

##### Input


```text
9 6
2 4 2 3 2 4 1 3 4
```
##### Output


```text
6
```
##### Input


```text
6 6
2 6 5 2 6 5
```
##### Output


```text
-1
```
##### Input


```text
5 4
1 2 3 4 5
```
##### Output


```text
-1
```
## Note

In the first example, Pak Chanek can do the following: 

1. Do not buy clownfish $1$.
2. Buy clownfish $2$ and assign it as male.
3. Buy clownfish $3$ and assign it as female.
4. Buy clownfish $4$ and assign it as male.
5. Buy clownfish $5$ and assign it as male.
6. Do not buy clownfish $6$.
7. Buy clownfish $7$ and assign it as male.
8. Buy clownfish $8$ and assign it as female.
9. Do not buy clownfish $9$.

Then, we get that: 

* The mean size among the $2$ female clownfish Pak Chanek buys is $\frac{2+3}{2} = 2.5$.
* The mean size among the $4$ male clownfish Pak Chanek buys is $\frac{4+3+2+1}{4} = 2.5$.
* $l=2$, $r=8$, $r-l=6$.

There are no better strategies.



#### Tags 

#3500 #NOT OK #binary_search #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_902_(Div._1,_based_on_COMPFEST_15_-_Final_Round).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
