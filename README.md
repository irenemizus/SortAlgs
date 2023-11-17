# SortAlgs
Implementation and comparison of different simple sorting algorithms in Python and C 

The target of this project is to make sorting algorithms in Python and C in different ways and analyze their performance. The algorithms being implemented so far:
* In C
  - Quick Sort recursive algorithm (as proposed by "Introduction to Algorithms" by Th.H.Cormen)
  - Merge Sort recursive algorithm (as proposed by "Introduction to Algorithms" by Th.H.Cormen)
  - Quick Sort non-recursive algorithm with a homemade linked list implementation for cursors management
  - Merge Sort non-recursive algorithm with the same linked list implementation
 
* In Python
  - Quick Sort recursive algorithm - the same as in C
  - Merge Sort recursive algorithm - the same as in C
  - Quick Sort non-recursive algorithm with a homemade linked list implementation for cursors management - the same as in C
  - Merge Sort non-recursive algorithm with the same linked list implementation - the same as in C
  - Quick Sort non-recursive algorithm with standard python list for cursors management
  - Merge Sort non-recursive algorithm with standard python list for cursors management
 
    

## C implementation analysis report and graphs

As we can see at the diagrams below:
1. Recursive algos are linearly more effective than algos with "home-made" linked lists. I blame my code optimizing skills for that.
2. For all practically sane array sizes (up to 1B items), the complexity grows almost linearly.
3. Both recursive algos are very close to each other in terms of performance on a data distribution close to the uniform one. 
4. Linked list-based implementations are close to linearly different from each other on this type of data. Apparently, the MergeSort() function is just little less effective than the QuickSort() one.
5. With increasing number of items the difference in performance between linked lists-based and recursive algos slowly tends to one. That can be explained by growing impact of the non-linear term in complexity
$Q = a\cdot x + d\cdot x\cdot log_2(x)$. Unfortunately, we can not test this on significantly larger arrays due to the physical RAM limit (the program takes about $20\times \text{Length}$ bytes RAM).
7. The values captured for small array lengths (up to about 5K items) are not representative because of low accuracy of time measurement. 
8. There is an unexpected leap of measured times (reduction of performance) by 12% for the linked list-based MergeSort algorithm at about 1M items. I can not explain this...

![graph1](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/c/report/log.i9-10900K.macos/graph1.svg)
![graph2](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/c/report/log.i9-10900K.macos/graph2.svg)
![graph3](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/c/report/log.i9-10900K.macos/graph3.svg)
