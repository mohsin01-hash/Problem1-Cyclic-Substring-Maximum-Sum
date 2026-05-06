#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSum(char *s) {
    int n = strlen(s);
    char str[200005];

    strcpy(str, s);
    strcat(str, s);

    int freq[26] = {0};
    int left = 0, sum = 0, maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int idx = str[right] - 'a';

        freq[idx]++;
        sum += (idx + 1);

        while (freq[idx] > 1 || (right - left + 1) > n) {
            int leftIdx = str[left] - 'a';
            freq[leftIdx]--;
            sum -= (leftIdx + 1);
            left++;
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    char s[100005];

    printf("Enter string: ");
    scanf("%s", s);

    printf("Maximum Sum: %d\n", maxSum(s));

    return 0;
}
