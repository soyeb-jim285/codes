<h1 style='text-align: center;'> C. Electric Charges</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Programmer Sasha is a student at MIPT (Moscow Institute of Physics and Technology) and he needs to make a laboratory work to pass his finals.

A laboratory unit is a plane with standard coordinate axes marked on it. Physicists from Moscow Institute of Physics and Technology charged the axes by large electric charges: axis *X* is positive and axis *Y* is negative.

Experienced laboratory worker marked *n* points with integer coordinates (*x**i*, *y**i*) on the plane and stopped the time. Sasha should use "atomic tweezers" to place elementary particles in these points. He has an unlimited number of electrons (negatively charged elementary particles) and protons (positively charged elementary particles). He can put either an electron or a proton at each marked point. As soon as all marked points are filled with particles, laboratory worker will turn on the time again and the particles will come in motion and after some time they will stabilize in equilibrium. The objective of the laboratory work is to arrange the particles in such a way, that the diameter of the resulting state (the maximum distance between the pairs of points of the set) is as small as possible.

Since Sasha is a programmer, he naively thinks that all the particles will simply "fall" into their projections on the corresponding axes: electrons will fall on axis *X*, while protons will fall on axis *Y*. As we are programmers too, we will consider the same model as Sasha. That is, a particle gets from point (*x*, *y*) to point (*x*, 0) if it is an electron and to point (0, *y*) if it is a proton.

As the laboratory has high background radiation and Sasha takes care of his laptop, he did not take it with him, and now he can't write a program that computes the minimum possible diameter of the resulting set. Therefore, you will have to do it for him.

Print a square of the minimum possible diameter of the set.

## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 100 000) — the number of points marked on the plane.

Each of the next *n* lines contains two integers *x**i* and *y**i* ( - 108 ≤ *x**i*, *y**i* ≤ 108) — the coordinates of the *i*-th point. It is guaranteed that no two points coincide.

## Output

Print a single integer — the square of the minimum possible diameter of the set.

## Examples

## Input


```
3  
1 10  
1 20  
1 30  

```
## Output


```
0  

```
## Input


```
2  
1 10  
10 1  

```
## Output


```
2  

```
## Note

In the first sample Sasha puts electrons at all points, all particles eventually fall at a single point (1, 0).

In the second sample Sasha puts an electron at point (1, 10), and a proton at point (10, 1). The result is a set of two points (1, 0) and (0, 1), which has a diameter of ![](images/bfe16f27ebc966df6f10ba356a1547b6e7242dd7.png).



#### tags 

#2900 #binary_search #dp 