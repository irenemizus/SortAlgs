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
8. There is an unexpected leap of measured times (reduction of performance) by 12% for the linked list-based MergeSort algorithm at about 1M items. It seems that it is caused by working with memory (allocating and freeing procedures), which becomes more challenging with increasing of items number.  

![graph1](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/c/report/log.i9-10900K.macos/graph1.svg)
![graph2](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/c/report/log.i9-10900K.macos/graph2.svg)
![graph3](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/c/report/log.i9-10900K.macos/graph3.svg)

## Python implementation analysis report and graphs

In the Python case I've implemented two variants of the non-recursive code: the one with standard embedded lists (which are actually not the lists in their conventional sense but rather arrays, and thus the procedure of deleting/adding of an item from/to them is very ineffective).

As we can see at the diagrams below:
1. Recursive algos are again linearly more effective than algos with "home-made" linked lists. However, in this case the Quick Sort recursive algorithm has slightly better performance than the one for Merge Sort. "Home-made" linked list implementations are close to each other, as well. The implementation of the Quick Sort algorithm with embedded lists is close to the Merge Sort Recursive one, but the case with Merge Sort non-recursive algorithm with standard Python lists is far worse in terms of performance than all other implementations.  
2. The complexity grows almost linearly, again, for all the implementations except for the "Merge Sort SimpleList" one, which is an obvious outsider, and asymptotically they behave similar to each other. Recursive algos, however, as well as the "Quick Sort SimpleList" algorithm, are about 1.5 -- 2 times faster for the number of items larger than 1.5M than the "LinkedList" ones. I think, the latter implementations need to be further optimized.  
3. Both recursive algos, as well as both LinkedList ones, are close to each other in terms of performance on a data distribution close to the uniform one. 
4. All the five algos (without the "Merge Sort SimpleList" one, again) behave close to each other in terms of performance.
5. The values captured for small array lengths (up to about 5K items) are not representative because of low accuracy of time measurement. 
8. There are unexpected (sometimes, very large) leaps of measured times (reduction of performance) for the linked list-based algorithms for 10K+ items. It seems that it is caused by working with memory (garbage collector actions), which becomes more challenging with increasing of items number.
9. As a benchmark value, the sorting time using a standard embedded Python sorting algorithm was also measured. It has given the value of 11.055313 sec. for 16800000 items, which is by order of magnitude larger than any recursive algorithm implemented in C. 

![graph4](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/python/report/log.i9-10900K.macos/graph4.svg)
![graph5](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/python/report/log.i9-10900K.macos/graph5.svg)
![graph6](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/python/report/log.i9-10900K.macos/graph6.svg)
![graph7](https://raw.githubusercontent.com/irenemizus/SortAlgs/master/python/report/log.i9-10900K.macos/graph7.svg)
