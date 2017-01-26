/* 
 * File:   main.cpp
 * Author: P0020049
 *
 * Created on 25 stycznia 2017, 10:03
 */

#include<cstdlib>
#include<stdio.h>
#include "Glove.h"
#include "CosineSimilarityClassifier.h"
#include "EuclideanSimilarityClassifier.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Glove a;
    a.read("C:\\glove.6B\\glove.6B.50d.txt");
    CosineSimilarityClassifier* cosClass = new CosineSimilarityClassifier();
    a.setClassifier(cosClass);
    vector<tuple> similar_words = a.most_similar("camel",10);
    for(int i = 0; i<10; i++)
    {
        cout << similar_words[i].word << " : " << similar_words[i].similarity << endl;
    }
    cout << "------------------------------------------------------------------------\n";
    EuclideanSimilarityClassifier* eucClass = new EuclideanSimilarityClassifier();
    a.setClassifier(eucClass);
    vector<tuple> similar_words2 = a.most_similar("camel",10);
    for(int i = 0; i<10; i++)
    {
        cout << similar_words2[i].word << " : " << similar_words2[i].similarity << endl;
    }
    return 0;
}

