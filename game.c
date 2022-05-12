#include <stdio.h>
#include <math.h>

struct Point
{
    double x;
    double y;
}

struct Game
{
    int vertex_count;
    int point_count;
    double factor;
};

int main()
{
    struct Game game = {3, 1000, 0.5};

    return 0;
}
