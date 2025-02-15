#include <iostream>
#include <vector>

using namespace std;

vector<int> CreateSet(int size){
    auto retval = vector<int>(size);
    for(int x = 0; x < size; x++){
        retval[x] = x + 1;
    }
    return retval;
}

void print(vector<int>& src){
    cout << "miles" << '\t' << "Km" << '\n';
    for(auto x : src){
        cout << x <<'\t' << x * 1.6 <<'\n';
    }
}

int main(int argc, char** argv){
    if(argc <2){
        cerr << "Please Supply ceiling value for table\n";
        exit(EXIT_FAILURE);
    }

    int numRequired = atoi(argv[1]);

    auto src = move(CreateSet(numRequired));
    print(src);
    exit(EXIT_SUCCESS);
}
