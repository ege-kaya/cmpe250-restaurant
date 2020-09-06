# Cmpe 250 Assignment 2

* **Deadline:** 29.10.2019 Tuesday @23:00, very strict.
* For your questions on the project,
please contact with your student teaching assistant
Ahmet Gedemenli via [afgedemenli@gmail.com](mailto:afgedemenli@gmail.com).

## Description
A restaurant is having some trouble with organization issues. Each incoming customer group must be assigned to a table by considering the following constraints:

* This restaurant has *n* number of tables, where *n* is an integer from 3 to 100.000 (3 <= *n* <= 10^5).
* Tables are named from 0 to *n-1*. The smallest table number is 0.
* Each table can have a different capacity, let's say *c_i*, such that 1 <= *c_i* <= 100000.
* Initially all tables are empty.
* There will be q customer groups in the input, arriving respectively, where (3 <= q <= 10^5).
* Customers might arrive as groups or single. Group sizes can vary between 1 to 100000.
* When a group arrives, regardless of the group size, it will be assigned to the table with current **maximum remaining capacity**. The program outputs the assigned table number. Note that different groups can be assigned to the same table.
* There will be no leavers until the last group arrives.
* If the arriving group is too large to assign, unfortunately the restaurant cannot accept them. In such case, the program prints **"-1" (without quotes)** as their assigned table number.
* If there are more than one table with the same remaining capacity, the group must be assigned to the one with the **smallest table number**.
* In the end, we need to know the final state of our restaurant. The remaining capacities of all tables are printed in descending order.


## Input
- First line will be the number of tables, *n*.
- Second line contains the sizes for each table, separated by a space.
- Third line will be the number of groups to arrive, *q*.
- Fourth line contains the sizes for each group, separated by a space.

## Output
An output consisting of **exactly** *q+1* lines.

* First *q* lines ARE the assigned table numbers of incoming *q* groups, respectively.
* The last İS the sorted list of remaining capacities of tables, in descending order, separated by a **single space character**. 
* The output is printed to a file. 
