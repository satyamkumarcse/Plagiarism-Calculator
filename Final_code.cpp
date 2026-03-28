#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class PlagiarismChecker {
private:
    std::vector<std::string> lines1;
    std::vector<std::string> lines2;
    std::vector<std::string> words1;
    std::vector<std::string> words2;

    void toLower(std::string &s) {
        for (char &c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
        }
    }

    void readLines(const std::string &file, std::vector<std::string> &lines) {
        std::ifstream fin(file);
        std::string line;

        if (!fin.is_open()) {
            std::cout << "Error opening file: " << file << std::endl;
            return;
        }

        while (std::getline(fin, line)) {
            toLower(line);
            if (!line.empty()) {
                lines.push_back(line);
            }
        }

        fin.close();
    }

    void extractWords(const std::vector<std::string> &lines,
                      std::vector<std::string> &words) {
        for (const std::string &line : lines) {
            std::stringstream ss(line);
            std::string word;
            while (ss >> word) {
                words.push_back(word);
            }
        }
    }

public:
    void loadFiles(const std::string &f1, const std::string &f2) {
        readLines(f1, lines1);
        readLines(f2, lines2);
        extractWords(lines1, words1);
        extractWords(lines2, words2);
    }

    double detectDirectPlagiarism() {
        int matchCount = 0;
        int j = 0;

        for (int i = 0; i < lines1.size(); i++) {
            while (j < lines2.size()) {
                if (lines1[i] == lines2[j]) {
                    matchCount++;
                    j++;
                    break;
                }
                j++;
            }
        }

        if (lines1.size() == 0) {
            return 0.0;
        }

        return (double)matchCount / lines1.size() * 100;
    }

    double detectPartialPlagiarism() {
        int matchCount = 0;

        for (int i = 0; i < words1.size(); i++) {
            for (int j = 0; j < words2.size(); j++) {
                if (words1[i] == words2[j]) {
                    matchCount++;
                    break;
                }
            }
        }

        if (words1.size() == 0) {
            return 0.0;
        }

        return (double)matchCount / words1.size() * 100;
    }
};

int main() {
    std::string file1, file2;

    std::cout << "Enter first file name: ";
    std::cin >> file1;

    std::cout << "Enter second file name: ";
    std::cin >> file2;

    PlagiarismChecker checker;
    checker.loadFiles(file1, file2);

    double direct = checker.detectDirectPlagiarism();
    double partial = checker.detectPartialPlagiarism();

    double similarity = (direct > partial) ? direct : partial;

    std::cout << "\nDirect Plagiarism: " << direct << "%" << std::endl;
    std::cout << "Partial Plagiarism: " << partial << "%" << std::endl;
    std::cout<<std::endl;
    std::cout << "Similarity Percentage: " << similarity << "%" << std::endl;

    if (similarity >= 0 && similarity < 10) {
        std::cout << "Very Low Plagiarism" << std::endl;
    } else if (similarity >= 10 && similarity < 20) {
        std::cout << "Low Plagiarism" << std::endl;
    } else if (similarity >= 20 && similarity < 40) {
        std::cout << "High Plagiarism" << std::endl;
    } else if (similarity >= 40 && similarity < 70) {
        std::cout << "Very High Plagiarism" << std::endl;
    } else {
        std::cout << "Extreme Plagiarism" << std::endl;
    }

    return 0;
}
