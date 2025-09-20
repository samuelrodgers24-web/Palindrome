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
    // printf("First Half: %s   |   ", firstHalf.c_str());
    // printf("Second Half: %s\n", secondHalf.c_str());
    reverse(secondHalf.begin(), secondHalf.end());
    return firstHalf == secondHalf;
}

void
addReverse(int& numIn) {
    string sIn = to_string(numIn);
    reverse(sIn.begin(), sIn.end());
    int reverse = stoull(sIn);
    numIn += reverse;
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

    // TODO write loop to add reverse to each input
    for (int i = 0; i < nums.size(); i++) {
        counts.push_back(0);
        counts[i] += 1;
        addReverse(nums[i]);
        while (!isPalindrome(nums[i]) && counts[i]<100) {
            counts[i] += 1;
            addReverse(nums[i]);
        }
        //printf("INTERNAL LOOP FINISHED - count is %d for value %d\n", counts[i], nums[i]);
    }


    // combine counters and final values
    string sOut = "";
    for (int i = 0; i < nums.size(); i++) {
        sOut += to_string(counts[i]) + " " + to_string(nums[i]) + " ";
    }
    sOut.pop_back();
    char* cPointOut = new char[sOut.length() + 1];
    strcpy(cPointOut, sOut.c_str());

    // TODO delete anything that needs to be deleted

    return cPointOut;
}


