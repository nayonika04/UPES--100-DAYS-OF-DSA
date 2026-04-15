#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Candidate {
    char name[100];
    int votes;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Candidate list[n];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        char currentName[100];
        scanf("%s", currentName);

        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(list[j].name, currentName) == 0) {
                list[j].votes++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(list[uniqueCount].name, currentName);
            list[uniqueCount].votes = 1;
            uniqueCount++;
        }
    }

    // Determine winner
    int maxVotes = 0;
    char winner[100];

    for (int i = 0; i < uniqueCount; i++) {
        if (list[i].votes > maxVotes) {
            maxVotes = list[i].votes;
            strcpy(winner, list[i].name);
        } else if (list[i].votes == maxVotes) {
            // Lexicographical tie-breaker
            if (strcmp(list[i].name, winner) < 0) {
                strcpy(winner, list[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
