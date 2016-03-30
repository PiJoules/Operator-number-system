#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * Convert an nos string to decimal number.
 */
static uint64_t nosToDecimal(string nos){
    size_t n = nos.length();
    uint64_t result = 0;
    for (int i = 0; i < n; ++i){
        switch (nos[i]){
            case '0':
                result += i + 1;
                break;
            case '1':
                result -= i + 1;
                break;
            default:
                result *= i + 1;
        }
    }
    return result;
}


/**
 * Cartesian product of vector of vectors.
 * Thanks https://gist.github.com/thirdwing/953b146ba39c5f5ff562
 */
template <typename T>
static vector<vector<T>> cartesianProduct(const vector<vector<T>>& v) {
    vector<vector<T>> s = {{}};
    for (auto& u : v) {
        vector<vector<T>> r;
        for (auto& x : s) {
            for (auto y : u) {
                r.push_back(x);
                r.back().push_back(y);
            }
        }
        s.swap(r);
    }
    return s;
}


/**
 * Convert a decimal number to an nos string.
 */
static string decimalToNos(uint64_t num){
    uint64_t i = 1;
    vector<string> valid;
    while (valid.empty()){
        vector<char> v = {'0', '1', '2'};
        vector<vector<char>> v2(i, v);
        vector<vector<char>> combos = cartesianProduct(v2);
        for (size_t j = 0; j < combos.size(); ++j){
            string combo(combos[j].begin(), combos[j].end());
            uint64_t dec = nosToDecimal(combo);
            if (dec == num){
                valid.push_back(combo);
            }
        }
        i++;
    }
    return *max_element(valid.begin(), valid.end(),
            [](const string& s1, const string& s2){
                return count(s1.begin(), s1.end(), '0') < count(s2.begin(), s2.end(), '0');
            });
}


/**
 * Print script usage.
 */
static void printUsage(string scriptName){
    cerr << "Usage: " << scriptName << " nos_number " << endl;
    cerr << "   or: " << scriptName << " --nos decimal_number" << endl;
    cerr << "   or: " << scriptName << " --compress file_to_compress" << endl;
    cerr << "   or: " << scriptName << " --decompress nos_compressed_file" << endl;
}


int main(int argc, char* argv[]){
    if (argc < 2){
        printUsage(argv[0]);
        return 1;
    }

    string arg(argv[1]);
    if (arg == "--nos"){
        string arg2(argv[2]);
        size_t size = 0;
        cout << decimalToNos(stoull(arg2, &size, 0)) << endl;
    }
    else if (arg == "--compress"){

    }
    else if (arg == "--decompress"){
    
    }
    else {
        cout << nosToDecimal(arg) << endl;
    }

    return 0;
}

