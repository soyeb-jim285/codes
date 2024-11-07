<h1 style='text-align: center;'> F. Rudolph and Mimic</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive task.

Rudolph is a scientist who studies alien life forms. There is a room in front of Rudolph with $n$ different objects scattered around. Among the objects there is exactly one amazing creature — a mimic that can turn into any object. He has already disguised himself in this room and Rudolph needs to find him by experiment.

The experiment takes place in several stages. At each stage, the following happens:

* Rudolf looks at all the objects in the room and writes down their types. The type of each object is indicated by a number; there can be several objects of the same type.
* After inspecting, Rudolph can point to an object that he thinks is a mimic. After that, the experiment ends. Rudolph only has one try, so if he is unsure of the mimic's position, he does the next step instead.
* Rudolf can remove any number of objects from the room (possibly zero). Then Rudolf leaves the room and at this time all objects, including the mimic, are mixed with each other, their order is changed, and the mimic can transform into any other object (even one that is not in the room).
* After this, Rudolf returns to the room and repeats the stage. The mimic may not change appearance, but it can not remain a same object for more than two stages in a row.

Rudolf's task is to detect mimic in no more than five stages.

## Input

The first line contains one integer $t$ $(1 \le t \le 1000)$ — the number of test cases.

The first line of each test case contains one integer $n$ $(2 \le n \le 200)$ — the number of objects in the room.

The second line of each test case contains $n$ integers $a_1$,$a_2$,...,$a_n$ $(1 \le a_i \le 9)$ — object types.

## Interaction

After you have read the description of the input data set, you must make no more than $5$ queries. Reading the input data is considered the beginning of the first stage, and the mimic may already begin to change.

The request is a line. The first character of the line indicates the request type. To remove objects, print "-". After that print the number $k$ — how many objects you want to remove. Then there are $k$ numbers — indexes of objects in their current location. Indexing starts from one. You can remove the mimic, but in this case you will not be able to point to it and will get "Wrong answer" verdict.

In response to the request you will receive a line containing integers — the objects remaining in the room after removal and mixing.

To indicate the position of a mimic, print "!", then print the index of the object that is the mimic.

The task will be considered solved if the position of the mimic is specified correctly.

If you make more than five requests, or make an invalid request, the solution will get "Wrong answer" verdict.

After outputting a query or the answer do not forget to output the end of line and flush the output. Otherwise, you will get "Idleness limit exceeded". To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

You can hack a solution with the following input format.

The first line contains one integer $t$ $(1 \le t \le 1000)$ — the number of test cases.

The first line of each test case contains two integers $n$, $k$ ($2 \le n \le 200, 1 \le k \le n$) — the number of objects and the position of the mimic.

The second line contains of each test case $n$ integers $a_1$, $a_2$,...,$a_n$ ($1 \le a_i \le 9$) – initial array of objects.

## Example

## Input


```

3
5
1 1 2 2 3

2 1 1 2

2 2 2

2

8
1 2 3 4 3 4 2 1

4 3 4 3 2 2 1 3
 
2 3 3 2

5 3 2

2 5

15
1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 

1 2 3 4 5 6 7 8 7 9 5 4 3 2 1 
```
Output
```

 
 
- 1 5

- 1 3

- 2 1 2

! 1


- 0

- 4 1 3 7 8

- 1 4

- 1 2

! 2


- 0

! 10
```
## Note

Explanation for the first test: initial array is $x_1$, $x_2$, $x_3$, $x_4$, $x_5$. Mimic is in first position. 

* Delete the fifth object. After that, the positions are shuffled, and the mimic chose not to change his appearance. Object positions become $x_4$, $x_1$, $x_2$, $x_3$.
* Delete the third objects. The mimic is forced to turn into another object, because it has already been in the form $1$ for two stages. The mimic chose to transform into $2$, the objects are shuffled and become $x_3$, $x_4$, $x_1$.
* Delete the first and second objects. The objects positions become $x_1$. Only the mimic remains, and it remains an object $2$.
* Point to the first element.


#### tags 

#1800 #constructive_algorithms #implementation #interactive 