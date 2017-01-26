/* 
 * File:   Glove.cpp
 * Author: P0020049
 * 
 * Created on 25 stycznia 2017, 10:03
 */

#include "Glove.h"

Glove::Glove() {
}

Glove::Glove(const Glove& orig) {
}

Glove::~Glove() {
}

void Glove::read(char* filename)
{
    string line;
    int line_no = 0;
    ifstream myFile(filename);
    if(myFile.is_open())
    {
        
        while(getline(myFile, line))
        {
            int vec_begin = line.find_first_of(' ');
            dictionary[line.substr(0,vec_begin)] = line_no;
            word_vectors[line_no] = createVector(line.substr(vec_begin,line.length()));
            inverse_dictionary[line_no] = line.substr(0,vec_begin);
            line_no++;
        }
        myFile.close();
    }
    else
        throw exception();
}
