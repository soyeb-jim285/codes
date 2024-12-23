<h1 style='text-align: center;'> B. Special Offer! Super Price 999 Bourles!</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarpus is an amateur businessman. Recently he was surprised to find out that the market for paper scissors is completely free! Without further ado, Polycarpus decided to start producing and selling such scissors.

Polycaprus calculated that the optimal celling price for such scissors would be *p* bourles. However, he read somewhere that customers are attracted by prices that say something like "Special Offer! Super price 999 bourles!". So Polycarpus decided to lower the price a little if it leads to the desired effect.

Polycarpus agrees to lower the price by no more than *d* bourles so that the number of nines at the end of the resulting price is maximum. If there are several ways to do it, he chooses the maximum possible price.

Note, Polycarpus counts only the trailing nines in a price.

## Input

The first line contains two integers *p* and *d* (1 ≤ *p* ≤ 1018; 0 ≤ *d* < *p*) — the initial price of scissors and the maximum possible price reduction.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d specifier.

## Output

Print the required price — the maximum price that ends with the largest number of nines and that is less than *p* by no more than *d*.

The required number shouldn't have leading zeroes.

## Examples

## Input


```
1029 102  

```
## Output


```
999  

```
## Input


```
27191 17  

```
## Output


```
27189  

```


#### tags 

#1400 #implementation 