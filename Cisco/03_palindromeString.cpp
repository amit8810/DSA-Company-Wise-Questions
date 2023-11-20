/*
Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome

Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome

GFG : https://www.geeksforgeeks.org/problems/palindrome-string0817/1?page=1&company=Cisco&sortBy=submissions
*/
#include<iostream>
#include<string>
using namespace std;

//*BruteForce || Naive Approach
//* time : O(N); space: (N)
int isPalindrome(string s) {
    int n = s.length();

    string rev = "";
    for(int i=n-1; i>=0; i--) {
        rev += s[i];
    }

    if(s == rev) return 1;
    
    return 0;
}

//* Optimized Approach
//* time : O(N), space : O(1)
int isPalindromeOptimzed(string s) {
    int n = s.length();
    //*checking first and last characters of the string
    int first = 0;
    int last = n-1;

    while(first < last) {

        if(s[first++] != s[last--]) return 0;
    }

    // yaha tak aagye ho to palindrome hoga
    return 1;
}

int main()
{
    string str1 = "abba";
    string str2 = "abc";

    if(isPalindrome("abba")){
        cout << "Yes\n";
    }else{
        cout<< "No\n";
    }

    if(isPalindromeOptimzed("abba")){
        cout<<" Yes it is Palindrome\n";
    }else{ 
        cout<<"No it is not a Palindrome\n";
    }

}