<h1 style='text-align: center;'> E. Dormitory</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Student Vasya came to study in Berland State University from the country, so he is living in a dormitory. A semester has *n* days, and in each of those days his parents send him some food. In the morning of the *i*-th day he receives *a**i* kilograms of food that can be eaten on that day and on the next one (then the food goes bad and becomes unfit for consumption).

Every day Vasya eats *v* kilograms of food. It is known that Vasya's parents do not allow him to starve, so there always is enough food for Vasya. Vasya has *m* friends who sometimes live with him. Let's index the friends from 1 to *m*. Friend number *j* lives with Vasya from day *l**j* to day *r**j*, inclusive. Also, the *j*-th friend requires *f**j* kilograms of food per day. Usually Vasya's friends eat in the canteen, but sometimes generous Vasya feeds some of them. Every day Vasya can feed some friends who live with him this day (or may feed nobody).

Every time Vasya feeds his friend, he gives him as much food as the friend needs for the day, and Vasya's popularity rating at the University increases by one. Vasya cannot feed the same friend multiple times in one day. In addition, he knows that eating habits must be regular, so he always eats *v* kilograms of food per day.

Vasya wants so choose whom he will feed each day of the semester to make his rating as high as possible. Originally Vasya's rating is 0 because he is a freshman.

## Input

The first line contains two integers *n* and *v* (1 ≤ *n*, *v* ≤ 400). The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 400), separated by single spaces. Value *a**i* means that in the morning of the *i*-th day *a**i* kilograms of food come, the food is good for eating on day *i* and/or on day *i* + 1 (then the food goes bad). It is guaranteed that if Vasya doesn't feed anyone, there is a way for him to eat so as to consume *v* kilograms of food every day.

The third line contains integer *m* (1 ≤ *m* ≤ 400). Each of the following *m* lines describes one Vasya's friend: the *j*-th of these lines contains three integers *l**j*, *r**j*, *f**j* (1 ≤ *l**j* ≤ *r**j* ≤ *n*, 1 ≤ *f**j* ≤ 400), separated by single spaces.

## Output

In the first line print the highest rating Vasya can reach. In the next *n* lines print, which friends Vasya needs to feed on each day. In the *i*-th of these lines first print the number of friends to feed on the *i*-th day, and then list the indexes of these friends. Print the friends in these lists in any order. If there are multiple optimal solutions, print any of them.

## Examples

## Input


```
4 1  
3 2 5 4  
3  
1 3 2  
1 4 1  
3 4 2  

```
## Output


```
7  
1 2  
1 2  
3 2 1 3  
2 2 3  

```


#### tags 

#2100 #dp #implementation 