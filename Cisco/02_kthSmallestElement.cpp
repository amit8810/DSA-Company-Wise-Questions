/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Note :-  l and r denotes the starting and ending index of the array.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
L=0 R=5
Output : 7
Explanation :
3rd smallest element in the given 
array is 7.
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

//* BruteForce
//* time : O(nlogn) space : O(1)
int kthSmallestElement(int *arr, int l, int r, int k) {
    //sort the array with : quick sort
    int n = r + 1; // size of the array
    sort(arr , arr+n); // time take : nlogn
    return arr[k-1]; // constant time
}

//* Optimized approach
//* time : O(k * log(k) + (r - k) * log(k)) space : O(k)
int kthSmallestELementOptimzed(int *arr, int l, int r, int k) {
    // create a max-heap
    priority_queue<int> maxHeap;
    //Insert the first k elements of the array into the max-heap
    for(int i=0; i<k; i++) {
        maxHeap.push(arr[i]);
    }

    // Continue iterating through the array from the (k+1)th element to the end (r).
    // Compare each element with the largest element (top element) in the max-heap.
    // If the current element is smaller, remove the largest element from the heap and insert the current element.
    for(int i=k; i<=r; i++) {

        if(arr[i] < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    // The top element of the max-heap will be the kth smallest element in the array.
    return maxHeap.top();
}

int main()
{
    int arr[6] = {7, 10, 4, 3, 20, 15};
    int l = 0, r = 5;
    int k = 3;

    cout<< "kth smallest element using bruteforce approach : " << kthSmallestElement(arr, l, r, k);
    cout<< "\nkth smallest element using optimzed approach approach : " << kthSmallestELementOptimzed(arr, l, r, k);
    return 0;
}