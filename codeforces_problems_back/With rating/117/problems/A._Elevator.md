<h1 style='text-align: center;'> A. Elevator</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

And now the numerous qualifying tournaments for one of the most prestigious Russian contests Russian Codec Cup are over. All *n* participants who have made it to the finals found themselves in a huge *m*-floored 108-star hotel. Of course the first thought to come in a place like this is "How about checking out the elevator?".

The hotel's elevator moves between floors according to one never changing scheme. Initially (at the moment of time 0) the elevator is located on the 1-st floor, then it moves to the 2-nd floor, then — to the 3-rd floor and so on until it reaches the *m*-th floor. After that the elevator moves to floor *m* - 1, then to floor *m* - 2, and so on until it reaches the first floor. This process is repeated infinitely. We know that the elevator has infinite capacity; we also know that on every floor people get on the elevator immediately. Moving between the floors takes a unit of time.

For each of the *n* participant you are given *s**i*, which represents the floor where the *i*-th participant starts, *f**i*, which represents the floor the *i*-th participant wants to reach, and *t**i*, which represents the time when the *i*-th participant starts on the floor *s**i*.

For each participant print the minimum time of his/her arrival to the floor *f**i*. 

If the elevator stops on the floor *s**i* at the time *t**i*, then the *i*-th participant can enter the elevator immediately. If the participant starts on the floor *s**i* and that's the floor he wanted to reach initially (*s**i* = *f**i*), then the time of arrival to the floor *f**i* for this participant is considered equal to *t**i*.

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n* ≤ 105, 2 ≤ *m* ≤ 108). 

Next *n* lines contain information about the participants in the form of three space-separated integers *s**i* *f**i* *t**i* (1 ≤ *s**i*, *f**i* ≤ *m*, 0 ≤ *t**i* ≤ 108), described in the problem statement.

## Output

Print *n* lines each containing one integer — the time of the arrival for each participant to the required floor.

## Examples

## Input


```
7 4  
2 4 3  
1 2 0  
2 2 0  
1 2 1  
4 3 5  
1 2 2  
4 2 0  

```
## Output


```
9  
1  
0  
7  
10  
7  
5  

```
## Input


```
5 5  
1 5 4  
1 3 1  
1 3 4  
3 1 5  
4 2 5  

```
## Output


```
12  
10  
10  
8  
7  

```
## Note

Let's consider the first sample. The first participant starts at floor *s* = 2 by the time equal to *t* = 3. To get to the floor *f* = 4, he has to wait until the time equals 7, that's the time when the elevator will go upwards for the second time. Then the first participant should get on the elevator and go two floors up. In this case the first participant gets to the floor *f* at time equal to 9. The second participant starts at the time *t* = 0 on the floor *s* = 1, enters the elevator immediately, and arrives to the floor *f* = 2. The third participant doesn't wait for the elevator, because he needs to arrive to the same floor where he starts.



#### tags 

#1300 #implementation #math 