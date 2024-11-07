<h1 style='text-align: center;'> D. Levko and Sets</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Levko loves all sorts of sets very much.

Levko has two arrays of integers *a*1, *a*2, ... , *a**n* and *b*1, *b*2, ... , *b**m* and a prime number *p*. Today he generates *n* sets. Let's describe the generation process for the *i*-th set:

1. First it has a single number 1.
2. Let's take any element *c* from this set. For all *j* (1 ≤ *j* ≤ *m*) if number (*c*·*a**i**b**j*) *mod* *p* doesn't occur in the set, then add it to the set.
3. Repeat step 2 as long as we can add at least one element to our set.

Levko wonders, how many numbers belong to at least one set. That is, he wants to know what size is the union of *n* generated sets.

## Input

The first line contains three integers *n*, *m* and *p* (1 ≤ *n* ≤ 104, 1 ≤ *m* ≤ 105, 2 ≤ *p* ≤ 109), *p* is prime. 

The second line contains space-separated integers *a*1, *a*2, ... , *a**n* (1 ≤ *a**i* < *p*). The third line contains space-separated integers *b*1, *b*2, ... , *b**m* (1 ≤ *b**i* ≤ 109).

## Output

The single number — the size of the union of the sets.

## Examples

## Input


```
1 1 7  
2  
5  

```
## Output


```
3  

```
## Input


```
1 2 7  
2  
2 4  

```
## Output


```
3  

```
## Input


```
2 1 7  
1 6  
2  

```
## Output


```
1  

```
## Input


```
2 1 7  
1 6  
5  

```
## Output


```
2  

```


#### tags 

#2600 #number_theory 