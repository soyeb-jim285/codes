<h1 style='text-align: center;'> D. Interstellar battle</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the intergalactic empire Bubbledom there are $N$ planets, of which some pairs are directly connected by two-way wormholes. There are $N-1$ wormholes. The wormholes are of extreme religious importance in Bubbledom, a set of planets in Bubbledom consider themselves one intergalactic kingdom if and only if any two planets in the set can reach each other by traversing the wormholes. You are given that Bubbledom is one kingdom. In other words, the network of planets and wormholes is a tree.

However, Bubbledom is facing a powerful enemy also possessing teleportation technology. The enemy attacks every night, and the government of Bubbledom retakes all the planets during the day. In a single attack, the enemy attacks every planet of Bubbledom at once, but some planets are more resilient than others. Planets are number $0,1,…,N-1$ and the planet $i$ will fall with probability $p_i$. Before every night (including the very first one), the government reinforces or weakens the defenses of a single planet.

The government of Bubbledom is interested in the following question: what is the expected number of intergalactic kingdoms Bubbledom will be split into, after a single enemy attack (before they get a chance to rebuild)? In other words, you need to print the expected number of connected components after every attack.

### Input

The first line contains one integer number $N$ ($1 \le N \le 10^5$) denoting the number of planets in Bubbledom (numbered from $0$ to $N-1$). 

The next line contains $N$ different real numbers in the interval $[0,1]$, specified with 2 digits after the decimal point, denoting the probabilities that the corresponding planet will fall.

The next $N-1$ lines contain all the wormholes in Bubbledom, where a wormhole is specified by the two planets it connects.

The next line contains a positive integer $Q$ ($1 \le Q \le 10^5$), denoting the number of enemy attacks.

The next $Q$ lines each contain a non-negative integer and a real number from interval $[0,1]$, denoting the planet the government of Bubbledom decided to reinforce or weaken, along with the new probability that the planet will fall.

### Output

### Output

 contains $Q$ numbers, each of which represents the expected number of kingdoms that are left after each enemy attack. Your answers will be considered correct if their absolute or relative error does not exceed $10^{-4}$. 

## Example

### Input


```text
5  
0.50 0.29 0.49 0.95 0.83  
2 3  
0 3  
3 4  
2 1  
3  
4 0.66  
1 0.69  
0 0.36  

```
### Output


```text
1.68040  
1.48440  
1.61740  

```


#### Tags 

#2200 #NOT OK #math #probabilities #trees 

## Blogs
- [All Contest Problems](../Bubble_Cup_11_-_Finals_[Online_Mirror,_Div._1].md)
- [Announcement (en)](../blogs/Announcement_(en).md)
