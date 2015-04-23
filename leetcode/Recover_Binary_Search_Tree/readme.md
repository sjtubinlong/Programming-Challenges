When we have a sorted list of integers (assume it was in increasing order) with two elements were swapped by a error opration, we can scan it and detect where errors happend.

Scan the list from left to right, and check every position if it is bigger than the former one.

When we detect the first error, where D[i] <= D[i-1], we can determine that i-1 is the first error element's position.(Because the first error element is from a high place). If no further error detected, then i is the second error element's position.

Because the second error element is from a lower position, so while D[i] <= D[i-1] then i is what we want.

For example, [6, 3, 4, 5, 2]

3 <= 6, so 6 is the first error element
2 <= 5, so 2 is the second error element

[2, 1]

1 <= 2 , so 2 is the first error element
After traverse throughout the list, no more error detects, thus 1 is the second error element.

The InOrder traverse of A BST is similar to scan a sorted list.


