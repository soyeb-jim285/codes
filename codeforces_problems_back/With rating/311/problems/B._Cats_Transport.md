<h1 style='text-align: center;'> B. Cats Transport</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Zxr960115 is owner of a large farm. He feeds *m* cute cats and employs *p* feeders. There's a straight road across the farm and *n* hills along the road, numbered from 1 to *n* from left to right. The distance between hill *i* and (*i* - 1) is *d**i* meters. The feeders live in hill 1.

One day, the cats went out to play. Cat *i* went on a trip to hill *h**i*, finished its trip at time *t**i*, and then waited at hill *h**i* for a feeder. The feeders must take all the cats. Each feeder goes straightly from hill 1 to *n* without waiting at a hill and takes all the waiting cats at each hill away. Feeders walk at a speed of 1 meter per unit time and are strong enough to take as many cats as they want.

For example, suppose we have two hills (*d*2 = 1) and one cat that finished its trip at time 3 at hill 2 (*h*1 = 2). Then if the feeder leaves hill 1 at time 2 or at time 3, he can take this cat, but if he leaves hill 1 at time 1 he can't take it. If the feeder leaves hill 1 at time 2, the cat waits him for 0 time units, if the feeder leaves hill 1 at time 3, the cat waits him for 1 time units.

Your task is to schedule the time leaving from hill 1 for each feeder so that the sum of the waiting time of all cats is minimized.

## Input

The first line of the input contains three integers *n*, *m*, *p* (2 ≤ *n* ≤ 105, 1 ≤ *m* ≤ 105, 1 ≤ *p* ≤ 100).

The second line contains *n* - 1 positive integers *d*2, *d*3, ..., *d**n* (1 ≤ *d**i* < 104).

Each of the next *m* lines contains two integers *h**i* and *t**i* (1 ≤ *h**i* ≤ *n*, 0 ≤ *t**i* ≤ 109).

## Output

## Output

 an integer, the minimum sum of waiting time of all cats.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
4 6 2  
1 3 5  
1 0  
2 1  
4 9  
1 10  
2 10  
3 12  

```
## Output


```
3  

```


#### tags 

#2400 #data_structures #dp 