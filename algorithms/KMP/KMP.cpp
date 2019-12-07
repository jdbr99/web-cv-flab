/*
Finding the prefix that are also is suffix for every i-th position (prefix) of an array in O(N). No propio.
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    //Declare variables and read the string
    cout << "Enter the string\n";
    string word;
    cin >> word;

    int n = word.length();
    int dp[n];

    //KMP 
    int j = dp[0] = -1;; //We start at dp[0] = -1 which is my longest substring until now.

    for (int i = 1; i < n; i++){
        while ( j >= 0 && word[j+1] != word[i]) // if j == -1 means that we coudn't find the substring, or if word[j+1] == word[i] means that the last character plus one of the maximun substring is equal to the last character of the preffix i, so this is the longest substring that is a prefix and a suffix of the i-th prefix. 
            j = dp[j]; //While niether of before happen, we move know to the preffix of the maximun substring, and repeat.
        if(word[j+1] == word[i]) j++; //If we find a match of the last letter that means that the prefix j match with the suffix - 1, and the last letter match so the maximun substring its j+1;
        dp[i] = j; //We store in DP the index of the maximun substring.
    }

    //Print the set for every prefix

    for (int i = 0; i < n; i++){
        cout << "For the prefix from [0," << i <<"] which is "<< word.substr(0, i+1) << " the non-proper prefix that are also suffixes are:\n";
        j = dp[i]; // inticialize by the longest
        while( j != -1){
            cout << word.substr(0, j+1) << '\n';//We print the substring which must be a prefix.
            j = dp[j]; //We move to the longest substring of the prefix with size of my actual longest substring, that is my kth longest substring
        }
        cout << "\n";
    }

    return 0;
}