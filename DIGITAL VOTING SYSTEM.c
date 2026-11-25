/* Digital Voting System */
#include <stdio.h>

struct candidate
{
    int id;
    char name[20];
    int votes;
};

struct candidate c[4] = {
    {1, "Rahul", 0},
    {2, "Priya", 0},
    {3, "Amit", 0},
    {4, "Neha", 0}
};

int voters[100];      // stores voter ids who have voted
int totalVoters = 0;

int showCandidates()
{
    int i;
    printf("\nCandidate List\n");
    for (i = 0; i < 4; i++)
        printf("%d. %s\n", c[i].id, c[i].name);
    return 0;
}

int castVote()
{
    int voterId, choice, i, alreadyVoted = 0;

    printf("Enter your voter ID: ");
    scanf("%d", &voterId);

    for (i = 0; i < totalVoters; i++)
    {
        if (voters[i] == voterId)
            alreadyVoted = 1;
    }

    if (alreadyVoted == 1)
        printf("You have already voted!\n");
    else
    {
        showCandidates();
        printf("Enter candidate number (1-4): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
        {
            c[choice - 1].votes++;
            voters[totalVoters] = voterId;
            totalVoters++;
            printf("Your vote is recorded. Thank you!\n");
        }
        else
            printf("Invalid candidate number. Vote not counted.\n");
    }
    return 0;
}

int showVotes()
{
    int i;
    printf("\nCandidate\tVotes\n");
    for (i = 0; i < 4; i++)
        printf("%s\t\t%d\n", c[i].name, c[i].votes);
    printf("Total votes: %d\n", totalVoters);
    return 0;
}

int showResult()
{
    int i, max = 0, winners = 0;

    if (totalVoters == 0)
    {
        printf("No votes yet.\n");
        return 0;
    }

    for (i = 0; i < 4; i++)
    {
        if (c[i].votes > max)
            max = c[i].votes;
    }

    for (i = 0; i < 4; i++)
    {
        if (c[i].votes == max)
            winners++;
    }

    if (winners == 1)
    {
        for (i = 0; i < 4; i++)
        {
            if (c[i].votes == max)
                printf("\nWinner is %s with %d votes\n", c[i].name, max);
        }
    }
    else
    {
        printf("\nIt is a tie between:\n");
        for (i = 0; i < 4; i++)
        {
            if (c[i].votes == max)
                printf("%s\n", c[i].name);
        }
    }
    return 0;
}

int main()
{
    int choice;

    printf("***** DIGITAL VOTING SYSTEM *****\n");

    while (1)
    {
        printf("\n1. Cast Vote\n");
        printf("2. Show Vote Count\n");
        printf("3. Show Result\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: castVote(); break;
            case 2: showVotes(); break;
            case 3: showResult(); break;
            case 4: printf("Thank you!\n"); return 0;
            default: printf("Wrong choice\n");
        }
    }
}