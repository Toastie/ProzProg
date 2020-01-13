#ifndef __einfach_h__
#define __einfach_h__

struct einfach {
    int loesung[5][5];
    int spalten[3][5];
    int zeilen[5][3];

};

struct einfach einfach1 = {
    {{1,1,1,1,1},
     {1,0,0,0,0},
     {1,1,1,1,1},
     {0,0,0,0,1},
     {1,1,1,1,1}},

    {{0,1,1,1,0},
     {3,1,1,1,1},
     {1,1,1,1,3}},

    {{0,0,5},
     {0,0,1},
     {0,0,5},
     {0,0,1},
     {0,0,5}}
};


#endif
