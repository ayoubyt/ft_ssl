s = """
main.c \
ft_arg_parse.c \
hash_handlers.c \
utils.c \
md5/ft_md5.c \
md5/ft_md5_process.c \
sha2/ft_sha256.c \
sha2/ft_sha256_process.c"""

arr = s.split()
for f in arr:
    c = f
    o = c.replace(".c", ".o")
    c = "$(SRCS_DIR)/" + c
    o = "$(BUILD_DIR)/" + o
    print(f"{o} : {c} $(HEADERS) | $(OBJS_SUBDIRS)")
    print(f"\tgcc -c {c} -o {o} $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)")