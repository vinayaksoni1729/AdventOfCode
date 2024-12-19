#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main() {
    string corruptedText, corruptedLine;
    ifstream inputFile("input.txt");
    while (getline(inputFile, corruptedLine)) {
        corruptedText += corruptedLine;
    }
    inputFile.close();

    long int mult_sum = 0;
    bool isEnabled = true; // Multiplications are enabled by default.

    // Regular expressions for instructions
    regex mul_regex(R"(mul\((\d+),(\d+)\))");
    regex do_regex(R"(do\(\))");
    regex dont_regex(R"(don't\(\))");

    // Iterator to find all matches
    regex instruction_regex(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
    auto matchesBegin = sregex_iterator(corruptedText.begin(), corruptedText.end(), instruction_regex);
    auto matchesEnd = sregex_iterator();

    for (auto it = matchesBegin; it != matchesEnd; it++) {
        smatch match = *it;

        if (match[0].str().find("do()") != string::npos) {
            isEnabled = true; // Enable future mul instructions.
        } else if (match[0].str().find("don't()") != string::npos) {
            isEnabled = false; // Disable future mul instructions.
        } else if (match[1].matched && match[2].matched && isEnabled) {
            // If enabled, process the mul(x, y) instruction.
            mult_sum += stoi(match[1]) * stoi(match[2]);
        }
    }

    cout << mult_sum << endl;
    return 0;
}
