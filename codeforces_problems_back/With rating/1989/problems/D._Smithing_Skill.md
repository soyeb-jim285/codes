<h1 style='text-align: center;'> D. Smithing Skill</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are playing a famous computer game (that just works) where you have various skills you can level up. Today, you focused on the "Smithing" skill. Your tactic is obvious: forging weapons from ingots and then melting them back to return the materials partially. For simplicity, every time you create an item, you get $1$ experience point, and every time you melt an item, you also get $1$ experience point.

There are $n$ classes of weapons you can forge and $m$ types of metal ingots.

You can create one weapon of the $i$-th class, spending $a_i$ ingots of metal of the same type. Melting a weapon of the $i$-th class (which you crafted earlier) returns you $b_i$ ingots of the type of metal it was made of.

You have $c_j$ metal ingots of the $j$-th type, and you know that you can craft a weapon of any class from any metal type. Each combination of a weapon class and a metal type can be used any number of times.

What is the maximum total amount of experience you can earn by crafting and melting weapons?

## Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 10^6$) — the number of weapon classes and metal types.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$), where $a_i$ is the number of ingots you need to forge one weapon of the $i$-th class.

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($0 \le b_i < a_i$), where $b_i$ is the number of ingots you return by melting one weapon of the $i$-th class you forged earlier.

The fourth line contains $m$ integers $c_1, c_2, \dots, c_m$ ($1 \le c_j \le 10^9$) — the number of ingots you have of the corresponding metal type.

## Output

Print one integer — the maximum total experience points you can gain by repeatedly forging and melting weapons.

## Examples

## Input


```

5 39 6 7 5 58 4 5 1 210 4 7
```
## Output


```

12

```
## Input


```

3 410 20 200 0 09 10 19 20
```
## Output


```

8

```
## Input


```

1 5311000000000 1000000000 1000000000 1000000000 1000000000
```
## Output


```

4999999990

```
## Note

In the first example, you can do the following: 

1. craft one weapon of the $1$-st class from the $1$-st type of metal, spending $9$ ingots;
2. melt that weapon, returning $8$ ingots of the $1$-st metal type;
3. again, craft and melt one weapon of the $1$-st class from the $1$-st metal type;
4. craft and melt one weapon of the $3$-rd class from the $1$-st metal type;
5. craft and melt one weapon of the $3$-rd class from the $3$-rd metal type;
6. craft and melt one weapon of the $4$-th class from the $1$-st metal type;
7. craft and melt one weapon of the $5$-th class from the $3$-rd metal type;

 In the end you'll have $c = [2, 4, 2]$ ingots left. In total, you've crafted $6$ weapons and melted $6$ weapons, gaining $12$ experience points in total.

#### tags 

#1900 #brute_force #data_structures #dp #greedy #math #sortings #two_pointers 