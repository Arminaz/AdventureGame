#ifndef NULLPUZZLE_H
#define NULLPUZZLE_H

#include "Puzzle.h"

class NullPuzzle : public Puzzle
{
    public:
        NullPuzzle();

        bool doPuzzle();

    protected:

    private:
        void getHelp() const {};
};

#endif // NULLPUZZLE_H
