#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        int n = names.size();
        std::vector<std::pair<int, std::string>> people(n);

        for (int i = 0; i < n; ++i) {
            people[i] = {heights[i], names[i]};
        }

        // Sort in descending order of heights
        std::sort(people.rbegin(), people.rend());

        std::vector<std::string> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = people[i].second;
        }

        return result;
    }
};