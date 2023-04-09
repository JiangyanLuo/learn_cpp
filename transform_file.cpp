#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cout;


int main() {
    std::string file_name {"items.txt"};

    //create an input file stream object
    std::ifstream input_file(file_name); // RAII

    //check if the file was opened successfuly
    if(input_file.is_open()) {
        char delimiter = '\t';
        std::string line;

        //read the file line by line
        while(std::getline(input_file,line)) {
            //create a string stream from the line
            std::istringstream ss(line);

            //declare 3 variables to hold each part
            std::string part1, part2, part3;

            //read each part seperated by tabs
            std::getline(ss,part1,delimiter);
            std::getline(ss,part2,delimiter);
            std::getline(ss,part3,delimiter);

            //print out
            cout <<"sku: " << part1 <<", name: " << part2 << ", desc: " << part3 << '\n';

        }

    } else {
        cout << "Unable to open " << file_name << '\n';
    }
    
    return 0;
}