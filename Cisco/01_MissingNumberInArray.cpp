/*
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Input:
N = 10
A[] = {6,1,2,8,3,4,7,10,5}
Output: 9

Input:
N = 5
A[] = {1,2,3,5}
Output: 4

GFG: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&company=Cisco&sortBy=submissions
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<numeric>
using namespace std;

//* BruteForc : Naive Approach
//* Time : O(N^2) , Space : O(1)
int missingNumberNaiveApproach(vector<int>&arr, int N) {
    int missingNumber;

    for(int i=1; i<=N; i++) {

        bool isNumberPresent = false;
        for(int j=0; j<arr.size(); j++) {

            if(i == arr[j] ) {
                isNumberPresent = true;
            }
        }
        //if still isNumberPresent = false; then its means the current number is missing in the array
        if(isNumberPresent == false) missingNumber = i;
    }
    return missingNumber;
}

//* Optimized
//* Time : O(N) , Space : O(1)
int missingNumberOptimizedSol(vector<int>&arr, int N) {

    //Sum of first N natural numbers
    long sumOfFirstNaturalNumbers = (long)(N * (N + 1)) / 2;
    //sum of elements present in Arr
    long sumOfElementsInArr = accumulate(arr.begin(), arr.end(), 0);
    //Missing Number will be equal to Sum_of_first_n_natural_numbers - Sum_of_elements_in_Arr
    int missingNumber = sumOfFirstNaturalNumbers - sumOfElementsInArr;
    return missingNumber;
}

int main()
{
    int N = 10;
    vector<int> arr = {6,1,2,8,3,4,7,10,5};
    cout<<"missing number in array is : "<< missingNumberNaiveApproach(arr, N);;
    cout<<"\nmissing number in array is : "<< missingNumberOptimizedSol(arr, N);
    return 0;
}