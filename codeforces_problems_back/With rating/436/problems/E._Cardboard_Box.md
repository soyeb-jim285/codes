<h1 style='text-align: center;'> E. Cardboard Box</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Everyone who has played Cut the Rope knows full well how the gameplay is organized. All levels in the game are divided into boxes. Initially only one box with some levels is available. Player should complete levels to earn stars, collecting stars opens new box with levels.

 ![](images/a6822b5e42fd15226d1f0ebd14f8d55d6817d745.png) Imagine that you are playing Cut the Rope for the first time. Currently you have only the levels of the first box (by the way, it is called "Cardboard Box"). Each level is characterized by two integers: *a**i* — how long it takes to complete the level for one star, *b**i* — how long it takes to complete the level for two stars (*a**i* < *b**i*).

You want to open the next box as quickly as possible. So, you need to earn at least *w* stars. How do make it happen? ## Note

 that the level can be passed only once: either for one star or for two. You do not necessarily need to pass all the levels.

## Input

The first line contains two integers *n* and *w* (1 ≤ *n* ≤ 3·105; 1 ≤ *w* ≤ 2*n*) — the number of levels in the first box and the number of stars you need to open another box. Each of the following *n* lines contains two integers *a**i* and *b**i* (1 ≤ *a**i* < *b**i* ≤ 109) — the attributes of the *i*-th level.

## Output

In the first line print integer *t* — the minimum time you need to open the next box. 

In the next line, print *n* digits without spaces — the description of the optimal scenario: 

* if you need to pass the *i*-th level for one star, the *i*-th digit should equal 1;
* if you need to pass the *i*-th level for two stars, the *i*-th digit should equal 2;
* if you do not need to pass the *i*-th level at all, the *i*-th digit should equal 0.
## Examples

## Input


```
2 3  
1 2  
1 2  

```
## Output


```
3  
12  

```
## Input


```
5 3  
10 20  
5 10  
10 20  
6 9  
25 30  

```
## Output


```
14  
01020  

```
## Note

In the first test sample, answer 21 is also assumed correct.



#### tags 

#2600 #data_structures #greedy 