<h1 style='text-align: center;'> C. Industrial Nim</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

There are *n* stone quarries in Petrograd.

Each quarry owns *m**i* dumpers (1 ≤ *i* ≤ *n*). It is known that the first dumper of the *i*-th quarry has *x**i* stones in it, the second dumper has *x**i* + 1 stones in it, the third has *x**i* + 2, and the *m**i*-th dumper (the last for the *i*-th quarry) has *x**i* + *m**i* - 1 stones in it.

Two oligarchs play a well-known game Nim. Players take turns removing stones from dumpers. On each turn, a player can select any dumper and remove any non-zero amount of stones from it. The player who cannot take a stone loses.

Your task is to find out which oligarch will win, provided that both of them play optimally. The oligarchs asked you not to reveal their names. So, let's call the one who takes the first stone «tolik» and the other one «bolik».

## Input

The first line of the input contains one integer number *n* (1 ≤ *n* ≤ 105) — the amount of quarries. Then there follow *n* lines, each of them contains two space-separated integers *x**i* and *m**i* (1 ≤ *x**i*, *m**i* ≤ 1016) — the amount of stones in the first dumper of the *i*-th quarry and the number of dumpers at the *i*-th quarry.

## Output

## Output

 «tolik» if the oligarch who takes a stone first wins, and «bolik» otherwise.

## Examples

## Input


```
2  
2 1  
3 2  

```
## Output


```
tolik  

```
## Input


```
4  
1 1  
1 1  
1 1  
1 1  

```
## Output


```
bolik  

```


#### tags 

#2000 #games 