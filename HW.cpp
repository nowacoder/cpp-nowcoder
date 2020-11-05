#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    setbuf(stdout, 0);
    vector<string> msg  = {"Hello", "C++", "World", "from", "VS Code with Clang!"};
    
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    
    cout << endl;
}