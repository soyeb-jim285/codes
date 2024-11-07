<h1 style='text-align: center;'> D. PriceFixed</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Lena is the most economical girl in Moscow. So, when her dad asks her to buy some food for a trip to the country, she goes to the best store  — "PriceFixed". Here are some rules of that store:

* The store has an infinite number of items of every product.
* All products have the same price: $2$ rubles per item.
* For every product $i$ there is a discount for experienced buyers: if you buy $b_i$ items of products (of any type, not necessarily type $i$), then for all future purchases of the $i$-th product there is a $50\%$ discount (so you can buy an item of the $i$-th product for $1$ ruble!).

Lena needs to buy $n$ products: she must purchase at least $a_i$ items of the $i$-th product. Help Lena to calculate the minimum amount of money she needs to spend if she optimally chooses the order of purchasing. ## Note

 that if she wants, she can buy more items of some product than needed.

## Input

The first line contains a single integer $n$ ($1 \leq n \leq 100\,000$) — the number of products.

Each of next $n$ lines contains a product description. Each description consists of two integers $a_i$ and $b_i$ ($1 \leq a_i \leq 10^{14}$, $1 \leq b_i \leq 10^{14}$) — the required number of the $i$-th product and how many products you need to buy to get the discount on the $i$-th product. 

The sum of all $a_i$ does not exceed $10^{14}$.

## Output

## Output

 the minimum sum that Lena needs to make all purchases. 

## Examples

## Input


```

3
3 4
1 3
1 5

```
## Output


```

8

```
## Input


```

5
2 7
2 8
1 2
2 4
1 8

```
## Output


```

12

```
## Note

In the first example, Lena can purchase the products in the following way:

1. one item of product $3$ for $2$ rubles,
2. one item of product $1$ for $2$ rubles,
3. one item of product $1$ for $2$ rubles,
4. one item of product $2$ for $1$ ruble (she can use the discount because $3$ items are already purchased),
5. one item of product $1$ for $1$ ruble (she can use the discount because $4$ items are already purchased).

In total, she spends $8$ rubles. It can be proved that it is impossible to spend less.

In the second example Lena can purchase the products in the following way:

1. one item of product $1$ for $2$ rubles,
2. two items of product $2$ for $2$ rubles for each,
3. one item of product $5$ for $2$ rubles,
4. one item of product $3$ for $1$ ruble,
5. two items of product $4$ for $1$ ruble for each,
6. one item of product $1$ for $1$ ruble.

In total, she spends $12$ rubles.



#### tags 

#1600 #binary_search #greedy #implementation #sortings #two_pointers 