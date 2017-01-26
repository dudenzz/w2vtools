/* 
 * File:   VectorSpace.cpp
 * Author: P0020049
 * 
 * Created on 25 stycznia 2017, 13:32
 */

#include "VectorSpace.h"

VectorSpace::VectorSpace() {
}

VectorSpace::VectorSpace(const VectorSpace& orig) {
}

VectorSpace::~VectorSpace() {
}
int VectorSpace::getIndex(string word)
{
    return dictionary[word];
}
string VectorSpace::getWord(int index)
{
    return inverse_dictionary[index];
}
vector<double> VectorSpace::getVector(int index)
{
    return word_vectors[index];
}

vector<double> VectorSpace::createVector(string line)
{
    vector<double> data;
    string cur_val = "";
    for(int i = 0; i<line.length(); i++)
    {
        if(line[i] == ' ' || line[i] == '\t'|| line[i] == '\0')
        {
            double val = atof(cur_val.c_str());
            data.push_back(val);
            cur_val = "";
        }
        else
        {
            cur_val += line[i];
        }
    }
    double val = atof(cur_val.c_str());
    data.push_back(val);
    return data;
}

double VectorSpace::similarity(string w1, string w2)
{
    int i1 = getIndex(w1);
    int i2 = getIndex(w2);
    double mult = 0;
    double norm1 = 0;
    double norm2 = 0;
    vector<double> v1 = getVector(i1);
    vector<double> v2 = getVector(i2);
    double similarity = classifier->similarity(v1,v2);
    return similarity;
}



vector<tuple> VectorSpace::most_similar(vector<double> v, int n)
{
     vector<tuple> ms;
     double most_similar = 0;
     for(int i = 0; i<n; i++)
         ms.push_back(tuple());
     for(map<int, vector<double> >::iterator i = word_vectors.begin(); i!=word_vectors.end(); ++i)
     {
        double cos = classifier->similarity(v, i->second);
        if(cos <= ms[n-1].similarity)
        {
            tuple m;
            m.similarity = cos;
            m.word = getWord(i->first);
            ms.push_back(m);
            sort(ms.begin(),ms.end(), sorting_f);
            if(ms.size() > n)
                ms.erase(ms.begin() + n + 1);
        }
     }
     return ms;
}

vector<tuple> VectorSpace::most_similar(string word, int n)
{
    return most_similar(getVector(getIndex(word)),n);
}

void VectorSpace::setClassifier(SimilarityClassifier* s)
{
    classifier = s;
}
