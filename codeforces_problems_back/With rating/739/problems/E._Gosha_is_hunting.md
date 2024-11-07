<h1 style='text-align: center;'> E. Gosha is hunting</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gosha is hunting. His goal is to catch as many Pokemons as possible. Gosha has *a* Poke Balls and *b* Ultra Balls. There are *n* Pokemons. They are numbered 1 through *n*. Gosha knows that if he throws a Poke Ball at the *i*-th Pokemon he catches it with probability *p**i*. If he throws an Ultra Ball at the *i*-th Pokemon he catches it with probability *u**i*. He can throw at most one Ball of each type at any Pokemon.

The hunting proceeds as follows: at first, Gosha chooses no more than *a* Pokemons at which he will throw Poke Balls and no more than *b* Pokemons at which he will throw Ultra Balls. After that, he throws the chosen Balls at the chosen Pokemons. If he throws both Ultra Ball and Poke Ball at some Pokemon, he is caught if and only if he is caught by any of these Balls. The outcome of a throw doesn't depend on the other throws.

Gosha would like to know what is the expected number of the Pokemons he catches if he acts in an optimal way. In other words, he would like to know the maximum possible expected number of Pokemons can catch.

## Input

The first line contains three integers *n*, *a* and *b* (2 ≤ *n* ≤ 2000, 0 ≤ *a*, *b* ≤ *n*) — the number of Pokemons, the number of Poke Balls and the number of Ultra Balls.

The second line contains *n* real values *p*1, *p*2, ..., *p**n* (0 ≤ *p**i* ≤ 1), where *p**i* is the probability of catching the *i*-th Pokemon if Gosha throws a Poke Ball to it.

The third line contains *n* real values *u*1, *u*2, ..., *u**n* (0 ≤ *u**i* ≤ 1), where *u**i* is the probability of catching the *i*-th Pokemon if Gosha throws an Ultra Ball to it.

All the probabilities are given with exactly three digits after the decimal separator.

## Output

Print the maximum possible expected number of Pokemons Gosha can catch. The answer is considered correct if it's absolute or relative error doesn't exceed 10- 4.

## Examples

## Input


```
3 2 2  
1.000 0.000 0.500  
0.000 1.000 0.500  

```
## Output


```
2.75  

```
## Input


```
4 1 3  
0.100 0.500 0.500 0.600  
0.100 0.500 0.900 0.400  

```
## Output


```
2.16  

```
## Input


```
3 2 0  
0.412 0.198 0.599  
0.612 0.987 0.443  

```
## Output


```
1.011
```


#### tags 

#3000 #brute_force #data_structures #dp #flows #math #probabilities #sortings 