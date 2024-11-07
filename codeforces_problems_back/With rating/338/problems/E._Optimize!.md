<h1 style='text-align: center;'> E. Optimize!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Manao is solving a problem with the following statement:

 ![](images/6d30f5a31c4b685301d16d49bdd548abc73cdbee.png) He came up with a solution that produces the correct answers but is too slow. You are given the pseudocode of his solution, where the function getAnswer calculates the answer to the problem:


```
  
getAnswer(a[1..n], b[1..len], h)  
  answer = 0  
  for i = 1 to n-len+1  
    answer = answer + f(a[i..i+len-1], b, h, 1)  
  return answer  
  
f(s[1..len], b[1..len], h, index)  
  if index = len+1 then  
    return 1  
  for i = 1 to len  
    if s[index] + b[i] >= h  
      mem = b[i]  
      b[i] = 0  
      res = f(s, b, h, index + 1)  
      b[i] = mem  
      if res > 0  
        return 1  
  return 0  

```
Your task is to help Manao optimize his algorithm.

## Input

The first line contains space-separated integers *n*, *len* and *h* (1 ≤ *len* ≤ *n* ≤ 150000; 1 ≤ *h* ≤ 109). The second line contains *len* space-separated integers *b*1, *b*2, ..., *b**len* (1 ≤ *b**i* ≤ 109). The third line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109).

## Output

Print a single number — the answer to Manao's problem.

## Examples

## Input


```
5 2 10  
5 3  
1 8 5 5 7  

```
## Output


```
2  

```


#### tags 

#2600 #data_structures 