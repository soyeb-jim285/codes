<h1 style='text-align: center;'> D. Visit of the Great</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Great Mushroom King descended to the dwarves, but not everyone managed to see him. Only the few chosen ones could see the King.

We know that only *LCM*(*k*2*l* + 1, *k*2*l* + 1 + 1, ..., *k*2*r* + 1) dwarves can see the Great Mushroom King. Numbers *k*, *l*, *r* are chosen by the Great Mushroom King himself in some complicated manner which is unclear to common dwarves. 

The dwarven historians decided to document all visits of the Great Mushroom King. For each visit the dwarven historians know three integers *k**i*, *l**i*, *r**i*, chosen by the Great Mushroom King for this visit. They also know a prime number *p**i*. Help them to count the remainder of dividing the number of dwarves who can see the King, by number *p**i*, for each visit.

## Input

The first line contains the single integer *t* (1 ≤ *t* ≤ 105) — the number of the King's visits. 

Each of the following *t* input lines contains four space-separated integers *k**i*, *l**i*, *r**i* and *p**i* (1 ≤ *k**i* ≤ 106; 0 ≤ *l**i* ≤ *r**i* ≤ 1018; 2 ≤ *p**i* ≤ 109) — the numbers, chosen by the Great Mushroom King and the prime module, correspondingly. 

It is guaranteed that for all visits number *p**i* is prime.

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Output

For each visit print the answer on a single line — the remainder of dividing the number of the dwarves who can see the King this time, by number *p**i*. Print the answers for the visits in the order, in which the visits are described in the input.

## Examples

## Input


```
2  
3 1 10 2  
5 0 4 3  

```
## Output


```
0  
0  

```
## Note

We consider that *LCM*(*a*1, *a*2, ..., *a**n*) represents the least common multiple of numbers *a*1, *a*2, ..., *a**n*.

We consider that *x*0 = 1, for any *x*.



#### tags 

#2600 #math #number_theory 