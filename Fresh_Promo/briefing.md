# Overview

A supermarket is running a promotion in which customers receives prizes for purchasing a secret combination of fruits. The code list contains groups of fruits. Both the order of the groups within the code list and the order of the fruits within the group matter. However, between the groups of fruits, any number, and type of fruit is allowable. The term *anything* is used to allow for any type of fruit to appear in the location within the group.

Consider the following secret code list: [[apple, apple], [banana, anything, banana]]

Based on the above secret code list, a customer who made either of the following purchases would win the prize:

1. orange, apple, apple, banana, orange, banana
2. apple, apple, orange, orange, banana, apple, banana, banana

Write an algorithm to output 1 if the customer is a winner else output 0.

## Input

The input of the function/method consists of two arguments:

1. **codeList**: a string array of space-separated values representing the order and grouping of specific fruits that must be purchased in order to win the prize of the day.

2. **shoppingCart**: a list representing the order in which the customer purchases fruit.

## Output

Return an integer 1 if the customer is a winner else return 0.

## Note

*anything* in the codeList represents that any fruit can be ordered in place of *anything* in the group. *anything* has to be something, it cannot be *nothing*.

*anything* must represent one and only on fruit.

If secret code list is empty the it is  assumed that the customer is a winner.

## Examples

* Example 1 Input:
    codeList = [[apple, apple], [banana, *anything*, banana]]
    shoppingCart = [orange, apple, apple, banana, orange, banana]

    Output:
    1

* Example 2 Input:
    codeList = [[apple, apple], [banana, *anything*, banana]]
    shoppingCart = [banana, orange, banana, apple, apple]

    Output:
    0

* Example 3 Input:
    codeList = [[apple, apple], [banana, *anything*, banana]]
    shoppingCart = [apple, banana, apple, banana, orange, banana]

    Output:
    0

* Example 4 Input:
    codeList = [[apple, apple], [apple, apple, banana]]
    shoppingCart = [apple, apple, apple, banana]

    Output:
    0
