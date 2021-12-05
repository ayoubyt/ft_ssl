#if !defined(FT_BASE64)
#define FT_BASE64

#include "ft_global.h"

#define BASE64_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define BASE64_PAD '='

char *padd_and_map(byte_t *data, size_t size);
char *ft_base64_encode(byte_t *data, size_t size);

#endif // FT_BASE64
