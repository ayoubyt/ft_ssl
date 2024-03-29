NAME := ft_ssl

SRCS_DIR := srcs

BUILD_DIR := build

HEADERS_DIR := includes

SRCS := main.c \
		ft_arg_parse.c \
		hash_handlers.c \
		utils.c \
		md5/ft_md5.c \
		md5/ft_md5_process.c \
		sha2/ft_sha256.c \
		sha2/ft_sha256_process.c



HEADERS = ft_global.h ft_md5.h


################## libft ################

LIBFT_DIR := libs/libft
LIBFT_BIN_DIR := build
LIBFT_HEADERS_DIR := includes
LIBFT_SUFF := ft

################## preprocessing #####################

OBJS := $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
OBJS_SUBDIRS := $(sort $(dir $(OBJS)))

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
HEADERS := $(addprefix $(HEADERS_DIR)/, $(HEADERS))

LIBFT_HEADERS_DIR := $(LIBFT_DIR)/$(LIBFT_HEADERS_DIR)
LIBFT := $(LIBFT_DIR)/$(LIBFT_BIN_DIR)/lib$(LIBFT_SUFF).a

CC := gcc
CCFLAGS := -O3 
CCLINKFLAGS =

# $(info $(SRCS_DIR) " :: " $(SRCS))
# $(info  $(BUILD_DIR) ":: " $(OBJS))

all : libft $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT) $(CCLINKFLAGS) -o $(NAME)

$(BUILD_DIR)/main.o : $(SRCS_DIR)/main.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $(SRCS_DIR)/main.c -o $(BUILD_DIR)/main.o $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)
$(BUILD_DIR)/ft_arg_parse.o : $(SRCS_DIR)/ft_arg_parse.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $(SRCS_DIR)/ft_arg_parse.c -o $(BUILD_DIR)/ft_arg_parse.o $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)
$(BUILD_DIR)/hash_handlers.o : $(SRCS_DIR)/hash_handlers.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $(SRCS_DIR)/hash_handlers.c -o $(BUILD_DIR)/hash_handlers.o $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)
$(BUILD_DIR)/utils.o : $(SRCS_DIR)/utils.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $(SRCS_DIR)/utils.c -o $(BUILD_DIR)/utils.o $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)
$(BUILD_DIR)/md5/ft_md5.o : $(SRCS_DIR)/md5/ft_md5.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $(SRCS_DIR)/md5/ft_md5.c -o $(BUILD_DIR)/md5/ft_md5.o $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)
$(BUILD_DIR)/md5/ft_md5_process.o : $(SRCS_DIR)/md5/ft_md5_process.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $(SRCS_DIR)/md5/ft_md5_process.c -o $(BUILD_DIR)/md5/ft_md5_process.o $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)
$(BUILD_DIR)/sha2/ft_sha256.o : $(SRCS_DIR)/sha2/ft_sha256.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $(SRCS_DIR)/sha2/ft_sha256.c -o $(BUILD_DIR)/sha2/ft_sha256.o $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)
$(BUILD_DIR)/sha2/ft_sha256_process.o : $(SRCS_DIR)/sha2/ft_sha256_process.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $(SRCS_DIR)/sha2/ft_sha256_process.c -o $(BUILD_DIR)/sha2/ft_sha256_process.o $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)

libft:
	make -C $(LIBFT_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS_SUBDIRS):
	mkdir -p $(OBJS_SUBDIRS)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)


re: fclean all

re-all: re
	make re -C $(LIBFT_BIN_DIR)

# .PHONY : $(LIBFT)

.PHONY:
	all clean fclean re-all libft 
