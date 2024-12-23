<h1 style='text-align: center;'> E. Function</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Serega and Fedor play with functions. One day they came across a very interesting function. It looks like that:

* *f*(1, *j*) = *a*[*j*], 1 ≤ *j* ≤ *n*.
* *f*(*i*, *j*) = *min*(*f*(*i* - 1, *j*), *f*(*i* - 1, *j* - 1)) + *a*[*j*], 2 ≤ *i* ≤ *n*, *i* ≤ *j* ≤ *n*.

Here *a* is an integer array of length *n*.

Serega and Fedya want to know what values this function takes at some points. But they don't want to calculate the values manually. So they ask you to help them.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) — the length of array *a*. The next line contains *n* integers: *a*[1], *a*[2], ..., *a*[*n*] (0 ≤ *a*[*i*] ≤ 104).

The next line contains integer *m* (1 ≤ *m* ≤ 105) — the number of queries. Each of the next *m* lines contains two integers: *x**i*, *y**i* (1 ≤ *x**i* ≤ *y**i* ≤ *n*). Each line means that Fedor and Serega want to know the value of *f*(*x**i*, *y**i*).

## Output

Print *m* lines — the answers to the guys' queries.

## Examples

## Input


```
6  
2 2 3 4 3 4  
4  
4 5  
3 4  
3 4  
2 3  

```
## Output


```
12  
9  
9  
5  

```
## Input


```
7  
1 3 2 3 4 0 2  
4  
4 5  
2 3  
1 4  
4 6  

```
## Output


```
11  
4  
3  
0  

```


#### tags 

#2900 #data_structures 