<h1 style='text-align: center;'> A. Любимые числа Поликарпа</h1>

<h5 style='text-align: center;'>ограничение по времени на тест: 2 секунды</h5>
<h5 style='text-align: center;'>ограничение по памяти на тест: 256 мегабайт</h5>

Поликарп мечтает стать программистом и фанатеет от степеней двойки. Среди двух чисел ему больше нравится то, которое делится на большую степень числа 2. 

По заданной последовательности целых положительных чисел *a*1, *a*2, ..., *a**n* требуется найти *r* — максимальную степень числа 2, на которую делится хотя бы одно из чисел последовательности. Кроме того, требуется вывести количество чисел *a**i*, которые делятся на *r*.

## Входные данные

В первой строке записано целое число *n* (1 ≤ *n* ≤ 100) — длина последовательности *a*.

Во второй строке записана последовательность целых чисел *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109).

## Выходные данные

Выведите два числа:

* *r* — максимальную степень двойки, на которую делится хотя бы одно из чисел заданной последовательности,
* количество элементов последовательности, которые делятся на *r*.
## Примеры

## Входные данные


```
5  
80 7 16 4 48  

```
## Выходные данные


```
16 3  

```
## Входные данные


```
4  
21 5 3 33  

```
## Выходные данные


```
1 4  

```
## Примечание

В первом тестовом примере максимальная степень двойки, на которую делится хотя бы одно число, равна 16 = 24, на неё делятся числа 80, 16 и 48.

Во втором тестовом примере все четыре числа нечётные, поэтому делятся только на 1 = 20. Это и будет максимальной степенью двойки для данного примера.



#### tags 

#1000 #constructive_algorithms #implementation 