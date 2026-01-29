/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &arr) {
        int start = 0, end = arr.length() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr.get(mid) < arr.get(mid + 1))
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }

    int binarySearch(MountainArray &arr, int target, int start, int end, bool asc) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;

            if (asc) {
                if (val < target) start = mid + 1;
                else end = mid - 1;
            } else {
                if (val > target) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);

        int left = binarySearch(mountainArr, target, 0, peak, true);
        if (left != -1) return left;

        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }
};