![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Giant Pizza

  * Task
  * Statistics

CSES - Giant Pizza

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Uolevi's family is going to order a large pizza and eat it together. A total
of $n$ family members will join the order, and there are $m$ possible
toppings. The pizza may have any number of toppings.

Each family member gives two wishes concerning the toppings of the pizza. The
wishes are of the form "topping $x$ is good/bad". Your task is to choose the
toppings so that at least one wish from everybody becomes true (a good topping
is included in the pizza or a bad topping is not included).

# Input

The first input line has two integers $n$ and $m$: the number of family
members and toppings. The toppings are numbered $1,2,\dots,m$.

After this, there are $n$ lines describing the wishes. Each line has two
wishes of the form "+ $x$" (topping $x$ is good) or "- $x$" (topping $x$ is
bad).

# Output

Print a line with $m$ symbols: for each topping "+" if it is included and "-"
if it is not included. You can print any valid solution.

If there are no valid solutions, print "IMPOSSIBLE".

# Constraints

  * $1 \le n,m \le 10^5$
  * $1 \le x \le m$

# Example

Input:

``` 3 5 \+ 1 + 2 \- 1 + 3 \+ 4 - 2 ```

Output:

``` \- + + + - ```

#### Graph Algorithms

... Road ConstructionFlight Routes CheckPlanets and KingdomsGiant PizzaCoin
CollectorMail DeliveryDe Bruijn SequenceTeleporters Path...

* * *

