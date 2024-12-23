<h1 style='text-align: center;'> D. Don't fear, DravDe is kind</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A motorcade of *n* trucks, driving from city «Z» to city «З», has approached a tunnel, known as Tunnel of Horror. Among truck drivers there were rumours about monster DravDe, who hunts for drivers in that tunnel. Some drivers fear to go first, others - to be the last, but let's consider the general case. Each truck is described with four numbers: 

* *v* — value of the truck, of its passangers and cargo
* *c* — amount of passanger on the truck, the driver included
* *l* — total amount of people that should go into the tunnel before this truck, so that the driver can overcome his fear («if the monster appears in front of the motorcade, he'll eat them first»)
* *r* — total amount of people that should follow this truck, so that the driver can overcome his fear («if the monster appears behind the motorcade, he'll eat them first»).

Since the road is narrow, it's impossible to escape DravDe, if he appears from one side. Moreover, the motorcade can't be rearranged. The order of the trucks can't be changed, but it's possible to take any truck out of the motorcade, and leave it near the tunnel for an indefinite period. You, as the head of the motorcade, should remove some of the trucks so, that the rest of the motorcade can move into the tunnel and the total amount of the left trucks' values is maximal. 

## Input

The first input line contains integer number *n* (1 ≤ *n* ≤ 105) — amount of trucks in the motorcade. The following *n* lines contain four integers each. Numbers in the *i*-th line: *v**i*, *c**i*, *l**i*, *r**i* (1 ≤ *v**i* ≤ 104, 1 ≤ *c**i* ≤ 105, 0 ≤ *l**i*, *r**i* ≤ 105) — describe the *i*-th truck. The trucks are numbered from 1, counting from the front of the motorcade.

## Output

In the first line output number *k* — amount of trucks that will drive into the tunnel. In the second line output *k* numbers — indexes of these trucks in ascending order. Don't forget please that you are not allowed to change the order of trucks. If the answer is not unique, output any.

## Examples

## Input


```
5  
1 1 0 3  
1 1 1 2  
1 1 2 1  
1 1 3 0  
2 1 3 0  

```
## Output


```
4  
1 2 3 5   

```
## Input


```
5  
1 1 0 3  
10 1 2 1  
2 2 1 1  
10 1 1 2  
3 1 3 0  

```
## Output


```
3  
1 3 5   

```


#### tags 

#2400 #binary_search #data_structures #dp #hashing 