#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout("Himanshu.txt");
    if (!fout) {
        cout << "Unable to open file";
        return 1;
    }
    string data;
    cout << "Enter your data(enter END to stop): ";
    while (getline(cin, data)) {
         if (data == "END") 
        break;
        fout << data << endl;
       
    }
    int character = 0;
    int word = 0;
    int line = 0;
    ifstream fin("Himanshu.txt");

    if (!fin) {
        cout << "Unable to open file";
        return 1; 
    }
    bool lastspace=false;
    bool inword = false;
    string str;

   
while (getline(fin, str)) {
    line++;
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            character++;
            inword = true;
        } else if (isspace(str[i])) {
            if (inword) {
                word++;
            }
            inword = false;
            lastspace = true; 
        }
        
    }
    if (inword) { 
            word++;
            inword = false;
    }
    lastspace=false;
}

 fin.close();

    if (character == 0) {
        cout << "File has only white space" << endl;
    }

    cout << "Character count: " << character << endl;
    cout << "Word count: " << word << endl;
    cout << "Line count: " << line << endl;

    return 0;
}
