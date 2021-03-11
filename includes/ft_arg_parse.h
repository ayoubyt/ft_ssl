#ifndef FT_ARG_PARSE
#define FT_ARG_PARSE

# include "libft.h"

#define MD5CMD "md5"
#define SHA256CMD "sha256"


typedef unsigned char bool_t;

typedef enum
{
	MD5,
	SHA256
} command_t;

typedef struct
{
	command_t	cmd;
	bool_t	 	s_opt;
	char 		*s_opt_param;
	bool_t 		q_opt;
	bool_t 		p_opt;
	bool_t 		r_opt;
} args_t;

extern args_t args;

#endif
