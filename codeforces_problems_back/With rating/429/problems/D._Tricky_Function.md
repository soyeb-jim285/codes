<h1 style='text-align: center;'> D. Tricky Function</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Iahub and Sorin are the best competitive programmers in their town. However, they can't both qualify to an important contest. The selection will be made with the help of a single problem. Blatnatalag, a friend of Iahub, managed to get hold of the problem before the contest. Because he wants to make sure Iahub will be the one qualified, he tells Iahub the following task.

You're given an (1-based) array *a* with *n* elements. Let's define function *f*(*i*, *j*) (1 ≤ *i*, *j* ≤ *n*) as (*i* - *j*)2 + *g*(*i*, *j*)2. Function g is calculated by the following pseudo-code:


```
  
int g(int i, int j) {  
    int sum = 0;  
    for (int k = min(i, j) + 1; k <= max(i, j); k = k + 1)  
        sum = sum + a[k];  
    return sum;  
}  

```
Find a value *min**i* ≠ *j*  *f*(*i*, *j*).

Probably by now Iahub already figured out the solution to this problem. Can you?

## Input

The first line of input contains a single integer *n* (2 ≤ *n* ≤ 100000). Next line contains *n* integers *a*[1], *a*[2], ..., *a*[*n*] ( - 104 ≤ *a*[*i*] ≤ 104). 

## Output

## Output

 a single integer — the value of *min**i* ≠ *j*  *f*(*i*, *j*).

## Examples

## Input


```
4  
1 0 0 -1  

```
## Output


```
1  

```
## Input


```
2  
1 -1  

```
## Output


```
2  

```


#### tags 

#2200 #data_structures #divide_and_conquer #geometry 