<h1 style='text-align: center;'> B. Dima and Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dima got into number sequences. Now he's got sequence *a*1, *a*2, ..., *a**n*, consisting of *n* positive integers. Also, Dima has got a function *f*(*x*), which can be defined with the following recurrence:

* *f*(0) = 0;
* *f*(2·*x*) = *f*(*x*);
* *f*(2·*x* + 1) = *f*(*x*) + 1.

Dima wonders, how many pairs of indexes (*i*, *j*) (1 ≤ *i* < *j* ≤ *n*) are there, such that *f*(*a**i*) = *f*(*a**j*). Help him, count the number of such pairs. 

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105). The second line contains *n* positive integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109).

The numbers in the lines are separated by single spaces.

## Output

In a single line print the answer to the problem.

Please, don't use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
3  
1 2 4  

```
## Output


```
3  

```
## Input


```
3  
5 3 1  

```
## Output


```
1  

```
## Note

In the first sample any pair (*i*, *j*) will do, so the answer is 3.

In the second sample only pair (1, 2) will do.



#### tags 

#1400 #implementation #math 