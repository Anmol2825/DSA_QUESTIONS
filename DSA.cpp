#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
int main()
{
    cout << "ALL QUESTIONS" << endl;
    return 0;
}
// 1)Longest Substring Without Repeating Characters
// set solution O(2n)
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int ans = 0;
    set<char> st;
    int l = 0, r = 0;
    while (r < n)
    {
        if (st.find(s[r]) != st.end())
        {
            while (s[l] != s[r])
            {
                st.erase(s[l]);
                l++;
            }
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}

// 2)Reverse Integer(32 BIT ISSUE)
int reverse(int x)
{
    bool negative = x < 0;

    double result = 0;
    if (x == INT_MIN)
        return 0;
    if (negative)
        x *= -1;

    while (x > 0)
    {
        int m = x % 10;
        result = result * 10 + m;
        if (result > INT_MAX)
            return 0;
        x /= 10;
    }
    if (negative)
        return -1 * result;
    return result;
}

// 3)Minimum Deletions to Make Character Frequencies Unique
int minDeletions(string s)
{
    vector<int> freq(26, 0);
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }
    sort(freq.begin(), freq.end());
    int ans = 0;
    for (int i = 24; i >= 0; i--)
    {
        if (freq[i] == 0)
        {
            break;
        }
        if (freq[i] >= freq[i + 1])
        {
            int prev = freq[i];
            freq[i] = max(0, freq[i + 1] - 1);
            ans += prev - freq[i];
        }
    }
    return ans;
}

// 4)Minimum Moves to Equal Array Elements II
int minMoves2(vector<int> &nums)
{
    int n = nums.size(), steps = 0;
    nth_element(nums.begin(), nums.begin() + (n / 2), nums.end()); // Fixing ths median element
    int median = nums[n / 2];
    for (int i = 0; i < n; i++)
    {
        steps += abs(nums[i] - median);
    }
    return steps;
}

// 5)Max Area of Piece Of Cake Horizontal and Vertical
int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int n1 = horizontalCuts.size();
    int n2 = verticalCuts.size();
    int max1 = horizontalCuts[0] - 0;
    int max2 = verticalCuts[0] - 0;
    for (int i = 1; i < n1; i++)
    {
        max1 = max(max1, horizontalCuts[i] - horizontalCuts[i - 1]);
    }
    max1 = max(max1, h - horizontalCuts[n1 - 1]);
    for (int i = 1; i < n2; i++)
    {
        max2 = max(max2, verticalCuts[i] - verticalCuts[i - 1]);
    }
    max2 = max(max2, w - verticalCuts[n2 - 1]);
    return (1LL * max1 * max2) % 1000000007;
}

// 6)Maximum XOR After Operations
int maximumXOR(vector<int> &nums)
{
    int n = nums.size();
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans | nums[i];
    }
    return ans;
}

// 7)JUMP GAME-6(priority queue and DP)
int maxResult(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<pair<int, int>> pq;
    vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (pq.size() && pq.top().second > (i + k))
        {
            pq.pop();
        }
        dp[i] = nums[i];
        if (pq.size())
        {
            dp[i] += pq.top().first;
        }
        pq.push({dp[i], i});
    }
    return dp[0];
}

// 8)Rotate Image
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// 9)Merge Two Sorted Array (O(n) && O(1))
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int i = m - 1, j = n - 1, k = n + m - 1;
    while (k >= 0)
    {
        auto a = i < 0 ? INT_MIN : nums1[i];
        auto b = j < 0 ? INT_MIN : nums2[j];
        if (a > b)
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
}

// 10)Count Inversions
long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
    long long int count = 0;
    int i, j, k;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += (mid - i);
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return count;
}
long long int inversionCounting(long long arr[], long long temp[], long long left, long long right)
{
    long long int count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        count += inversionCounting(arr, temp, left, mid);
        count += inversionCounting(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }
    return count;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long temp[N];
    return inversionCounting(arr, temp, 0, N - 1);
}

// 11)power(x,n)//double including negative n
double myPow(double x, int n)
{
    return calculation(x, n);
}
double calculation(double x, long int n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return calculation(1 / x, -n);
    else if (n % 2)
        return calculation(x * x, n / 2) * x;
    else
        return calculation(x * x, n / 2);
}

// 12)count elements which appear more than n/2 times in an array (morey Voting algorithm)
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count = 1;
    int val = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == val)
        {
            count++;
        }
        else if (count > 0)
        {
            count--;
        }
        else
        {
            val = nums[i];
            count = 1;
        }
    }
    return val;
}

// 13)Count elements which appear n/3 times in an array
vector<int> majorityElement(int nums[], int n)
{
    int sz = n;
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
    for (i = 0; i < sz; i++)
    {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
        else if (count1 == 0)
        {
            num1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1 = count2 = 0;
    for (i = 0; i < sz; i++)
    {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
    }
    if (count1 > sz / 3)
        ans.push_back(num1);
    if (count2 > sz / 3)
        ans.push_back(num2);
    return ans;
}