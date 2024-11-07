<h1 style='text-align: center;'> B. Drinks</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Vasya loves orange juice very much. That's why any food and drink in his kitchen necessarily contains orange juice. There are *n* drinks in his fridge, the volume fraction of orange juice in the *i*-th drink equals *p**i* percent.

One day Vasya decided to make himself an orange cocktail. He took equal proportions of each of the *n* drinks and mixed them. Then he wondered, how much orange juice the cocktail has.

Find the volume fraction of orange juice in the final drink.

## Input

The first input line contains a single integer *n* (1 ≤ *n* ≤ 100) — the number of orange-containing drinks in Vasya's fridge. The second line contains *n* integers *p**i* (0 ≤ *p**i* ≤ 100) — the volume fraction of orange juice in the *i*-th drink, in percent. The numbers are separated by a space.

## Output

Print the volume fraction in percent of orange juice in Vasya's cocktail. The answer will be considered correct if the absolute or relative error does not exceed 10 - 4.

## Examples

## Input


```
3  
50 50 100  

```
## Output


```
66.666666666667  

```
## Input


```
4  
0 25 50 75  

```
## Output


```
37.500000000000  

```
## Note

## Note

 to the first sample: let's assume that Vasya takes *x* milliliters of each drink from the fridge. Then the volume of pure juice in the cocktail will equal ![](images/c1fac6e64d3a8ee6a5ac138cbe51e60039b22473.png) milliliters. The total cocktail's volume equals 3·*x* milliliters, so the volume fraction of the juice in the cocktail equals ![](images/ceb0664e55a1f9f5fa1243ec74680a4665a4d58d.png), that is, 66.(6) percent.



#### tags 

#800 #implementation #math 