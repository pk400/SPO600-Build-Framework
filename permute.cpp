#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class CompilerOptions {
	vector<vector<string>> group;
	public:
		CompilerOptions() {}
		void add(vector<string> v);
		void permutation();
		void permuteOptions(int groupIdx);
		
		vector<vector<string>>& getGroups() { return group; }
};

void CompilerOptions::add(vector<string> v) {
	group.push_back(v);
}

void CompilerOptions::permutation() {

    //permuteOptions(0);


    for(int a = 0; a < group[0].size(); a++) {
        for(int b = 0; b < group[1].size(); b++) {
            for(int c = 0; c < group[2].size(); c++) {
                for(int d = 0; d < group[3].size(); d++) {
                    cout << group[0][a] << " " << group[1][b] << " " 
                        << group[2][c] << " " << group[3][d] << endl;
                }
            }
        }
    }
}

void CompilerOptions::permuteOptions(int groupIdx) {
    for(auto x : group[0]) {
        cout << x << endl;
    }
}

string removeSpaces(string s) {
	string newstr;
	for(auto x : s) {
		if(x != ' ')
			newstr.push_back(x);
	}
	
	return newstr;
}

int main(int argc, char** argv) {
	if(argc < 2) return 1; // error?
	
	CompilerOptions co;
	
	//-------------------------------------------------------------------------
	// Removes spaces from input and puts all compiler options inside a vector
	for(int i = 1; i < argc; i++) {
	    stringstream ss(removeSpaces(argv[i]));
	    char delimiter = '|';
	    vector<string> vtemp;
	    string temp;
	
	    while(getline(ss, temp, delimiter)) {
	        vtemp.push_back(temp);
	    }
	    
	    co.add(vtemp);
	}
	
	//-------------------------------------------------------------------------
	// Permute through each combination
	co.permutation();
	
	return 0;
}
