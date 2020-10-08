/*
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

static constexpr int MAX_RESULT = 5;

void filter_forbidden_chars(string& word) {
	const vector<char> forbidden{ ',', '.', '\\', '/', '@', '#', '$' };
	word.erase(remove_if(word.begin(), word.end(), [&forbidden](char A) {
		for (char ptr : forbidden) {
			if (ptr == A) {
				return 1;
			} else {
				return 0;
			}
		}
		}), word.end());
}

vector<string> SplitIntoWords(const string& text) {
	vector<string> words;
	string word;
	for (const char c : text) {
		if (c == ' ') {
			words.push_back(word);
			word = "";
		} else {
			word += c;
		}
	}
	words.push_back(word);
	return words;
}

int main(int argc, char* argv[]) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	map<string, size_t> parsed_words;
	string word;
	ifstream book(".\\C.txt", std::ios::binary);
	if (book.is_open()) {
		while (getline(book, word)) {
			vector<string> all_words = SplitIntoWords(word);
			for (auto& word : all_words) {
				filter_forbidden_chars(word);
				++parsed_words[word];
			}
		}
		book.close();
	}
	vector<pair<string, size_t>> parsed_words_bycount(parsed_words.size());
	move(parsed_words.begin(), parsed_words.end(), back_inserter(parsed_words_bycount));
	sort(parsed_words_bycount.begin(), parsed_words_bycount.end(), [](const pair<string, size_t>& A, const pair<string, size_t>& B) {
		return A.second > B.second;
		});
	if (parsed_words_bycount.size() > MAX_RESULT) {
		parsed_words_bycount.resize(MAX_RESULT);
	}
	for (const auto& word_count : parsed_words_bycount) {
		cout << word_count.first << " - " << word_count.second << endl;
	}
	return 0;
} 
*/