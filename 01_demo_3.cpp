#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class PlagiarismChecker {
private:
    std::vector<std::string> file1Lines;
    std::vector<std::string> file2Lines;

    void toLowerCase(std::string &s) {
        for (char &c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
        }
    }

    void readFile(const std::string &filename, std::vector<std::string> &lines) {
        std::ifstream file(filename);
        std::string line;

        if (!file.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return;
        }

        while (std::getline(file, line)) {
            toLowerCase(line);
            if (!line.empty()) {
                lines.push_back(line);
            }
        }

        file.close();
    }

public:
    void loadFiles(const std::string &file1, const std::string &file2) {
        readFile(file1, file1Lines);
        readFile(file2, file2Lines);
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
    std::string file1, file2;

    std::cout << "Enter first file name: ";
    std::cin >> file1;

    std::cout << "Enter second file name: ";
    std::cin >> file2;

    PlagiarismChecker checker;
    checker.loadFiles(file1, file2);

    double similarity = checker.calculateSimilarity();

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
