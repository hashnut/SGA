#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

typedef unsigned int uint;

using namespace std;

uint alphaToUint(char x) {
    int shift_val = (x - 'A') + 1;
    
    return static_cast<uint>(1 << shift_val);
}

uint alphaToUint(uint original, char x) {
    int shift_val = (x - 'A') + 1;
	
	return (original & static_cast<uint>(1 << shift_val));
}

uint alphaToUint(string input) {
	unsigned int result = 0;
	
	for (char elem : input) {
		result |= alphaToUint(elem);
	}
	
	return result;
}

string UintToAlpha(uint input) {
	string result = "";

	for (int i = 0; i < 26; i++) {
		if (input & (1 << i)) 
			result.append(1, 'A' + i); 
	}
	
	return result;
}

void permutation(vector<string>& perm, string& input, vector<char>& output, int course_len, int idx) {
    
    if (input.length() < course_len) return;
    else if (input.length() == course_len) perm.push_back(input);
	
	// recursion exit condition
	if (output.size() == course_len) {
		perm.push_back(string(output.begin(), output.end()));
		return;
	}
	if (idx >= input.length()) return;
    
    for (int i = idx; i < input.length(); i++) {
        output.push_back(input.at(i));
		permutation(perm, input, output, course_len, idx+1);
		output.pop_back();
    }
}

vector<string> comb_string(vector<string> orders, int course_len) {
    
    vector<string> courses;

	vector<string> perm;

	vector<char> output;
	
    for (string order : orders) {
        permutation(perm, order, output, course_len, 0);
    }
	
	cout << "Permutataion Check" << endl;
	for (auto elem : perm) cout << elem << " ";
	cout << endl;
	
	// first : string->uint, second : how many?
	set<uint> course_set;
	
	uint new_key;
	for (auto &elem : perm) {
		new_key = alphaToUint(elem);
		auto itr = course_set.find(new_key);
		if (itr == course_set.end()) {
			course_set.insert(new_key);
		}
	}
	
	map<uint, uint> course_map;
	
	for (auto& candidate : course_set) {
		for (auto& order : orders) {
			new_key = alphaToUint(order);
			if ((new_key & candidate) == candidate) {
				auto itr = course_map.find(candidate);
				if (itr == course_map.end()) {
					course_map.insert(make_pair(candidate, 1));
				} else {
					itr->second++;
				}				
			}
		}
	}
	
	// pick courses if itr->second >= 2
	for (const auto& elem : course_map) {
		if (elem.second >= 2) {
			courses.push_back(UintToAlpha(elem.first));
		}
	}
    
    return courses;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // uint's bit represents alphabet
    
    for (auto course_len : course) {
        vector<string> cur_comb = comb_string(orders, course_len);
        answer.insert(answer.begin(), cur_comb.begin(), cur_comb.end());
    }
    
    return answer;
}