<h1 style='text-align: center;'> C. Felicity is Coming!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It's that time of the year, Felicity is around the corner and you can see people celebrating all around the Himalayan region. The Himalayan region has *n* gyms. The *i*-th gym has *g**i* Pokemon in it. There are *m* distinct Pokemon types in the Himalayan region numbered from 1 to *m*. There is a special evolution camp set up in the fest which claims to evolve any Pokemon. The type of a Pokemon could change after evolving, subject to the constraint that if two Pokemon have the same type before evolving, they will have the same type after evolving. Also, if two Pokemon have different types before evolving, they will have different types after evolving. It is also possible that a Pokemon has the same type before and after evolving. 

Formally, an evolution plan is a permutation *f* of {1, 2, ..., *m*}, such that *f*(*x*) = *y* means that a Pokemon of type *x* evolves into a Pokemon of type *y*.

The gym leaders are intrigued by the special evolution camp and all of them plan to evolve their Pokemons. The protocol of the mountain states that in each gym, for every type of Pokemon, the number of Pokemon of that type before evolving any Pokemon should be equal the number of Pokemon of that type after evolving all the Pokemons according to the evolution plan. They now want to find out how many distinct evolution plans exist which satisfy the protocol.

Two evolution plans *f*1 and *f*2 are distinct, if they have at least one Pokemon type evolving into a different Pokemon type in the two plans, i. e. there exists an *i* such that *f*1(*i*) ≠ *f*2(*i*).

Your task is to find how many distinct evolution plans are possible such that if all Pokemon in all the gyms are evolved, the number of Pokemon of each type in each of the gyms remains the same. As the answer can be large, output it modulo 109 + 7.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 105, 1 ≤ *m* ≤ 106) — the number of gyms and the number of Pokemon types.

The next *n* lines contain the description of Pokemons in the gyms. The *i*-th of these lines begins with the integer *g**i* (1 ≤ *g**i* ≤ 105) — the number of Pokemon in the *i*-th gym. After that *g**i* integers follow, denoting types of the Pokemons in the *i*-th gym. Each of these integers is between 1 and *m*.

The total number of Pokemons (the sum of all *g**i*) does not exceed 5·105.

## Output

## Output

 the number of valid evolution plans modulo 109 + 7.

## Examples

## Input


```
2 3  
2 1 2  
2 2 3  

```
## Output


```
1  

```
## Input


```
1 3  
3 1 2 3  

```
## Output


```
6  

```
## Input


```
2 4  
2 1 2  
3 2 3 4  

```
## Output


```
2  

```
## Input


```
2 2  
3 2 2 1  
2 1 2  

```
## Output


```
1  

```
## Input


```
3 7  
2 1 2  
2 3 4  
3 5 6 7  

```
## Output


```
24  

```
## Note

In the first case, the only possible evolution plan is: 

![](images/09e0e2f9394b52c6493c7865ece6f322b26434eb.png)In the second case, any permutation of (1,  2,  3) is valid.

In the third case, there are two possible plans: 

![](images/c8db0de324b08c3f78b8db5ce7a45c1f4e206dcd.png) ![](images/5f569c7ffa0111a20a7bedc873c68fdf02d79d08.png)In the fourth case, the only possible evolution plan is: 

![](images/64cf59d705c51be7d92ffd554bfa5d433917bcf8.png)

#### tags 

#1900 #data_structures #hashing #sortings #strings 