NAME := ft_ssl

SRCS_DIR := srcs

BUILD_DIR := build

HEADERS_DIR := includes

SRCS := main.c \

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

$(NAME) := $(BUILD_DIR)/$(NAME)


LIBFT_HEADERS_DIR := $(LIBFT_DIR)/$(LIBFT_HEADERS_DIR)
LIBFT := $(LIBFT_DIR)/$(LIBFT_BIN_DIR)/lib$(LIBFT_SUFF).a

CC := gcc
CCFLAGS := 

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT)

$(BUILD_DIR)/%.o : $(SRCS_DIR)/%.c $(HEADERS) | $(OBJS_SUBDIRS)
	gcc -c $< -o $@ $(CCFLAGS) -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS_SUBDIRS):
	mkdir -p $@

.PHONY : $(LIBFT)