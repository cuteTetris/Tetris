#ifndef STONE_H
#define STONE_H

class Stone
{
public:
    Stone();
    ~Stone();
    virtual void rotate(void) = 0;
private:
    void reset(void);
public:
   static const int msize=4;
   int mStone[msize][msize];
};
#endif // STONE_H
