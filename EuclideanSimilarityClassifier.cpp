/* 
 * File:   CosineSimilarityClassifier.cpp
 * Author: P0020049
 * 
 * Created on 25 stycznia 2017, 13:46
 */

#include "EuclideanSimilarityClassifier.h"

EuclideanSimilarityClassifier::EuclideanSimilarityClassifier() {
}

EuclideanSimilarityClassifier::EuclideanSimilarityClassifier(const EuclideanSimilarityClassifier& orig) {
}

EuclideanSimilarityClassifier::~EuclideanSimilarityClassifier() {
}

double EuclideanSimilarityClassifier::similarity(std::vector<double> v1, std::vector<double> v2)
{
    double sum_sq = 0;
    for(int i = 0; i<v1.size(); i++)
    {
        sum_sq += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
    double distance = sqrt(sum_sq);
    return distance;
}
