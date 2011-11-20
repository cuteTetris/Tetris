#include "stone.h"

Stone::Stone()
{
    reset();
}

void Stone::reset(void){
    //Initialisieren
    for(int i=0;i<msize;i++){
        for(int j=0;j<msize;j++){
            mStone[i][j]=0;
        }
    }
}

Stone::~Stone(){
}

