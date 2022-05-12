#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

struct Game
{
    int vertex_count;
    int point_count;
    double factor;
};

void run(struct Game game)
{
    FILE *file = fopen("game.csv", "w");

    double vertices[game.vertex_count][2];

    double x = 1.0;
    double y = 0.0;

    double vertex_x;
    double vertex_y;

    for (int i = 0; i < game.vertex_count; ++i)
    {
        double angle = 2 * PI * i / game.vertex_count;

        vertices[i][0] = cos(angle);
        vertices[i][1] = sin(angle);
    }

    for (int i = 0; i < game.point_count; ++i)
    {
        double random = (double) rand() / RAND_MAX;
        int random_vertex_index = (int) (random * game.vertex_count);

        vertex_x = vertices[random_vertex_index][0];
        vertex_y = vertices[random_vertex_index][1];

        x = (1 - game.factor) * x + game.factor * vertex_x;
        y = (1 - game.factor) * y + game.factor * vertex_y;

        fprintf(file, "%f,%f\n", x, y);
    }

    fclose(file);
}

int main()
{
    struct Game game = {3, 1000, 0.5};

    return 0;
}
