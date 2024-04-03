/*

977. Squares of a sorted array

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.



Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]




Solution: 
To solve this problem we can employ the 2 pointer technique.

With this, we will create two pointers, left and right, which will actively scan
through the array. 

Since the array is sorted and we are looking for the squares, both ends
of the array give us the highest values

We can have our left and right pointers start at these ends and set a variable 
to track which one is the highest square 

when the highest square is found we can place it inside of a new array created based on the size
of the initial array

we can continue to do this once everything has been filled

*/

#include <iostream>
#include <vector>



class Solution {

public:
	static std::vector<int> sortedSquares(const std::vector<int>& arr);

};



std::vector<int> Solution::sortedSquares( const std::vector<int>& arr) {

	//We can create a variable n that will initialize the new array with n size,
	//but will also be used to track where we are while inserting elements within the new array
	int n = arr.size();

	//First we need to initialize our variables
	//We need to create a new vector array which is the same size as arr, to store our results
	std::vector<int> result(n);

	//We need to create both pointers left and right
	//Left will be initialized to the first element within arr which is the largest negative value
	int left = 0;

	//Right will be initialized to the last element within arr which is the largest positive value
	int right = arr.size() - 1;

	//We need to create a counter for what the largest value currently is in order to insert
	//the largest value at the end of our newly created array 'result'
	//We can start by assigning it the value of the last element within arr, squared. the first value it will
	//be compared to is the first value, which is the largest negative number which could potentially be bigger
	int largerSquare = arr[arr.size() - 1] * arr[arr.size() - 1];

	//boolean value to determine if largerSquare is on the leftSide or Right side
	//Starts off on the right side by default
	bool onRightSide = true;


	//We need a while loop that will iterate through arr until left and right pointers cross each other
	//We know that when left and right cross each other, every element has been visited
	//We use = to guarentee that right crosses left (right is less than left)
	while (left <= right) {

		//Check to see if n = 0, this means our squaredArray is full and we can return it
		if (n == 0) {
			return result;
		}

		//Now we can compare left and right in order to insert the largest square within our new array
		//If right is larger than left, then we want to insert right into new array
		//and then decrement right and give largerSquare the value of left squared
		//we also want to decrement n to move down the new array
		if (largerSquare > (arr[left] * arr[left]) && onRightSide == true) {

			result[n - 1] = largerSquare;
			//largerSquare now holds the value of the left pointer
			largerSquare = arr[left] * arr[left];
			onRightSide = false;
			//Slides down arr from the right since it was inserted into new array
			right--;
			//Keeps track of index at new array while inserting, decrement since we just inserted
			n--;
		}
		else if (largerSquare < arr[left] * arr[left] && onRightSide == true) {

			//no need to change the bool value since largerSquare has not changed, its still on the right side
			result[n - 1] = arr[left] * arr[left];
			left++;
			n--;
		}
		else if (largerSquare == arr[left] * arr[left] && onRightSide == true) {


			if (n >= 2) {
				//If Right and left are equal to each other, then we want to insert both
				//and then assign largerSquare to the next right number to start the process again
				result[n - 1] = largerSquare;
				result[n - 2] = arr[left] * arr[left];
				right--;
				left++;
				n = n - 2;
				largerSquare = arr[right] * arr[right];
			}
			else {
				//if there is only one more spot within the new array, we can insert it and return the array
				result[n - 1] = largerSquare;
				return result;
			}
		}

		//largerSquare is holding left and now gets compared to left
			//largerSquare now needs to get compared to right instead
		if (largerSquare > arr[right] * arr[right] && onRightSide == false) {
			result[n - 1] = largerSquare;
			//largerSquare is now back to the right
			largerSquare = arr[right] * arr[right];
			onRightSide = true;
			left++;
			n--;
		}
		else if (largerSquare < arr[right] * arr[right] && onRightSide == false) {
			result[n - 1] = arr[right] * arr[right];
			right--;
			n--;
		}
		else if (largerSquare == arr[right] * arr[right] && onRightSide == false) {


			if (n >= 2) {
				result[n - 1] = largerSquare;
				result[n - 2] = arr[right] * arr[right];
				right--;
				left++;
				n = n - 2;
				largerSquare = arr[left] * arr[left];
			}
			else {
				result[n - 1] = largerSquare;
				return result;
			}
		}

	}

	//After the while loop is done, we should have the squares so return the array
	return result;

}

 int main() {


	 Solution solution;

	 std::vector<int> array1 = { -2,-1,0,2,3 };
	 std::vector<int> array2 = { -3,-1,0,1,2 };
	 std::vector<int> array3 = { -4,-1,0,3,10 };
	 std::vector<int> array4 = { -7,-3,2,3,11 };
	 std::vector<int> array5 = { -5,-2,2,6,9 };
	 std::vector<int> result = solution.sortedSquares(array3);

	 //Time complexity: O(n), while loop that loops through n array
	 //Space complexity: O(n), creates a new array w/ n elements
	
	

	 for (int i = 0; i < array3.size(); i++) {

		 std::cout << result[i] << ' ';
	 }



	 return 0;
 }