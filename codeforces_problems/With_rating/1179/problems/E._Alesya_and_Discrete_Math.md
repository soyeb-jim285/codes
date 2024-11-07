<h1 style='text-align: center;'> E. Alesya and Discrete Math</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We call a function good if its domain of definition is some set of integers and if in case it's defined in $x$ and $x-1$, $f(x) = f(x-1) + 1$ or $f(x) = f(x-1)$.

Tanya has found $n$ good functions $f_{1}, \ldots, f_{n}$, which are defined on all integers from $0$ to $10^{18}$ and $f_i(0) = 0$ and $f_i(10^{18}) = L$ for all $i$ from $1$ to $n$. It's an notorious coincidence that $n$ is a divisor of $L$. 

She suggests Alesya a game. Using one question Alesya can ask Tanya a value of any single function in any single point. To win Alesya must choose integers $l_{i}$ and $r_{i}$ ($0 \leq l_{i} \leq r_{i} \leq 10^{18}$), such that $f_{i}(r_{i}) - f_{i}(l_{i}) \geq \frac{L}{n}$ (here $f_i(x)$ means the value of $i$-th function at point $x$) for all $i$ such that $1 \leq i \leq n$ so that for any pair of two functions their segments $[l_i, r_i]$ don't intersect (but may have one common point).

Unfortunately, Tanya doesn't allow to make more than $2 \cdot 10^{5}$ questions. Help Alesya to win!

It can be proved that it's always possible to choose $[l_i, r_i]$ which satisfy the conditions described above.

It's guaranteed, that Tanya doesn't change functions during the game, i.e. interactor is not adaptive

### Input

The first line contains two integers $n$ and $L$ ($1 \leq n \leq 1000$, $1 \leq L \leq 10^{18}$, $n$ is a divisor of $L$)  — number of functions and their value in $10^{18}$.

### Output

When you've found needed $l_i, r_i$, print $"!"$ without quotes on a separate line and then $n$ lines, $i$-th from them should contain two integers $l_i$, $r_i$ divided by space.

## Interaction

To ask $f_i(x)$, print symbol "?" without quotes and then two integers $i$ and $x$ ($1 \leq i \leq n$, $0 \leq x \leq 10^{18}$). 
## Note

, you must flush your output to get a response.

After that, you should read an integer which is a value of $i$-th function in point $x$.

You're allowed not more than $2 \cdot 10^5$ questions.

To flush you can use (just after printing an integer and end-of-line):

* fflush(stdout) in C++;
* System.out.flush() in Java;
* stdout.flush() in Python;
* flush(output) in Pascal;
* See the documentation for other languages.

Hacks:

Only tests where $1 \leq L \leq 2000$ are allowed for hacks, for a hack set a test using following format:

The first line should contain two integers $n$ and $L$ ($1 \leq n \leq 1000$, $1 \leq L \leq 2000$, $n$ is a divisor of $L$)  — number of functions and their value in $10^{18}$.

Each of $n$ following lines should contain $L$ numbers $l_1$, $l_2$, ... , $l_L$ ($0 \leq l_j < 10^{18}$ for all $1 \leq j \leq L$ and $l_j < l_{j+1}$ for all $1 < j \leq L$), in $i$-th of them $l_j$ means that $f_i(l_j) < f_i(l_j + 1)$.

## Example

### Input


```text
5 5
? 1 0
? 1 1
? 2 1
? 2 2
? 3 2
? 3 3
? 4 3
? 4 4
? 5 4
? 5 5
!
0 1
1 2
2 3
3 4
4 5
```
### Output


```text
0
1
1
2
2
3
3
4
4
4
5
```
## Note

In the example Tanya has $5$ same functions where $f(0) = 0$, $f(1) = 1$, $f(2) = 2$, $f(3) = 3$, $f(4) = 4$ and all remaining points have value $5$.

Alesya must choose two integers for all functions so that difference of values of a function in its points is not less than $\frac{L}{n}$ (what is $1$ here) and length of intersection of segments is zero.

One possible way is to choose pairs $[0$, $1]$, $[1$, $2]$, $[2$, $3]$, $[3$, $4]$ and $[4$, $5]$ for functions $1$, $2$, $3$, $4$ and $5$ respectively.



#### Tags 

#3200 #NOT OK #divide_and_conquer #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_569_(Div._1).md)
- [Codeforces Round #569](../blogs/Codeforces_Round_569.md)
- [Editorial of Round #569](../blogs/Editorial_of_Round_569.md)
