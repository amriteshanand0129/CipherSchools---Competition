#include<iostream>
using namespace std;

int maxArea(int height[], int n) {

    int left = 0;         // Initializing left boundary of container
    int right = n - 1;    // Initializing right boundary of container

    int maxWater = 0, water;

    while(left < right) {

        water = (right - left) * min(height[left], height[right]);  // Calculating the area of water that can be stored within left and right boundary
        maxWater = max(water, maxWater);  // Comparing the current area of water with maximum area of water

        // Updating the smaller boundary with its adjacent boundary
        if(height[left] < height[right]) 
            left++;
        else    
            right--;
    }

    return maxWater;
}

int main() {

    int n;    // Size of array 
    cout << "Enter the value of n: ";
    cin >> n;

    int height[n];    // Array to store height of "n" lines 
    for(int i=0; i<n; i++) {
        cout << "Enter height of line " << i+1 << ": ";
        cin >> height[i];
    }

    cout << "Maximum area of water that can be contained is: " << maxArea(height, n);
}