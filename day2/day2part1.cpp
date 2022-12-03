#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int play_game(
    unordered_map<char, int> shapes,
    char elf, char you)
{
    if (shapes[elf] == shapes[you]) return 3;
    else if ((3 + shapes[elf] - shapes[you])%3 == 1) return 0;
    else return 6;
}

int score_round(
    unordered_map<char, int> shapes,
    char elf, char you)
{
    int score = 0;
    score = play_game(shapes, elf, you) + (shapes[you] + 1);
    return score;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 0 is rock, 1 is paper, 2 is scissors
    unordered_map<char, int> shapes =
    {
        {'A', 0},
        {'B', 1},
        {'C', 2},
        {'X', 0},
        {'Y', 1},
        {'Z', 2}
    };

    int total_score = 0;

    char elf, you;
    string line;
    while (getline(cin, line))
    {
        elf = line[0], you = line[2];
        total_score += score_round(shapes, elf, you);
    }
    
    cout << total_score;

    return 0;
}