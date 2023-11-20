/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i

Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

GFG : https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?page=1&company=Cisco&sortBy=submissions
*/
#include<iostream>
using namespace std;

//* time : O(|str|) length of the string, space : O()
string reverseString(string str) {
    int n = str.length();

    string ans = "";
    string character = "";
    for(int i=0; i<n; i++) {

        if(str[i] == '.'){
            ans = "." +character + ans;
            character = "";
        }else{
            character += str[i];
        }
    }

    ans = character + ans; // dont forget to add last word in the ans :>
    return ans;
}

int main()
{
    string str = "i.like.this.program.very.much";

    string output;
    output = reverseString(str);
    cout<<output;
    return 0;
}