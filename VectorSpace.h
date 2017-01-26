/* 
 * File:   VectorSpace.h
 * Author: P0020049
 *
 * Created on 25 stycznia 2017, 13:32
 */

#ifndef VECTORSPACE_H
#define	VECTORSPACE_H
#include<string>
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include <stdlib.h> 
#include<algorithm>
#include"SimilarityClassifier.h"
using namespace std;
struct tuple{
    double similarity;
    string word;
    tuple()
    {
        similarity = 100;
        word = "";
    }
};
class VectorSpace {
public:
    VectorSpace();
    VectorSpace(const VectorSpace& orig);
    virtual ~VectorSpace();
    virtual void read(char* filename) = 0;
    int getIndex(string word);
    string getWord(int word);
    vector<double> getVector(int index);
    double similarity(string w1, string w2);
    double similarity(vector<double> v1, vector<double> v2);
    vector<tuple> most_similar(string word, int n);
    void setClassifier(SimilarityClassifier* s);
    static bool sorting_f (tuple i,tuple j) { return (i.similarity<j.similarity); }
protected:
    map<string, int> dictionary;
    map<int, string> inverse_dictionary;
    map<int, vector<double> > word_vectors;
    vector<double> createVector(string line);
    vector<tuple> most_similar(vector<double>, int);
    SimilarityClassifier* classifier;
};

#endif	/* VECTORSPACE_H */

