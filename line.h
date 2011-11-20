#ifndef LINE_H
#define LINE_H


#include "stone.h"

class line : public Stone
{
public:

    line(): Stone(){
        mStone[1][0]=1;
        mStone[1][0]=1;
        mStone[1][0]=1;
        mStone[1][0]=1;
    }
    void rotate(void);
};
#endif // LINE_H
