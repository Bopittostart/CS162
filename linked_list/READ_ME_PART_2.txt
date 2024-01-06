Name: Quinn Roth
ID: 934437362

Hello Jacob Evans?

Description: 
    The program creates a linked list from scratch. A linked list is a way to store data. Specifically a linked list 
is a list of data that is linked together by pointers. Linked lists are particularly effecient at deleting data and inserting
data compared to other data structures. Usually a linked list is pre-made like an array or a vector, but this program makes a
linked list from scratch and includes various functions to alter the list. The program runs through a series of tests that test 
the variosu features included. The program can add an element to the front, back, and anywhere in between in the linked list. 
It can delete an element from the front, back, and anywhere in between in the linked list. It can clear the list entirely. It can
also sort the elements inside the linked list from lowest to highest and highest to lowest. This uses a tecnique called merge sort and select sort. 
Merge sort splits the list into two seperate halves, then splits those lists into two halves and continues to split the lists
until all of the lists have 1 element in them. It then compares two lists, sorts them accordingly and merges them together. 
For example if you have a list with the number 5 and a list with the number 9, the sorted list (if it was sorted ascendingly) would
be 5, 9. Merge sort continues to merge two lists together into a sorted list until there is only one list left. When sorting descendingly
instead of comparing to see which was smaller you compare to see which one is bigger. Selection sort assigns the frist element to max value 
then goes through the list comparing the elements to the currently assigned max value. If the new value is bigger than the max value it is now 
the max value. Once it has gone through the entire list it places the max value at the beginning of the list. It repeats this until the list is sorted.

Instructions:
    Once the zip file has been unzipped make sure you are writing to the correct terminal. Go into the terminal and write make. Then
    type into the termal "./run_list". You will be presented with the first test. Hit enter to move onto the next test. 
    The first test tests if the lenght is accurate. Test 2.1 tests the push_front function which pushes an element int othe front of the list.
    Test 2.2 tests the pop_front function which removes the first element of the linked list. Test 2.3 tests the push_front function which
    inserts an element to the back of the linked list. Test 2.4 tests pop_back which removes the last element of the linked list. Test 2.5
    tests the  insert function which inserts an element somewhere in the list depending on a given index. Text 2.6 tests the remove function
    which removes an element in the linked list depending on a given index. Test 3 tests sort ascending and sort descending functions.
    Sort ascending uses merge sort to sort the list from lowest to highest. Sort descending uses selection sort to sort the list from highest to lowest.
    Test 4 tests the clear function which clears the entire linked list.

Extra Credit: 
    Selection Sort: 
        Selection sort assigns the frist element to max value then goes through the list comparing the elements to the currently assigned
        max value. If the new value is bigger than the max value it is now the max value. Once it has gone through the entire list it 
        places the max value at the beginning of the list. It repeats this until the list is sorted.
        
Limitations:
    The program only accepts enter as an appropriate input.

Complexity analysis:
    Sort ascending:
        Sort ascending uses merge sort to sort the linked list from lowest to highest. Merge sort is a sorting algorithm that recursivly 
        splits the list into smaller and smaller lists until there are only lists  of size 1 left. Then it merges two lists together to 
        and makes a sorted list. This list has the values in the correct order. It merges two lists together into sorted lists until
        there is only one sorted list left. The time complexity of merge sort is O(n*log(n)).

    Sort Descending:
        Sort descending uses selection sort to sort the linked list from highest to lowest.
        Selection sort assigns the frist element to max value then goes through the list comparing the elements to the currently assigned
        max value. If the new value is bigger than the max value it is now the max value. Once it has gone through the entire list it 
        places the max value at the beginning of the list. It repeats this until the list is sorted.
        The time complecity of selection sort is O(n^2).