<h1 style='text-align: center;'> N. Waste Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The progress is not standing still in Berland. Recently all garbage containers in Bertown, the capital of Berland, were replaced by differentiated recycling bins, each accepting some category of waste. While this will definitely improve the ecological situation, for some citizens it's difficult to get used to the habit of sorting waste.

Monocarp is one of those citizens who tries to get used to waste sorting. Today he has to take out the trash from his house. There are three containers near the Monocarp's house, the first one accepts paper waste, the second one accepts plastic waste, and the third one — all other types of waste. It is possible to fit $c_1$ items into the first container, $c_2$ items into the second container and $c_3$ items into the third container.

Monocarp has a lot of items to throw into containers. Some are made of paper, so Monocarp has to put them into the first container (he has $a_1$ such items), some are made of plastic, so he has to put them into the second container (he has $a_2$ such items), and some are neither paper nor plastic — so Monocarp has to put them into the third container (he has $a_3$ such items).

Unfortunately, there are also two categories of items that Monocarp is unsure of: he has $a_4$ items which are partially made of paper, so he will put each of these items either into the first container or into the third container. Similarly, he has $a_5$ items partially made of plastic, so he has to put each of them either into the second container or into the third container. Obviously, this choice is made separately for each item — for example, Monocarp can throw several partially-plastic items into the second container, and all other partially-plastic items — into the third one.

Now Monocarp wonders: is it possible to put each item into some container so that the first container will hold no more than $c_1$ items, the second one — no more than $c_2$ items, and the third one — no more than $c_3$ items?

## Input

The first line contains one integer $t$ ($1 \le t \le 3 \cdot 10^4$) — the number of test cases. 

Each test case consists of two lines. The first line of each test case contains three integers $c_1$, $c_2$, $c_3$ ($0 \le c_1, c_2, c_3 \le 10^8$) — the capacities of the containers. 

The second line of each test case contains five integers $a_1$, $a_2$, $a_3$, $a_4$, $a_5$ ($0 \le a_i \le 10^8$), where $a_i$ is the number of items of the $i$-th category Monocarp has to throw out ($i = 1$ is paper waste, $i = 2$ is plastic waste, $i = 3$ is general waste, $i = 4$ is partially-paper waste, $i = 5$ is partially-plastic waste).

## Output

For each test case, print either YES if it is possible to fit all items into containers, or NO otherwise. You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

## Example

## Input


```

7
1 2 3
1 2 3 0 0
2 2 3
1 2 3 1 0
2 2 3
1 2 3 0 1
1 2 5
1 2 3 1 1
0 0 0
0 0 0 0 0
0 0 4
1 0 0 0 0
13 37 42
0 0 0 40 47

```
## Output


```

YES
YES
NO
YES
YES
NO
YES

```
## Note

Explanations for the example test cases:

1. Monocarp can put $1$ item of paper waste into the first container, $2$ items of plastic waste into the second container, and $3$ items of general waste into the third container;
2. Monocarp can put $1$ item of paper waste and $1$ item of partially-paper waste into the first container, $2$ items of plastic waste into the second container, and $3$ items of general waste into the third container;
3. there is no answer since either the second container should contain $3$ items, or the third container should contain $4$ items;
4. Monocarp can put $1$ item of paper waste into the first container, $2$ items of plastic waste into the second container, and $3$ items of general waste, $1$ item of partially-paper waste and $1$ item of partially-plastic waste into the third container;
5. there is no waste at all, so all containers can be left empty;
6. there's no answer since it's impossible to put a paper item into the third container;
7. Monocarp can put $10$ items of partially-paper waste into the first container, $37$ items of partially-plastic waste into the second container, and $30$ items of partially-paper waste and $10$ items of partially-plastic waste into the third container.


#### tags 

#900 #greedy #implementation 