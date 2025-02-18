#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> events;

    // Step 1: Create events for start and end of buildings
    for (const auto& b : buildings) {
        events.emplace_back(b[0], -b[2]); // Start of a building (negative height to distinguish from end)
        events.emplace_back(b[1], b[2]);  // End of a building (positive height)
    }

    // Step 2: Sort events by x-coordinates, breaking ties by height
    sort(events.begin(), events.end());

    multiset<int> heights = {0}; // Max heap simulation (sorted container)
    vector<vector<int>> result;
    int prevMax = 0;

    // Step 3: Process each event
    for (const auto& event : events) {
        int x = event.first, h = event.second;
        
        if (h < 0) {
            heights.insert(-h); // Insert new building height
        } else {
            heights.erase(heights.find(h)); // Remove building height
        }

        int currMax = *heights.rbegin(); // Get max height
        if (currMax != prevMax) { // If skyline changes, add key point
            result.push_back({x, currMax});
            prevMax = currMax;
        }
    }

    return result;
}

// Helper function to print 2D vector
void print2DVector(const vector<vector<int>>& vec) {
    for (const auto& v : vec) {
        cout << "[" << v[0] << ", " << v[1] << "] ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};

    vector<vector<int>> skyline = getSkyline(buildings);
    
    cout << "Skyline: ";
    print2DVector(skyline);

    return 0;
}
