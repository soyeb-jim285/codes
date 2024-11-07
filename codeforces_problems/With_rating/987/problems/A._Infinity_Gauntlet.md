<h1 style='text-align: center;'> A. Infinity Gauntlet</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You took a peek on Thanos wearing Infinity Gauntlet. In the Gauntlet there is a place for six Infinity Gems:

* the Power Gem of purple color,
* the Time Gem of green color,
* the Space Gem of blue color,
* the Soul Gem of orange color,
* the Reality Gem of red color,
* the Mind Gem of yellow color.

Using colors of Gems you saw in the Gauntlet determine the names of absent Gems.

#### Input

In the first line of input there is one integer $n$ ($0 \le n \le 6$) — the number of Gems in Infinity Gauntlet.

In next $n$ lines there are colors of Gems you saw. Words used for colors are: purple, green, blue, orange, red, yellow. It is guaranteed that all the colors are distinct. All colors are given in lowercase English letters.

#### Output

In the first line output one integer $m$ ($0 \le m \le 6$) — the number of absent Gems.

Then in $m$ lines print the names of absent Gems, each on its own line. Words used for names are: Power, Time, Space, Soul, Reality, Mind. Names can be printed in any order. Keep the first letter uppercase, others lowercase.

## Examples

#### Input


```text
4  
red  
purple  
yellow  
orange  

```
#### Output


```text
2  
Space  
Time  

```
#### Input


```text
0  

```
#### Output


```text
6  
Time  
Mind  
Soul  
Power  
Reality  
Space  

```
## Note

In the first sample Thanos already has Reality, Power, Mind and Soul Gems, so he needs two more: Time and Space.

In the second sample Thanos doesn't have any Gems, so he needs all six.



#### Tags 

#800 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_485_(Div._2).md)
- [A (en)](../blogs/A_(en).md)
- [Tutorial](../blogs/Tutorial.md)
