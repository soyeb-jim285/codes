<h1 style='text-align: center;'> B. Choosing Symbol Pairs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a given string *S* consisting of *N* symbols. Your task is to find the number of ordered pairs of integers *i* and *j* such that

1. 1 ≤ *i*, *j* ≤ *N*

2. *S*[*i*] = *S*[*j*], that is the *i*-th symbol of string *S* is equal to the *j*-th.

## Input

The single input line contains *S*, consisting of lowercase Latin letters and digits. It is guaranteed that string *S* in not empty and its length does not exceed 105.

## Output

Print a single number which represents the number of pairs *i* and *j* with the needed property. Pairs (*x*, *y*) and (*y*, *x*) should be considered different, i.e. the ordered pairs count.

## Examples

## Input


```
great10  

```
## Output


```
7  

```
## Input


```
aaaaaaaaaa  

```
## Output


```
100  

```


#### tags 

#1500 #strings 