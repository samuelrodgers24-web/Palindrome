#include <algorithm>
#include <cstring>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

/**
 * Checks if the input is a palindrome
 * @param num the number to be checked
 * @return true if it is a palindrome, false if not
 */
bool isPalindrome(unsigned long long num) {
    if (num < 10) { return true;}
    string val = to_string(num);
    string firstHalf;
    string secondHalf;

    if (val.length() % 2 != 0) { // length is even
        firstHalf = val.substr(0, val.length() / 2);
        secondHalf = val.substr((val.length() / 2)+1);
    } else {                     // length is odd
        firstHalf = val.substr(0, val.length() / 2);
        secondHalf = val.substr((val.length() / 2));
    }
    reverse(secondHalf.begin(), secondHalf.end());
    return firstHalf == secondHalf;
}

/**
 * Takes the mirror of the input and adds the result to the input
 * @param numIn number to modify
 */
void addReverse(unsigned long long& numIn) {
    string sIn = to_string(numIn);
    reverse(sIn.begin(), sIn.end());
    unsigned long long reverse = stoull(sIn);
    numIn += reverse;
}

char* process(const char* numbers) {
    // handle empty argument
    if (strlen(numbers) < 1) {
        char* cPointOut = new char[0];
        strcpy(cPointOut, "");
        return cPointOut;
    }

    // set up variables
    vector<unsigned long long> nums;
    vector<int> counts;
    char charNums[strlen(numbers)+1];
    strcpy(charNums, numbers);

    // convert char* to numbers
    // store values in the vector 'nums'
    char* first = strtok(charNums, " ");
    while (first != NULL) {
        string s = first;
        unsigned long long firstInt = stoull(s);
        nums.push_back(firstInt);
        first = strtok (NULL, " ");
    }

    // loop to add reverse to each input
    for (int i = 0; i < nums.size(); i++) {
        counts.push_back(0);
        counts[i] += 1;
        addReverse(nums[i]);
        while (!isPalindrome(nums[i]) && counts[i]<100) {
            counts[i] += 1;
            addReverse(nums[i]);
        }
    }


    // combine counters and final values
    string sOut = "";
    for (int i = 0; i < nums.size(); i++) {
        sOut += to_string(counts[i]) + " " + to_string(nums[i]) + " ";
    }
    sOut.pop_back();
    char* cPointOut = new char[sOut.length() + 1]; // delete this??
    strcpy(cPointOut, sOut.c_str());

    // TODO delete anything that needs to be deleted
    // TODO try not to use unsigned long long for every single value

    return cPointOut;
}


