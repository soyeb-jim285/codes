<h1 style='text-align: center;'> K. Kingdom Partition</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The King is gone. After the King's rule, all the roads in the Kingdom are run down and need repair. Three of the King's children, Adrian, Beatrice and Cecilia, are dividing the Kingdom between themselves.

Adrian and Beatrice do not like each other and do not plan to maintain any relations between themselves in the future. Cecilia is on good terms with both of them. Moreover, most of the Kingdom's workers support Cecilia, so she has better resources and more opportunity to repair the infrastructure and develop the economy. 

Cecilia proposes to partition the Kingdom into three districts: A (for Adrian), B (for Beatrice), and C (for Cecilia), and let Adrian and Beatrice to negotiate and choose any towns they want to be in their districts, and agree on how they want to partition the Kingdom into three districts.

Adrian's castle is located in town $a$, and Beatrice's one is located in town $b$. So Adrian and Beatrice want their castles to be located in districts A and B, respectively. Cecilia doesn't have a castle, so district C can consist of no towns.

There is an issue for Adrian and Beatrice. When they choose the towns, they will have to pay for the roads' repair.

The cost to repair the road of length $l$ is $2l$ gold. However, Adrian and Beatrice don't have to bear all the repair costs. The repair cost for the road of length $l$ that they bear depends on what towns it connects:

* For a road between two towns inside district A, Adrian has to pay $2l$ gold;
* For a road between two towns inside district B, Beatrice has to pay $2l$ gold;
* For a road between towns from district A and district C, Adrian has to pay $l$ gold, Cecilia bears the remaining cost;
* For a road between towns from district B and district C, Beatrice has to pay $l$ gold, Cecilia bears the remaining cost.

The roads that connect towns from district A and district B won't be repaired, since Adrian and Beatrice are not planning to use them, so no one pays for them. Cecilia herself will repair the roads that connect the towns inside district C, so Adrian and Beatrice won't bear the cost of their repair either.

Adrian and Beatrice want to minimize the total cost they spend on roads' repair. Find the cheapest way for them to partition the Kingdom into three districts.

## Input

The first line contains two integers $n$ and $m$ — the number of towns and the number of roads in the Kingdom ($2 \le n \le 1000$; $0 \le m \le 2000$).

The second line contains two integers that represent town $a$ and town $b$ — the towns that have to be located in district A and district B, respectively ($1 \le a, b \le n$; $a \ne b$).

The following $m$ lines describe the Kingdom roads. The $i$-th of them consists of three integers $u_i$, $v_i$, and $l_i$ representing a road of length $l_i$ between towns $u_i$ and $v_i$ ($1 \le u_i, v_i \le n$; $u_i \ne v_i$; $1 \le l_i \le 10^9$).

Each pair of towns is connected with at most one road.

## Output

In the first line output a single integer — the minimum total cost of roads' repair for Adrian and Beatrice.

In the second line output a string consisting of $n$ characters 'A', 'B', and 'C', $i$-th of the characters representing the district that the $i$-th town should belong to.

If several cheapest ways to partition the Kingdom exist, print any of them.

## Example

## Input


```

6 7
1 3
1 2 10
2 3 5
1 3 7
4 5 3
3 6 100
4 6 3
5 6 8

```
## Output


```

16
ABBCBA

```
## Note

The following picture illustrates the example. Adrian and Beatrice don't pay for the dashed roads, they pay $2l$ for the bold roads, and $l$ for the solid roads.

So the total cost is $2 \cdot 5 + 3 + 3 = 16$.

The castles of Adrian and Beatrice are located in bold towns.

 ![](images/b382111a38753d6c3a3c2f3ab9d0dbdb3225cbda.png) 

#### tags 

#3200 #flows 