#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



class PlagiarismChecker {
private:
    vector<string> file1Lines;
    vector<string> file2Lines;


    void toLowerCase(string &s) {
        for (char &c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }

        }


    }


    void readFile(const string &filename, vector<string> &lines) {
        ifstream file(filename);

        string line;



        if (!file.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return;

        }

        while (getline(file, line)) {

            toLowerCase(line);
            if (line.size() > 0) {

                lines.push_back(line);
            }


        }
        file.close();
    }




public:
    void loadFiles(const string &f1, const string &f2) {
        readFile(f1, file1Lines);
        readFile(f2, file2Lines);


    }

    double calculateSimilarity() {
        int matchCount = 0;

        int j = 0;


        for (int i = 0; i < file1Lines.size(); i++) {

            while (j < file2Lines.size()) {

                if (file1Lines[i] == file2Lines[j]) {
                    matchCount++;

                    j++;
                    break;
                }
                j++;


            }
        }

        if (file1Lines.size() == 0) {


            return 0.0;
        }


        return (double)matchCount / file1Lines.size() * 100;
    }


};

int main() {


    string file1, file2;

    cout << "Enter first file name: ";


    cin >> file1;

    cout << "Enter second file name: ";


    cin >> file2;

    PlagiarismChecker checker;


    checker.loadFiles(file1, file2);

    double similarity = checker.calculateSimilarity();

    cout << "Similarity Percentage: " << similarity << "%" << endl;



    if (similarity >= 50) {
        cout << "High Plagiarism Detected" << endl;
    } else {


        cout << "Low Plagiarism Detected" << endl;
    }


    return 0;

    
}



