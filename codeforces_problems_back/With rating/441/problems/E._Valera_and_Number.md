<h1 style='text-align: center;'> E. Valera and Number</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valera is a coder. Recently he wrote a funny program. The pseudo code for this program is given below:


```
  
//input: integers x, k, p  
a = x;  
for(step = 1; step <= k; step = step + 1){  
    rnd = [random integer from 1 to 100];  
    if(rnd <= p)  
        a = a * 2;  
    else  
        a = a + 1;  
}  
  
s = 0;  
  
while(remainder after dividing a by 2 equals 0){  
    a = a / 2;  
    s = s + 1;  
}  
  

```
Now Valera wonders: given the values *x*, *k* and *p*, what is the expected value of the resulting number *s*?

## Input

The first line of the input contains three integers *x*, *k*, *p* (1 ≤ *x* ≤ 109; 1 ≤ *k* ≤ 200; 0 ≤ *p* ≤ 100).

## Output

Print the required expected value. Your answer will be considered correct if the absolute or relative error doesn't exceed 10- 6.

## Examples

## Input


```
1 1 50  

```
## Output


```
1.0000000000000  

```
## Input


```
5 3 0  

```
## Output


```
3.0000000000000  

```
## Input


```
5 3 25  

```
## Output


```
1.9218750000000  

```
## Note

If the concept of expected value is new to you, you can read about it by the link: 

http://en.wikipedia.org/wiki/Expected_value



#### tags 

#2400 #bitmasks #dp #math #probabilities 