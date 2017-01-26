/* 
 * File:   CosineSimilarityClassifier.cpp
 * Author: P0020049
 * 
 * Created on 25 stycznia 2017, 13:46
 */

#include "CosineSimilarityClassifier.h"

CosineSimilarityClassifier::CosineSimilarityClassifier() {
}

CosineSimilarityClassifier::CosineSimilarityClassifier(const CosineSimilarityClassifier& orig) {
}

CosineSimilarityClassifier::~CosineSimilarityClassifier() {
}

double CosineSimilarityClassifier::similarity(std::vector<double> v1, std::vector<double> v2)
{
    double mult = 0;
    double norm1 = 0;
    double norm2 = 0;
    for(int i = 0; i<v1.size(); i++)
    {
        mult += v1[i]*v2[i];
        norm1 += v1[i]*v1[i];
        norm2 += v2[i]*v2[i];
                
    }
    norm1 = sqrt(norm1);
    norm2 = sqrt(norm2);
    double cosine = mult / (norm1*norm2);
    return 1-cosine;
}
