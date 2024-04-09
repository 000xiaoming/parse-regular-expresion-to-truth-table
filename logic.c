#include "logic.h"


int and_(int x1, int x2)
{
    return (x1 && x2);
}

int or_(int x1, int x2)
{
    return (x1 || x2);
}
int not_(int x1, int x2)
{
    x1 = 1;
    return (!x2 && x1) || (x2 && !x1) ;
}
int con_opr(int x1, int x2)//conditional operation
{
    if ( (x1 != 0) && (x2 == 0) )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int same_or(int x1, int x2)
{
    return ( (x1 && x2) || (!x1 && !x2) );
}

