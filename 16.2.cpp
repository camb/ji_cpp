// Chapter 16 Practice Problem 2
// Write a recursive function that takes an array and displays the elements in reverse order without starting the index of the array at the end. (In other words, don’t write the equivalent of a loop that starts printing at the end of the array.)

#include <iostream>

using namespace std;

void reverseArray(char array[], int size);

int main()
{
	char alphabet[25];
	alphabet[0] = 'a';
	alphabet[1] = 'b';
	alphabet[2] = 'c';
	alphabet[3] = 'd';
	alphabet[4] = 'e';
	alphabet[5] = 'f';
	alphabet[6] = 'g';
	alphabet[7] = 'h';
	alphabet[8] = 'i';
	alphabet[9] = 'j';
	alphabet[10] = 'k';
	alphabet[11] = 'l';
	alphabet[12] = 'm';
	alphabet[13] = 'n';
	alphabet[14] = 'o';
	alphabet[15] = 'p';
	alphabet[16] = 'q';
	alphabet[17] = 'r';
	alphabet[18] = 's';
	alphabet[19] = 't';
	alphabet[20] = 'u';
	alphabet[21] = 'v';
	alphabet[22] = 'w';
	alphabet[23] = 'x';
	alphabet[24] = 'y';
	alphabet[25] = 'z';

	reverseArray(alphabet, 25);
	cout << endl;
}

void reverseArray(char array[], int size)
{
	cout << array[size];

	if (size > 0)
	{
		reverseArray(array, size -1);
	}

}