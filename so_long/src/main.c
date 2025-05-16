#include "MLX42/MLX42.h"
#include <stdlib.h>

int main(void)
{
    mlx_t* mlx;
    
    mlx = mlx_init(800, 600, "so_long", true);
    if (!mlx)
        return (EXIT_FAILURE);

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
