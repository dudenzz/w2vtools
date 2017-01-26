/* 
 * File:   SimilarityClassifier.h
 * Author: P0020049
 *
 * Created on 25 stycznia 2017, 13:43
 */

#ifndef SIMILARITYCLASSIFIER_H
#define	SIMILARITYCLASSIFIER_H
#include"vector"


class SimilarityClassifier {
public:
    SimilarityClassifier();
    SimilarityClassifier(const SimilarityClassifier& orig);
    virtual ~SimilarityClassifier();
    virtual double similarity(std::vector<double>, std::vector<double>) = 0;
private:

};

#endif	/* SIMILARITYCLASSIFIER_H */

