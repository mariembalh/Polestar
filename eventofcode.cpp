// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

string opening="({<[";
string closing =")}>]";
static std::map<char, int> scores  = {
                                           {')',3 },
                                           {']', 57},
                                           {'}', 1197},
                                           {'>', 25137}};
vector<char> cumul;
vector<int> pos;
char eventofcode(string line)
{
    for (char& c : line) 
    {
       
        if( opening.find(c) != string::npos)
        {
            pos.push_back(opening.find(c));
           
            cumul.push_back(c);
         
        }
       else if((closing.find(c) != string::npos) && pos.back() == closing.find(c))
        {
           cumul.pop_back();
           pos.pop_back();
        }
        else 
            return c;
       
    
    }
   
    return 0;
}
int charToScore(char c)
{
    return scores[c];
}
int main() {
    // Write C++ code here
    string input = "{([(<{}[<>[]}>{[]{[(<()>\n[[<[([]))<([[{}[[()]]]\n[{[{({}]{}}([{[{{{}}([]\n[<(<(<(<{}))><([]([]()\n<{([([[(<>()){}]>(<<{{";
    istringstream iss(input);

    string line;
    char output ;
    int score =0;
    
    while (getline(iss, line))
    {
        output = eventofcode(line);
        score += charToScore(output);
        
    }
    cout << "the score is " << score;
    return 0;
}
