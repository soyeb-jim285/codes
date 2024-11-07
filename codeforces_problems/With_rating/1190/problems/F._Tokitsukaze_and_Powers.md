<h1 style='text-align: center;'> F. Tokitsukaze and Powers</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tokitsukaze is playing a room escape game designed by SkywalkerT. In this game, she needs to find out hidden clues in the room to reveal a way to escape.

After a while, she realizes that the only way to run away is to open the digital door lock since she accidentally went into a secret compartment and found some clues, which can be interpreted as:

* Only when you enter $n$ possible different passwords can you open the door;
* Passwords must be integers ranged from $0$ to $(m - 1)$;
* A password cannot be $x$ ($0 \leq x < m$) if $x$ and $m$ are not coprime (i.e. $x$ and $m$ have some common divisor greater than $1$);
* A password cannot be $x$ ($0 \leq x < m$) if there exist non-negative integers $e$ and $k$ such that $p^e = k m + x$, where $p$ is a secret integer;
* Any integer that doesn't break the above rules can be a password;
* Several integers are hidden in the room, but only one of them can be $p$.

Fortunately, she finds that $n$ and $m$ are recorded in the lock. However, what makes Tokitsukaze frustrated is that she doesn't do well in math. Now that she has found an integer that is suspected to be $p$, she wants you to help her find out $n$ possible passwords, or determine the integer cannot be $p$.

###### Input

The only line contains three integers $n$, $m$ and $p$ ($1 \leq n \leq 5 \times 10^5$, $1 \leq p < m \leq 10^{18}$).

It is guaranteed that $m$ is a positive integer power of a single prime number.

###### Output

If the number of possible different passwords is less than $n$, print a single integer $-1$.

Otherwise, print $n$ distinct integers ranged from $0$ to $(m - 1)$ as passwords. You can print these integers in any order. Besides, if there are multiple solutions, print any.

## Examples

###### Input


```text
1 2 1
```
###### Output


```text
-1
```
###### Input


```text
3 5 1
```
###### Output


```text
2 4 3
```
###### Input


```text
2 5 4
```
###### Output


```text
2 3
```
###### Input


```text
4 9 8
```
###### Output


```text
2 4 7 5
```
## Note

In the first example, there is no possible password.

In each of the last three examples, the given integer $n$ equals to the number of possible different passwords for the given integers $m$ and $p$, so if the order of numbers in the output is ignored, the solution is unique as shown above.



#### Tags 

#3400 #NOT OK #number_theory #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_573_(Div._1).md)
- [Codeforces Round #573 (en)](../blogs/Codeforces_Round_573_(en).md)
- [E (en)](../blogs/E_(en).md)
