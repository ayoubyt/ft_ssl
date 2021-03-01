NAME := ft_ssl

SRCS_DIR := srcs

BUILD_DIR := build

HEADERS_DIR := includes

SRCS := main.c \
		md5/md5.c

HEADERS = global.h md5.h


################## libft ################

LIBFT_DIR := libs/libft
LIBFT_BIN_DIR := build
LIBFT_HEADERS_DIR := includes
LIBFT_SUFF := ft

################## preprocessing #####################

OBJS := $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
OBJS_SUBDIRS := $(dir $(OBJS))

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
HEADERS := $(addprefix $(HEADERS_DIR)/, $(HEADERS))

LIBFT_HEADERS_DIR := $(LIBFT_DIR)/$(LIBFT_HEADERS_DIR)
LIBFT := $(LIBFT_DIR)/$(LIBFT_BIN_DIR)/lib$(LIBFT_SUFF).a

CC := gcc
CCFLAGS := -g

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BUILD_DIR)/%.o : $(SRCS_DIR)/%.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $< -o $@ $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS_SUBDIRS):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)


re: fclean all

re-all: re
	make re -C $(LIBFT_BIN_DIR)


# .PHONY : $(LIBFT)

.PHONY:
	all clean fclean
