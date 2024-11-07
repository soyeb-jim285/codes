<h1 style='text-align: center;'> E. Inna and Binary Logic</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Inna is fed up with jokes about female logic. So she started using binary logic instead.

Inna has an array of *n* elements *a*1[1], *a*1[2], ..., *a*1[*n*]. Girl likes to train in her binary logic, so she does an exercise consisting of *n* stages: on the first stage Inna writes out all numbers from array *a*1, on the *i*-th (*i* ≥ 2) stage girl writes all elements of array *a**i*, which consists of *n* - *i* + 1 integers; the *k*-th integer of array *a**i* is defined as follows: *a**i*[*k*] = *a**i* - 1[*k*] *AND* *a**i* - 1[*k* + 1]. Here AND is bit-wise binary logical operation.

Dima decided to check Inna's skill. He asks Inna to change array, perform the exercise and say the sum of all ![](images/5e54199c623e6698508e30637903d25ae30f0d42.png) elements she wrote out during the current exercise.

Help Inna to answer the questions!

## Input

The first line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — size of array *a*1 and number of Dima's questions. Next line contains *n* integers *a*1[1], *a*1[2], ..., *a*1[*n*] (0 ≤ *a**i* ≤ 105) — initial array elements.

Each of next *m* lines contains two integers — Dima's question description. Each question consists of two integers *p**i*, *v**i* (1 ≤ *p**i* ≤ *n*; 0 ≤ *v**i* ≤ 105). For this question Inna should make *a*1[*p**i*] equals *v**i*, and then perform the exercise. Please, note that changes are saved from question to question.

## Output

For each question print Inna's answer on a single line.

## Examples

## Input


```
3 4  
1 1 1  
1 1  
2 2  
3 2  
1 2  

```
## Output


```
6  
4  
7  
12  

```


#### tags 

#2100 #binary_search #bitmasks #data_structures 