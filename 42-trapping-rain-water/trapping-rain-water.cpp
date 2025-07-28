#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;

        // find index of first non-zero bar (fert)
        int fert = 0;
        while (fert < n && height[fert] == 0) fert++;
        // find index of last non-zero bar (end)
        int last = n - 1;
        while (last >= 0 && height[last] == 0) last--;
        if (fert >= last) return 0;

        // find peak position between fert and last
        int max_idx = fert;
        for (int i = fert + 1; i <= last; ++i) {
            if (height[i] > height[max_idx]) max_idx = i;
        }

        int z = 0;
        int curr = 0;
        int maxH = 0;
        // left-to-right up to max_idx
        for (int i = fert; i <= max_idx; ++i) {
            if (height[i] >= maxH) {
                z += curr;
                curr = 0;
                maxH = height[i];
            } else {
                curr += maxH - height[i];
            }
        }

        // right-to-left from last down to max_idx
        curr = 0;
        maxH = 0;
        for (int i = last; i >= max_idx; --i) {
            if (height[i] >= maxH) {
                z += curr;
                curr = 0;
                maxH = height[i];
            } else {
                curr += maxH - height[i];
            }
        }

        return z;
    }
};
