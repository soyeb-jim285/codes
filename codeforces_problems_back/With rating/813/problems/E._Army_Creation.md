<h1 style='text-align: center;'> E. Army Creation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As you might remember from our previous rounds, Vova really likes computer games. Now he is playing a strategy game known as Rage of Empires.

In the game Vova can hire *n* different warriors; *i*th warrior has the type *a**i*. Vova wants to create a balanced army hiring some subset of warriors. An army is called balanced if for each type of warrior present in the game there are not more than *k* warriors of this type in the army. Of course, Vova wants his army to be as large as possible.

To make things more complicated, Vova has to consider *q* different plans of creating his army. *i*th plan allows him to hire only warriors whose numbers are not less than *l**i* and not greater than *r**i*.

Help Vova to determine the largest size of a balanced army for each plan.

Be aware that the plans are given in a modified way. See input section for details.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n*, *k* ≤ 100000).

The second line contains *n* integers *a*1, *a*2, ... *a**n* (1 ≤ *a**i* ≤ 100000).

The third line contains one integer *q* (1 ≤ *q* ≤ 100000).

Then *q* lines follow. *i*th line contains two numbers *x**i* and *y**i* which represent *i*th plan (1 ≤ *x**i*, *y**i* ≤ *n*).

You have to keep track of the answer to the last plan (let's call it *last*). In the beginning *last* = 0. Then to restore values of *l**i* and *r**i* for the *i*th plan, you have to do the following:

1. *l**i* = ((*x**i* + *last*) *mod* *n*) + 1;
2. *r**i* = ((*y**i* + *last*) *mod* *n*) + 1;
3. If *l**i* > *r**i*, swap *l**i* and *r**i*.
## Output

Print *q* numbers. *i*th number must be equal to the maximum size of a balanced army when considering *i*th plan.

## Example

## Input


```
6 2  
1 1 1 2 2 2  
5  
1 6  
4 3  
1 1  
2 6  
2 6  

```
## Output


```
2  
4  
1  
3  
2  

```
## Note

In the first example the real plans are: 

1. 1 2
2. 1 6
3. 6 6
4. 2 4
5. 4 6


#### tags 

#2200 #binary_search #data_structures 