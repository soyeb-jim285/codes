<h1 style='text-align: center;'> B. Karen and Coffee</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

To stay woke and attentive during classes, Karen needs some coffee!

 ![](images/2cdaba6bbbe757e9a8aa9e308a9c2b1da4b8b485.png) Karen, a coffee aficionado, wants to know the optimal temperature for brewing the perfect cup of coffee. Indeed, she has spent some time reading several recipe books, including the universally acclaimed "The Art of the Covfefe".

She knows *n* coffee recipes. The *i*-th recipe suggests that coffee should be brewed between *l**i* and *r**i* degrees, inclusive, to achieve the optimal taste.

Karen thinks that a temperature is admissible if at least *k* recipes recommend it.

Karen has a rather fickle mind, and so she asks *q* questions. In each question, given that she only wants to prepare coffee with a temperature between *a* and *b*, inclusive, can you tell her how many admissible integer temperatures fall within the range?

## Input

The first line of input contains three integers, *n*, *k* (1 ≤ *k* ≤ *n* ≤ 200000), and *q* (1 ≤ *q* ≤ 200000), the number of recipes, the minimum number of recipes a certain temperature must be recommended by to be admissible, and the number of questions Karen has, respectively.

The next *n* lines describe the recipes. Specifically, the *i*-th line among these contains two integers *l**i* and *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ 200000), describing that the *i*-th recipe suggests that the coffee be brewed between *l**i* and *r**i* degrees, inclusive.

The next *q* lines describe the questions. Each of these lines contains *a* and *b*, (1 ≤ *a* ≤ *b* ≤ 200000), describing that she wants to know the number of admissible integer temperatures between *a* and *b* degrees, inclusive.

## Output

For each question, output a single integer on a line by itself, the number of admissible integer temperatures between *a* and *b* degrees, inclusive.

## Examples

## Input


```
3 2 4  
91 94  
92 97  
97 99  
92 94  
93 97  
95 96  
90 100  

```
## Output


```
3  
3  
0  
4  

```
## Input


```
2 1 1  
1 1  
200000 200000  
90 100  

```
## Output


```
0  

```
## Note

In the first test case, Karen knows 3 recipes.

1. The first one recommends brewing the coffee between 91 and 94 degrees, inclusive.
2. The second one recommends brewing the coffee between 92 and 97 degrees, inclusive.
3. The third one recommends brewing the coffee between 97 and 99 degrees, inclusive.

A temperature is admissible if at least 2 recipes recommend it.

She asks 4 questions.

In her first question, she wants to know the number of admissible integer temperatures between 92 and 94 degrees, inclusive. There are 3: 92, 93 and 94 degrees are all admissible.

In her second question, she wants to know the number of admissible integer temperatures between 93 and 97 degrees, inclusive. There are 3: 93, 94 and 97 degrees are all admissible.

In her third question, she wants to know the number of admissible integer temperatures between 95 and 96 degrees, inclusive. There are none.

In her final question, she wants to know the number of admissible integer temperatures between 90 and 100 degrees, inclusive. There are 4: 92, 93, 94 and 97 degrees are all admissible.

In the second test case, Karen knows 2 recipes.

1. The first one, "wikiHow to make Cold Brew Coffee", recommends brewing the coffee at exactly 1 degree.
2. The second one, "What good is coffee that isn't brewed at at least 36.3306 times the temperature of the surface of the sun?", recommends brewing the coffee at exactly 200000 degrees.

A temperature is admissible if at least 1 recipe recommends it.

In her first and only question, she wants to know the number of admissible integer temperatures that are actually reasonable. There are none.



#### tags 

#1400 #binary_search #data_structures #implementation 