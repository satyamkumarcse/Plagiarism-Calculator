# Plagiarism-Calculator
Plagiarism Checker : A simple plagiarism checker that compares text files to measure similarity using string processing and file handling. Useful for detecting copied content and understanding basic text similarity techniques.



# Plagiarism Checker (C++)

This is a simple plagiarism detection program written in C++. It compares two text files and calculates how similar they are.

The program checks similarity in two ways:

1. Direct plagiarism (line by line match)
2. Partial plagiarism (word level match)



## How it works

The program reads two input files and processes their content.

### Steps:

* Converts all text to lowercase (case insensitive comparison)
* Removes empty lines
* Splits text into:

  * Lines (for direct comparison)
  * Words (for partial comparison)



## Features

### 1. Direct Plagiarism

* Compares lines from both files
* Counts how many lines are exactly the same
* Gives a percentage based on total lines

### 2. Partial Plagiarism

* Compares words from both files
* Counts matching words
* Gives a percentage based on total words

### 3. Final Similarity

* Takes the higher value of:

  * Direct plagiarism
  * Partial plagiarism



## Plagiarism Levels

| Percentage | Result    |
| ---------- | --------- |
| 0 - 10%    | Very Low  |
| 10 - 20%   | Low       |
| 20 - 40%   | High      |
| 40 - 70%   | Very High |
| 70%+       | Extreme   |



## How to Run

### Compile

```bash
g++ plagiarism.cpp -o plagiarism
```

### Run

```bash
./plagiarism
```

### Input

```
Enter first file name: file1.txt
Enter second file name: file2.txt
```

---

## Example Output

```
Direct Plagiarism: 25%
Partial Plagiarism: 40%

Similarity Percentage: 40%
High Plagiarism
```



## File Structure

* Main source file: 



## Limitations

* Does not ignore punctuation
* Does not handle synonyms or semantic similarity
* Word matching is basic (exact match only)
* Performance is not optimized for very large files



## Future Improvements

* Remove punctuation
* Use better string matching algorithms
* Add semantic similarity (NLP based)
* Improve performance using hashing or maps



## Summary

This project is a basic implementation of a plagiarism checker. It is useful for understanding how text comparison works using simple logic in C++.


