<h1 style='text-align: center;'> E. Berland collider</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently the construction of Berland collider has been completed. Collider can be represented as a long narrow tunnel that contains *n* particles. We associate with collider 1-dimensional coordinate system, going from left to right. For each particle we know its coordinate and velocity at the moment of start of the collider. The velocities of the particles don't change after the launch of the collider. Berland scientists think that the big bang will happen at the first collision of particles, whose velocities differs in directions. Help them to determine how much time elapses after the launch of the collider before the big bang happens.

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 5·105) — amount of particles in the collider. Next *n* lines contain description of particles. Each particle is described by two integers *x**i*, *v**i* ( - 109 ≤ *x**i*, *v**i* ≤ 109, *v**i* ≠ 0) — coordinate and velocity respectively. All the coordinates are distinct. The particles are listed in order of increasing of coordinates. All the coordinates are in meters, and all the velocities — in meters per second. The negative velocity means that after the start of collider the particle will move to the left, and the positive — that the particle will move to the right.

## Output

If there will be no big bang, output -1. Otherwise output one number — how much time in seconds elapses after the launch of the collider before the big bang happens. Your answer must have a relative or absolute error less than 10- 9.

## Examples

## Input


```
3  
-5 9  
0 1  
5 -1  

```
## Output


```
1.00000000000000000000  

```
## Input


```
6  
1 3  
2 3  
3 3  
4 -3  
5 -1  
6 -100  

```
## Output


```
0.02912621359223301065  

```


#### tags 

#2300 #binary_search 