<h1 style='text-align: center;'> A. Wrong Subtraction</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little girl Tanya is learning how to decrease a number by one, but she does it wrong with a number consisting of two or more digits. Tanya subtracts one from a number by the following algorithm:

* if the last digit of the number is non-zero, she decreases the number by one;
* if the last digit of the number is zero, she divides the number by 10 (i.e. removes the last digit).

You are given an integer number $n$. Tanya will subtract one from it $k$ times. Your task is to print the result after all $k$ subtractions.

It is guaranteed that the result will be positive integer number.

#### Input

The first line of the input contains two integer numbers $n$ and $k$ ($2 \le n \le 10^9$, $1 \le k \le 50$) — the number from which Tanya will subtract and the number of subtractions correspondingly.

#### Output

Print one integer number — the result of the decreasing $n$ by one $k$ times.

It is guaranteed that the result will be positive integer number. 

## Examples

#### Input


```text
512 4  

```
#### Output


```text
50  

```
#### Input


```text
1000000000 9  

```
#### Output


```text
1  

```
## Note

The first example corresponds to the following sequence: $512 \rightarrow 511 \rightarrow 510 \rightarrow 51 \rightarrow 50$.



#### Tags 

#800 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_479_(Div._3).md)
- [Tutorial](../blogs/Tutorial.md)
