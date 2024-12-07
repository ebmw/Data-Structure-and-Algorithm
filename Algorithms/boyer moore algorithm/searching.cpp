
#include <iostream>
#include <vector>
using namespace std;
// Function to find the candidate for majority element
int findCandidate(const std::vector<int>& arr, int left, int right) {
    if (left == right) {
        return arr[left];  // Base case: only one element
    }

    // Compare pairs and form the candidate
    int mid = left + (right - left) / 2;
    int leftCandidate = findCandidate(arr, left, mid);
    int rightCandidate = findCandidate(arr, mid + 1, right);

    if (leftCandidate == rightCandidate) {
        return leftCandidate;  // If both candidates are the same
    }

    // Return one of the candidates (we can return either since we don't know yet)
    return leftCandidate; // Returning leftCandidate for further verification
}

// Function to count occurrences of a candidate in the array
int countOccurrences(const std::vector<int>& arr, int candidate) {
    int count = 0;
    for (int num : arr) {
        if (num == candidate) {
            count++;
        }
    }
    return count;
}

// Function to find the majority element
int findMajorityElement(const std::vector<int>& arr) {
    int candidate = findCandidate(arr, 0, arr.size() - 1);

    // Verify if the candidate is the majority
    if (countOccurrences(arr, candidate) > arr.size() / 2) {
        return candidate;
    }
    return -1; // Indicate no majority element
}

int main() {
    std::vector<int> arr1 = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    std::vector<int> arr2 = {3, 3, 4, 2, 4, 4, 2, 4};

    int majority1 = findMajorityElement(arr1);
    if (majority1 != -1) {
        std::cout << "The majority element in arr1 is: " << majority1 << std::endl;
    } else {
        std::cout << "There is no majority element in arr1." << std::endl;
    }

    int majority2 = findMajorityElement(arr2);
    if (majority2 != -1) {
        std::cout << "The majority element in arr2 is: " << majority2 << std::endl;
    } else {
        std::cout << "There is no majority element in arr2." << std::endl;
    }

    return 0;
}
