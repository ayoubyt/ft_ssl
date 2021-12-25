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
    data_t input = {0, 0};
    data_t result;

    if (args.i_opt_param)
        input = read_from_file(args.i_opt_param);
    else
        input = ft_readall_raw(0);

    if (!args.d_opt)
        result = ft_base64_encode(input.content, input.size);
    else
        result = ft_base64_decode(input.content, input.size);
    if (args.o_opt_param)
    {
        int fd = open(args.o_opt_param, O_WRONLY | O_CREAT, 0555);
        if (fd < 0)
        {
            ft_putstr_fd("error : ", 2);
            ft_putendl_fd(strerror(errno), 2);
            exit(EXIT_FAILURE);
        }
        args.d_opt ? print_data(result, fd) : print_base64(result, fd);
    }
    else
        args.d_opt ? print_data(result, 1) : print_base64(result, 1);
    free(input.content);
    free(result.content);
}
