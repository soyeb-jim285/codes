<h1 style='text-align: center;'> E. Karen and Neighborhood</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

It's been long after the events of the previous problems, and Karen has now moved on from student life and is looking to relocate to a new neighborhood.

 ![](images/d63fcc1a38e9fbbabf52e0af130829508558a396.png) The neighborhood consists of *n* houses in a straight line, labelled 1 to *n* from left to right, all an equal distance apart.

Everyone in this neighborhood loves peace and quiet. Because of this, whenever a new person moves into the neighborhood, he or she always chooses the house whose minimum distance to any occupied house is maximized. If there are multiple houses with the maximum possible minimum distance, he or she chooses the leftmost one.

## Note

 that the first person to arrive always moves into house 1.

Karen is the *k*-th person to enter this neighborhood. If everyone, including herself, follows this rule, which house will she move into?

## Input

The first and only line of input contains two integers, *n* and *k* (1 ≤ *k* ≤ *n* ≤ 1018), describing the number of houses in the neighborhood, and that Karen was the *k*-th person to move in, respectively.

## Output

## Output

 a single integer on a line by itself, the label of the house Karen will move into.

## Examples

## Input


```
6 4  

```
## Output


```
2  

```
## Input


```
39 3  

```
## Output


```
20  

```
## Note

In the first test case, there are 6 houses in the neighborhood, and Karen is the fourth person to move in:

1. The first person moves into house 1.
2. The second person moves into house 6.
3. The third person moves into house 3.
4. The fourth person moves into house 2.

In the second test case, there are 39 houses in the neighborhood, and Karen is the third person to move in:

1. The first person moves into house 1.
2. The second person moves into house 39.
3. The third person moves into house 20.


#### tags 

#2900 #binary_search #constructive_algorithms #implementation 