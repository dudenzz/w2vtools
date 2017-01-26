/* 
 * File:   CosineSimilarityClassifier.h
 * Author: P0020049
 *
 * Created on 25 stycznia 2017, 13:46
 */

#ifndef COSINESIMILARITYCLASSIFIER_H
#define	COSINESIMILARITYCLASSIFIER_H
#include "SimilarityClassifier.h"
#include <math.h>
class CosineSimilarityClassifier : public SimilarityClassifier{
public:
    CosineSimilarityClassifier();
    CosineSimilarityClassifier(const CosineSimilarityClassifier& orig);
    virtual ~CosineSimilarityClassifier();
    double similarity(std::vector<double>, std::vector<double>);
private:

};

#endif	/* COSINESIMILARITYCLASSIFIER_H */

