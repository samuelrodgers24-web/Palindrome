#include <algorithm>
#include <cstring>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

bool isPalindrome(int num) {
    if (num < 10) { return true;}
    string val = to_string(num);
    string firstHalf;
    string secondHalf;

    if (val.length() % 2 != 0) {
        firstHalf = val.substr(0, val.length() / 2);
        secondHalf = val.substr((val.length() / 2)+1);
    } else {
        firstHalf = val.substr(0, val.length() / 2);
        secondHalf = val.substr((val.length() / 2));
    }
    printf("First Half: %s   |   ", firstHalf.c_str());
    printf("Second Half: %s\n", secondHalf.c_str());
    reverse(secondHalf.begin(), secondHalf.end());
    return firstHalf == secondHalf;
}

void
addReverse(int& numIn) {
    printf("BEFORE ADDITION: %d   |   ", numIn);
    string sIn = to_string(numIn);
    reverse(sIn.begin(), sIn.end());
    int reverse = stoi(sIn);
    numIn += reverse;
    printf("AFTER ADDITION: %d\n", numIn);
}

char* process(const char* numbers) {
    // handle empty argument
    if (strlen(numbers) < 1) {
        //char* s_out[] = ;
        return NULL;
    }

    // set up variables
    vector<int> nums;
    vector<int> counts;
    char charNums[strlen(numbers)+1];
    strcpy(charNums, numbers);

    // convert char* to numbers
    char* first = strtok(charNums, " ");
    while (first != NULL)
    {
        int firstInt = atoi(first);
        nums.push_back(firstInt);
        first = strtok (NULL, " ");
    }

    // TODO write loop to add reverse
    //  - Do this for one number first, then all of them
    counts.push_back(0);
    counts[0] += 1;
    addReverse(nums[0]);
    //while (!isPalindrome(nums[0]) && counts[0]<100) {}

    // TODO combine counters and final values

    // TODO delete anything that needs to be deleted
    return NULL;
}


