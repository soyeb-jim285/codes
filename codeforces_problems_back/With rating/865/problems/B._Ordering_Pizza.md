<h1 style='text-align: center;'> B. Ordering Pizza</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It's another Start[c]up finals, and that means there is pizza to order for the onsite contestants. There are only 2 types of pizza (obviously not, but let's just pretend for the sake of the problem), and all pizzas contain exactly *S* slices.

It is known that the *i*-th contestant will eat *s**i* slices of pizza, and gain *a**i* happiness for each slice of type 1 pizza they eat, and *b**i* happiness for each slice of type 2 pizza they eat. We can order any number of type 1 and type 2 pizzas, but we want to buy the minimum possible number of pizzas for all of the contestants to be able to eat their required number of slices. Given that restriction, what is the maximum possible total happiness that can be achieved?

## Input

The first line of input will contain integers *N* and *S* (1 ≤ *N* ≤ 105, 1 ≤ *S* ≤ 105), the number of contestants and the number of slices per pizza, respectively. *N* lines follow.

The *i*-th such line contains integers *s**i*, *a**i*, and *b**i* (1 ≤ *s**i* ≤ 105, 1 ≤ *a**i* ≤ 105, 1 ≤ *b**i* ≤ 105), the number of slices the *i*-th contestant will eat, the happiness they will gain from each type 1 slice they eat, and the happiness they will gain from each type 2 slice they eat, respectively.

## Output

Print the maximum total happiness that can be achieved.

## Examples

## Input


```
3 12  
3 5 7  
4 6 7  
5 9 5  

```
## Output


```
84  

```
## Input


```
6 10  
7 4 7  
5 8 8  
12 5 8  
6 11 6  
3 3 7  
5 9 6  

```
## Output


```
314  

```
## Note

In the first example, you only need to buy one pizza. If you buy a type 1 pizza, the total happiness will be 3·5 + 4·6 + 5·9 = 84, and if you buy a type 2 pizza, the total happiness will be 3·7 + 4·7 + 5·5 = 74.



#### tags 

#1900 #binary_search #sortings #ternary_search 