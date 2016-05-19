// Chapter 16 Practice Problem 4
// Write a recursive function that takes a sorted array and a target element and finds that element in the array (returning the index, or -1 if the element isn’t in the array). How fast can you make this search? Can you do better than looking having to look at every element?

#include <iostream>

using namespace std;

int removeNum(int array[], int size, int target, int cur);

int main ()
{
    int sorted_ints[9];
    sorted_ints[0] = 1;
    sorted_ints[1] = 5;
    sorted_ints[2] = 11;
    sorted_ints[2] = 23;
    sorted_ints[3] = 33;
    sorted_ints[4] = 45;
    sorted_ints[5] = 50;
    sorted_ints[6] = 52;
    sorted_ints[7] = 61;
    sorted_ints[8] = 77;
    sorted_ints[9] = 100;

    for (int i = 0; i < 10; i++)
    {
        cout << sorted_ints[i] << endl;
    }

    cout << "The index of 77 is: " << removeNum(sorted_ints, 9, 77, 0) << endl;
    cout << "The index of 23 is: " << removeNum(sorted_ints, 9, 23, 0) << endl;
    cout << "The index of 52 is: " << removeNum(sorted_ints, 9, 52, 0) << endl;
    cout << "The index of 99 is: " << removeNum(sorted_ints, 9, 99, 0) << endl;
}

int removeNum(int array[], int size, int target, int cur)
{
    if (cur == size)
    {
        return -1;
    }
    else if (array[cur] == target)
    {
        return cur;
    }
    else
    {
       removeNum(array, size, target, ++cur);
    }
}