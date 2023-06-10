#include <iostream>
#include <bits/stdc++.h>
#include <string>
using  namespace std;
void swap(string &a, string&b) {
    string temp = a;
    a = b;
    b = temp;
}

void generator(vector <string>& permSet, int index, string seq, string inp) {
    if(index >= inp.length()){
        permSet.push_back(seq);
        return;
    }
    for (int j = index; j <inp.length(); j++) {
        swap(inp[index], inp[j]);
        generator(permSet, index+1, seq+inp[index], inp);
        swap(inp[index], inp[j]);
    }
}
vector <string> stringPermutation(string inp) {
    vector <string> permutationSet;
    int index = 0;
    string sequence = "";
    generator(permutationSet, index, sequence, inp);
    return permutationSet;
}
int main () {
    string input;
    getline(cin, input);
    vector<string> answer = stringPermutation(input);
    for (auto i: answer) {
        std :: cout << i << ' ';
    }
}

