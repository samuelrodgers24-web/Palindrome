#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

char* process(const char* numbers) {

    // TODO set up variables
    vector<int> nums;
    vector<int> counts;
    char charNums[strlen(numbers)+1];
    strcpy(charNums, numbers);

    // TODO convert char* to numbers
    //  - This probably needs to be dynamically sized

    char* first = strtok(charNums, " ");
    while (first != NULL)
    {
        int firstInt = atoi(first);
        nums.push_back(firstInt);
        first = strtok (NULL, " ");
    }

    // TODO write loop to add reverse
    //  - Do this for one number first, then all of them

    // TODO combine counters and final values

    // TODO delete anything that needs to be deleted

    return NULL;
}
