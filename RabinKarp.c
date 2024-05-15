#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet

void search(char *pattern, char *text, int q)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {
        // Check the hash values of current window of text and pattern
        // If the hash values match, then only check for characters one by one
        if (p == t)
        {
            // Check for characters one by one
            for (j = 0; j < M; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            // If pattern[0...M-1] = text[i, i+1, ...i+M-1]
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate the hash value for next window of text: Remove leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            // Make sure t is non-negative
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    char text[100], pattern[100];
    int q = 101; // A prime number

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to search for: ");
    scanf("%s", pattern);

    search(pattern, text, q);

    return 0;
}