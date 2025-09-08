#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SUCCESS = 0;
const int FAIL = -1;
const int FILE_OPEN_FAIL = 1;

int main(int argc, char** argv) {
    
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <file1> [<file2> ...]" << endl;
        return FAIL;
    }

    for (int i = 1; i < argc; ++i) {
        string filename = argv[i];
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Failed to open file '" << filename << "' for writing." << endl;
            return FILE_OPEN_FAIL;
        }

        file << "This is the output written to " << filename << "." << endl;
        file.close();
    }
   

    return SUCCESS;
}
