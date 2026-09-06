#include <vector>
#include <map>
#include<bits/stdc++.h>

class CountSquares {
private:
    map<pair<int, int>, int> ptsCount;

public:
    CountSquares() {}

    void add(std::vector<int> point) {
        ptsCount[{point[0], point[1]}]++;
    }

    int count(std::vector<int> point) {
        int res = 0;
        int qx = point[0];
        int qy = point[1];

        for (auto& [p, count] : ptsCount) {
            int x = p.first;
            int y = p.second;

            // Check if they form a diagonal (dx == dy, and not the same point or on a straight line)
            if (std::abs(qx - x) != std::abs(qy - y) || qx == x || qy == y) {
                continue;
            }

            // Find the other two corners of the square: (x, qy) and (qx, y)
            if (ptsCount.count({x, qy}) && ptsCount.count({qx, y})) {
                res += count * ptsCount[{x, qy}] * ptsCount[{qx, y}];
            }
        }

        return res;
    }
};