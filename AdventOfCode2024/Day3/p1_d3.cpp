#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main(){
    string corruptedText,corruptedLine;
    ifstream inputFile("input.txt");
    while  (getline(inputFile,corruptedLine)){
        corruptedText+= corruptedLine;
    }
    inputFile.close();
    long int mult_sum=0;
    regex mul_regex(R"(mul\((\d+),(\d+)\))");
    auto multMatchBegin= sregex_iterator(corruptedText.begin(),corruptedText.end(),mul_regex);
    auto multMatchEnd= sregex_iterator();

    for(auto it=multMatchBegin; it!=multMatchEnd;it++){
        smatch mult_match=*it;
        mult_sum+=stoi(mult_match[1])*stoi(mult_match[2]);
    }
    cout<<mult_sum<<endl;
    return 0;
}