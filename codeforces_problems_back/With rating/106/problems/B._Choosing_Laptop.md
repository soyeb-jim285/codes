<h1 style='text-align: center;'> B. Choosing Laptop</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya is choosing a laptop. The shop has *n* laptops to all tastes.

Vasya is interested in the following properties: processor speed, ram and hdd. Vasya is a programmer and not a gamer which is why he is not interested in all other properties.

If all three properties of a laptop are strictly less than those properties of some other laptop, then the first laptop is considered outdated by Vasya. Among all laptops Vasya does not consider outdated, he chooses the cheapest one.

There are very many laptops, which is why Vasya decided to write a program that chooses the suitable laptop. However, Vasya doesn't have his own laptop yet and he asks you to help him.

## Input

The first line contains number *n* (1 ≤ *n* ≤ 100).

Then follow *n* lines. Each describes a laptop as *speed* *ram* *hdd* *cost*. Besides, 

* *speed*, *ram*, *hdd* and *cost* are integers
* 1000 ≤ *speed* ≤ 4200 is the processor's speed in megahertz
* 256 ≤ *ram* ≤ 4096 the RAM volume in megabytes
* 1 ≤ *hdd* ≤ 500 is the HDD in gigabytes
* 100 ≤ *cost* ≤ 1000 is price in tugriks

All laptops have different prices.

## Output

Print a single number — the number of a laptop Vasya will choose. The laptops are numbered with positive integers from 1 to *n* in the order in which they are given in the input data.

## Examples

## Input


```
5  
2100 512 150 200  
2000 2048 240 350  
2300 1024 200 320  
2500 2048 80 300  
2000 512 180 150  

```
## Output


```
4
```
## Note

In the third sample Vasya considers the first and fifth laptops outdated as all of their properties cannot match those of the third laptop. The fourth one is the cheapest among the laptops that are left. Thus, Vasya chooses the fourth laptop.



#### tags 

#1000 #brute_force #implementation 