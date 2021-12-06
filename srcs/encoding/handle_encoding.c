#include "ft_base64.h"

void handle_encoding(void)
{
    char *data = ft_readall(0);
    char *base64 = ft_base64_encode(data, ft_strlen(data));
    print_base64(base64);
    free(data);
    free(base64);
}
