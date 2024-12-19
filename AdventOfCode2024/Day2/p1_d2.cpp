#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int isSafe(const vector<int> &report)
{
    bool increasing = true, decreasing = true;
    for (int i = 1; i < report.size(); i++)
    {
        int avh=0;
        int diff = report[i] - report[i - 1];

        // Check if absolute value of difference is between 1 & 3 (inclusive)
        if (abs(diff) < 1 || abs(diff) > 3)
            avh+=1;

        if (diff < 0)
            increasing = false;
        if (diff > 0)
            decreasing = false;
    }
    return increasing || decreasing;
}

int main()
{
    vector<vector<int>> reports; // 2D Reports vector based on file input.txt

    ifstream inputFile("input.txt");

    string reportLine;
    while (getline(inputFile, reportLine))
    {
        vector<int> reportRow;
        stringstream levelString(reportLine);
        int level;

        while (levelString >> level)
        {
            reportRow.push_back(level);
        }
        reports.push_back(reportRow);
    }
    inputFile.close();

    int safeCount = 0;
    for (auto &report : reports)
    {
        // Check if a report is safe then increase safeCount by 1
        if (isSafe(report))
        {
            safeCount++;
        }
    }

    cout << safeCount << endl;

    return 0;
}