<h1 style='text-align: center;'> F. Shady Lady</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ani and Borna are playing a short game on a two-variable polynomial. It's a special kind of a polynomial: the monomials are fixed, but all of its coefficients are fill-in-the-blanks dashes, e.g. $$ \\_ xy + \\_ x^4 y^7 + \\_ x^8 y^3 + \ldots $$

Borna will fill in the blanks with positive integers. He wants the polynomial to be bounded from below, i.e. his goal is to make sure there exists a real number $M$ such that the value of the polynomial at any point is greater than $M$. 

 Ani is mischievous, and wants the polynomial to be unbounded. Along with stealing Borna's heart, she can also steal parts of polynomials. Ani is only a petty kind of thief, though: she can only steal at most one monomial from the polynomial before Borna fills in the blanks. 

If Ani and Borna play their only moves optimally, who wins?

#### Input

The first line contains a positive integer $N$ $(2 \leq N \leq 200\, 000)$, denoting the number of the terms in the starting special polynomial.

Each of the following $N$ lines contains a description of a monomial: the $k$-th line contains two **space**-separated integers $a_k$ and $b_k$ $(0 \leq a_k, b_k \leq 10^9$) which mean the starting polynomial has the term $\\_ x^{a_k} y^{b_k}$. It is guaranteed that for $k \neq l$, either $a_k \neq a_l$ or $b_k \neq b_l$.

#### Output

If Borna can always choose the coefficients such that the resulting polynomial is bounded from below, regardless of what monomial Ani steals, output "Borna". Else, output "Ani". 

You shouldn't output the quotation marks.

## Examples

#### Input


```text
3  
1 1  
2 0  
0 2  

```
#### Output


```text
Ani  

```
#### Input


```text
4  
0 0  
0 1  
0 2  
0 8  

```
#### Output


```text
Borna  

```
## Note

In the first sample, the initial polynomial is $\\_xy+ \\_x^2 + \\_y^2$. If Ani steals the $\\_y^2$ term, Borna is left with $\\_xy+\\_x^2$. Whatever positive integers are written on the blanks, $y \rightarrow -\infty$ and $x := 1$ makes the whole expression go to negative infinity.

In the second sample, the initial polynomial is $\\_1 + \\_x + \\_x^2 + \\_x^8$. One can check that no matter what term Ani steals, Borna can always win.



#### Tags 

#3400 #NOT OK #geometry #math 

## Blogs
- [All Contest Problems](../Bubble_Cup_11_-_Finals_[Online_Mirror,_Div._1].md)
- [Announcement (en)](../blogs/Announcement_(en).md)
