#include<unordered_map>
#include<vector>
using namespace std;

/*  Old implementation I did long time ago using C++
 *  Idea is we create a map and for any value in our k sized array
 *  We determine what value would be needed to reach our target, done by taking the difference
 *  missing = target - num_i
 *  We use this missing value to be the KEY in our map and it's VALUE will be the index of the original number.
 *  So at any point in our nums vector we come across a value that exists in our map
 *  We have found a pair that will build our target value.
 *  O(n) time with O(n) space. We pass through our original vector once, and our map grows in memory by n values
 *  until our condition is met
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> arr;
        int compliment;

        for (int i = 0; i < nums.size(); i++) {
            compliment = target - nums[i];

            if (arr.find(compliment) != arr.end()) {
                return {arr[compliment], i};
            }

            // store index if pair match in map.
            arr[nums[i]] = i;
        }

        return {};
    }
};
