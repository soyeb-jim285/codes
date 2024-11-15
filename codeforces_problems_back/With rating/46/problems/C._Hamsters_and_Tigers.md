<h1 style='text-align: center;'> C. Hamsters and Tigers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Today there is going to be an unusual performance at the circus — hamsters and tigers will perform together! All of them stand in circle along the arena edge and now the trainer faces a difficult task: he wants to swap the animals' positions so that all the hamsters stood together and all the tigers also stood together. The trainer swaps the animals in pairs not to create a mess. He orders two animals to step out of the circle and swap places. As hamsters feel highly uncomfortable when tigers are nearby as well as tigers get nervous when there's so much potential prey around (consisting not only of hamsters but also of yummier spectators), the trainer wants to spend as little time as possible moving the animals, i.e. he wants to achieve it with the minimal number of swaps. Your task is to help him.

## Input

The first line contains number *n* (2 ≤ *n* ≤ 1000) which indicates the total number of animals in the arena. The second line contains the description of the animals' positions. The line consists of *n* symbols "H" and "T". The "H"s correspond to hamsters and the "T"s correspond to tigers. It is guaranteed that at least one hamster and one tiger are present on the arena. The animals are given in the order in which they are located circle-wise, in addition, the last animal stands near the first one.

## Output

Print the single number which is the minimal number of swaps that let the trainer to achieve his goal.

## Examples

## Input


```
3  
HTH  

```
## Output


```
0  

```
## Input


```
9  
HTHTHTHHT  

```
## Output


```
2  

```
## Note

In the first example we shouldn't move anybody because the animals of each species already stand apart from the other species. In the second example you may swap, for example, the tiger in position 2 with the hamster in position 5 and then — the tiger in position 9 with the hamster in position 7.



#### tags 

#1600 #two_pointers 