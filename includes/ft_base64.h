#if !defined(FT_BASE64)
#define FT_BASE64

#include "ft_global.h"

#define BASE64_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define BASE64_PAD '='

data_t ft_base64_encode(byte_t *data, size_t size);
data_t ft_base64_decode(byte_t *data, size_t size);
data_t padd_and_map(byte_t *data, size_t size);
data_t base64_reverse_map(byte_t *data, size_t size);
data_t base64_clean_and_check(byte_t* data, size_t size);
void print_base64(data_t data, int fd);
void print_data(data_t result, int fd);
void init_base64map_list();

extern int8_t base64map_list[255];


#endif // FT_BASE64
