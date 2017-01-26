/* 
 * File:   Glove.h
 * Author: P0020049
 *
 * Created on 25 stycznia 2017, 10:03
 */


#ifndef GLOVE_H
#define	GLOVE_H
#include "VectorSpace.h"
using namespace std;

class Glove : public VectorSpace{
public:
    Glove();
    Glove(const Glove& orig);
    virtual ~Glove();
    void read(char* filename);

private:

};

#endif	/* GLOVE_H */

