/* 
 * File:   CosineSimilarityClassifier.h
 * Author: P0020049
 *
 * Created on 25 stycznia 2017, 13:46
 */

#ifndef EUCLIDEANIMILARITYCLASSIFIER_H
#define	EUCLIDEANIMILARITYCLASSIFIER_H
#include "SimilarityClassifier.h"
#include <math.h>
class EuclideanSimilarityClassifier : public SimilarityClassifier{
public:
    EuclideanSimilarityClassifier();
    EuclideanSimilarityClassifier(const EuclideanSimilarityClassifier& orig);
    virtual ~EuclideanSimilarityClassifier();
    double similarity(std::vector<double>, std::vector<double>);
private:

};

#endif	/* EUCLIDEANIMILARITYCLASSIFIER_H */

