#include "ft_base64.h"
#include "ft_arg_parse.h"

static data_t read_from_file(char *filename)
{
    int fd;
    data_t result;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("error : ", 2);
        ft_putendl_fd(strerror(errno), 2);
        exit(EXIT_FAILURE);
    }
    result = ft_readall_raw(fd);
    close(fd);
    return result;
}

void handle_encoding(void)
{
    data_t data = {0, 0};
    char *base64;

    if (args.i_opt_param)
        data = read_from_file(args.i_opt_param);
    else
        data = ft_readall_raw(0);
    base64 = ft_base64_encode(data.content, data.size);
    if (args.o_opt_param)
    {
        int fd = open(args.o_opt_param, O_WRONLY | O_CREAT, 0555);
        if (fd < 0)
        {
            ft_putstr_fd("error : ", 2);
            ft_putendl_fd(strerror(errno), 2);
            exit(EXIT_FAILURE);
        }
         print_base64(base64, fd);
    }
    else
        print_base64(base64, 1);
    free(data.content);
    free(base64);
}
