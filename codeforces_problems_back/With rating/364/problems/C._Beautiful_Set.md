<h1 style='text-align: center;'> C. Beautiful Set</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We'll call a set of positive integers *a* beautiful if the following condition fulfills: for any prime *p*, if ![](images/60a03c36680044f0bf831aad4ee38c0e4e5fea90.png), then ![](images/6c79564a80ed73bfd97a34135be5692a1cd5936e.png). In other words, if one number from the set is divisible by prime *p*, then at least half of numbers from the set is divisible by *p*.

Your task is to find any beautiful set, where the number of elements is equal to *k* and each element doesn't exceed 2*k*2.

## Input

The first line contains integer *k* (10 ≤ *k* ≤ 5000) that shows how many numbers the required beautiful set should have.

## Output

In the first line print *k* space-separated integers that are a beautiful set. If there are multiple such sets, you are allowed to print any of them.

## Examples

## Input


```
10  

```
## Output


```
16 18 24 27 36 48 54 72 108 144   

```


#### tags 

#2300 #brute_force #number_theory 