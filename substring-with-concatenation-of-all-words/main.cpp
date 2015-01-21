#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <cstring>
#include <unordered_map>

using namespace std;

// memory limit exceeded
//class Solution {
//    public:
//        vector<int> findSubstring(string S, vector<string> &L) {
//            vector<vector<int>> indices;
//            indices.reserve(L.size());
//            for(auto &val : L) {
//                const char *p = S.c_str();
//                const char *pval = val.c_str();
//                vector<int> vec;
//                const char *tmp = nullptr;
//                while(*p != '\0' && (tmp = strstr(p, pval)) != nullptr) {
//                    vec.push_back(tmp-S.c_str());
//                    p = tmp + val.size();
//                }
//                if(!vec.size()) {
//                    return {};
//                } else {
//                    indices.push_back(std::move(vec));
//                }
//            }

//            auto &index = indices.front();
//            int slen = L.front().size();
//            vector<int> res;
//            for(auto &p : index) {
//                int n = indices.size();
//                int l, r;
//                l = r = p;
//                int i=1;
//                for(; i<n; ++i) {
//                    unsigned key;
//                    if(l >= slen) {
//                        key = l - slen;
//                        auto res = find(indices[i].begin(), indices[i].end(), key);
//                        if(res != indices[i].end()) {
//                            l = *res;
//                            continue;
//                        }
//                    }

//                    key = r + slen;
//                    if(key < S.size()) {
//                        auto res = find(indices[i].begin(), indices[i].end(), key);
//                        if(res != indices[i].end()) {
//                            r = *res;
//                            continue;
//                        }
//                    }
//                }
//                if(i == n) {
//                    res.push_back(l);
//                }
//            }

//            return res;
//        }
//};

class Solution {
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            vector<int> res;

            unsigned wordNum = L.size();
            if(wordNum == 0) {
                return res;
            }
            unsigned wordSize = L[0].size();
            if(wordSize == 0) {
                return res;
            }
            unsigned slen = S.size();
            if(slen < wordSize*wordNum) {
                return res;
            }

            unordered_map<string, int> words;
            for(auto &word : L) {
                ++words[word];
            }

            unordered_map<string, int> count;
            for(unsigned i=0; i<=slen-wordSize*wordNum; ++i) {
                count.clear();
                unsigned j = 0;
                for(; j<wordNum; ++j) {
                    auto word = S.substr(i+j*wordSize, wordSize);
                    if(words.find(word) == words.end()) {
                        break;
                    }
                    if(++count[word] > words[word]) {
                        break;
                    }
                }
                if(j == wordNum) {
                    res.push_back(i);
                }
            }

            return res;
        }
};

int main(int argc, char const* argv[]) {
    Solution s;

    string str = "barfoothefoobarman";
    vector<string> L = {"foo", "bar"};
    vector<int> vec = s.findSubstring(str, L);
    cout << "0 9 == ";
    for_each(vec.begin(), vec.end(), [](int &val){cout<< val << " ";});
    cout << endl;

    str = "a";
    L = {"a", "a"};
    vec = s.findSubstring(str, L);
    cout << " == ";
    for_each(vec.begin(), vec.end(), [](int &val){cout<< val << " ";});
    cout << endl;

    str = "akjalsdkfjlsdkajflksdajflksdjflksdjflksdjflkjsdflkfjdsddddddfooookljsdlfkjsldkjfsjdfkljsdfkjsdflkjsadlfkjasdlkfjasldkjflasdjflksjsssssssssssssssfffffffffffffbarbarbarbarffffffffffffoobarlksjdflksdjflksdjflksjdbarfooakjalsdkfjlsdkajflksdajflksdjflksdjflksdjflkjsdflkfjdsddddddfooookljsdlfkjsldkjfsjdfkljsdfkjsdflkjsadlfkjasdlkfjasldkjflasdjflksjsssssssssssssssfffffffffffffbarbarbarbarffffffffffffoobarlksjdflksdjflksdjflksjdbarfooakjalsdkfjlsdkajflksdajflksdjflksdjflksdjflkjsdflkfjdsddddddfooookljsdlfkjsldkjfsjdfkljsdfkjsdflkjsadlfkjasdlkfjasldkjflasdjflksjsssssssssssssssfffffffffffffbarbarbarbarffffffffffffoobarlksjdflksdjflksdjflksjdbarfooakjalsdkfjlsdkajflksdajflksdjflksdjflksdjflkjsdflkfjdsddddddfooookljsdlfkjsldkjfsjdfkljsdfkjsdflkjsadlfkjasdlkfjasldkjflasdjflksjsssssssssssssssfffffffffffffbarbarbarbarffffffffffffoobarlksjdflksdjflksdjflksjdbarfoo";
    L = {"foo", "bar"};
    vec = s.findSubstring(str, L);
    cout << "... == ";
    for_each(vec.begin(), vec.end(), [](int &val){cout<< val << " ";});
    cout << endl;

    return 0;
}
