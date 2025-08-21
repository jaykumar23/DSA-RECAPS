// merge sort -> divide the elements using recursion & merge using conquer
// TC: O(log n)
// SC: O(N)

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);
  
    // adding it to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    // base case
    if (low >= high) return;
    int mid = low + (high - low) / 2;
  
    // recursive calls
    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
  
    // merge step
    merge(arr, low, mid, high);
}
