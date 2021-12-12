#include "ft_base64.h"
#include "ft_arg_parse.h"

static char *read_from_file(char *filename)
{
    int fd;
    char *result;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("error : ", 2);
        ft_putendl_fd(strerror(errno), 2);
        exit(EXIT_FAILURE);
    }
    result = ft_readall(fd);
    close(fd);
    return result;
}

void handle_encoding(void)
{
    char *data = NULL;
    char *base64;

    if (args.i_opt_param)
        data = read_from_file(args.i_opt_param);
    else
        data = ft_readall(0);
    base64 = ft_base64_encode((byte_t*)data, ft_strlen(data));
    print_base64(base64);
    free(data);
    free(base64);
}
