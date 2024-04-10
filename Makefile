# This is a minimal set of ANSI/VT100 color codes
END			=	\e[0m
BOLD		=	\e[1m
UNDER		=	\e[4m
REV			=	\e[7m

# Colors

DEF_COLOR 	= 	\033[0;39m
GRAY 		= 	\033[0;90m
GREY_01		=	\033[30m
RED 		= 	\033[0;91m
RED_01		=	\033[31m
GREEN 		= 	\033[0;92m
GREEN_01	=	\033[32m
YELLOW 		= 	\033[0;93m
YELLOW_01	=	\033[33m
BLUE 		= 	\033[0;94m
BLUE_01		=	\033[34m
PURPLE		=	\033[35m
MAGENTA 	= 	\033[0;95m
CYAN 		= 	\033[0;96m
CYAN_01		=	\033[36m
WHITE 		= 	\033[0;97m
WHITE_01	=	\033[37m

# Inverted, i.e. colored backgrounds
IGREY		=	\e[40m
IRED		=	\e[41m
IGREEN		=	\e[42m
IYELLOW		=	\e[43m
IBLUE		=	\e[44m
IPURPLE		=	\e[45m
ICYAN		=	\e[46m
IWHITE		=	\e[47m

# **************************************************************************** #

#Variables‹

NAME			= minishell
INCLUDE			= include/
LIBFT			= libft
SRC_DIR			= src/
CONSOLE_DIR		= console/
PIPEX_DIR		= pipex/
ENVP_LIST_DIR	= envp_list/
PARSER_DIR		= parser/
EXPANSION_DIR	= parser/expansion/
CMD_DIR			= parser/cmd/
FREE_DIR		= free/
SIGS_DIR		= signals/
OBJ_DIR			= obj/
CC				= gcc
HEADER			= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include
CFLAGS			=  -Wall -Werror -Wextra -g3 -I
RM				= rm -f
AR				= ar rcs

# =========================================================================== #


#Sources

SRC_FILES	=	main init_data
CONSOLE 	=	console_init
ENVP_LIST	=	envp_list_manage
SIGNALS		=	signals_handler
PARSER		=	handlers token_init parser_utils cmd_init
EXPANSION	=	expansion utils
CMD			=	cmd_init cmd_fill utils
FREE		=	free_lsts
PIPEX 		=	ft_pipex



SRC_FILES+=$(addprefix $(ENVP_LIST_DIR),$(ENVP_LIST))
SRC_FILES+=$(addprefix $(CONSOLE_DIR),$(CONSOLE))
SRC_FILES+=$(addprefix $(SIGS_DIR),$(SIGNALS))
SRC_FILES+=$(addprefix $(PARSER_DIR),$(PARSER))
SRC_FILES+=$(addprefix $(EXPANSION_DIR),$(EXPANSION))
SRC_FILES+=$(addprefix $(CMD_DIR),$(CMD))
SRC_FILES+=$(addprefix $(FREE_DIR),$(FREE))
SRC_FILES+=$(addprefix $(PIPEX_DIR),$(PIPEX))

# Files 

SRCS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(CC) $(OBJS) -o $(NAME) $(LIBFT)/libft.a $(HEADER) 
			@echo "$(GREEN)MiniShell compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(ENVP_LIST_DIR)
			@mkdir -p $(OBJ_DIR)$(CONSOLE_DIR)
			@mkdir -p $(OBJ_DIR)$(PIPEX_DIR)
			@mkdir -p $(OBJ_DIR)$(SIGS_DIR)
			@mkdir -p $(OBJ_DIR)$(PARSER_DIR)
			@mkdir -p $(OBJ_DIR)$(EXPANSION_DIR)
			@mkdir -p $(OBJ_DIR)$(FREE_DIR)

# Rules

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf utils/
			@make clean -C $(LIBFT)
			@echo "$(BLUE)MiniShell object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME2)
			@$(RM) -f $(NAME_TEST)
			@$(RM) -f $(NAME_DEBUG)
			@$(RM) -f $(LIBFT)/libft.a
			@$(RM) -f $(TEST_DIR)/libft.a
			@$(RM) -f libft.a
			@echo "$(CYAN)MiniShell executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(YELLOW)MiniShell recompiled!$(DEF_COLOR)"	
			@echo ""	
			@echo "$(BLUE)@@@@@@@@@@   $(YELLOW)@@@  $(GREEN)@@@  @@@  $(PURPLE)@@@  $(CYAN) @@@@@@   $(RED)@@@  @@@  @@@@@@@@  @@@       @@@$(DEF_COLOR)"
			@echo "$(BLUE)@@@@@@@@@@@  $(YELLOW)@@@  $(GREEN)@@@@ @@@  $(PURPLE)@@@  $(CYAN)@@@@@@@   $(RED)@@@  @@@  @@@@@@@@  @@@       @@@$(DEF_COLOR)"
			@echo "$(BLUE)@@! @@! @@!  $(YELLOW)@@!  $(GREEN)@@!@!@@@  $(PURPLE)@@!  $(CYAN)!@@       $(RED)@@!  @@@  @@!       @@!       @@!$(DEF_COLOR)"
			@echo "$(BLUE)!@! !@! !@!  $(YELLOW)!@!  $(GREEN)!@!!@!@!  $(PURPLE)!@!  $(CYAN)!@!       $(RED)!@!  @!@  !@!       !@!       !@!$(DEF_COLOR)"
			@echo "$(BLUE)@!! !!@ @!@  $(YELLOW)!!@  $(GREEN)@!@ !!@!  $(PURPLE)!!@  $(CYAN)!!@@!!    $(RED)@!@!@!@!  @!!!:!    @!!       @!!$(DEF_COLOR)"
			@echo "$(BLUE)!@!   ! !@!  $(YELLOW)!!!  $(GREEN)!@!  !!!  $(PURPLE)!!!  $(CYAN) !!@!!!   $(RED)!!!@!!!!  !!!!!:    !!!       !!!$(DEF_COLOR)"
			@echo "$(BLUE)!!:     !!:  $(YELLOW)!!:  $(GREEN)!!:  !!!  $(PURPLE)!!:  $(CYAN)     !:!  $(RED)!!:  !!!  !!:       !!:       !!:$(DEF_COLOR)"
			@echo "$(BLUE):!:     :!:  $(YELLOW):!:  $(GREEN):!:  !:!  $(PURPLE):!:  $(CYAN)    !:!   $(RED):!:  !:!  :!:        :!:       :!:$(DEF_COLOR)"
			@echo "$(BLUE):::     ::   $(YELLOW) ::  $(GREEN) ::   ::  $(PURPLE) ::  $(CYAN):::: ::   $(RED)::   :::   :: ::::   :: ::::   :: ::::$(DEF_COLOR)"
			@echo "$(BLUE) :      :    $(YELLOW):    $(GREEN)::    :   $(PURPLE):    $(CYAN):: : :    $(RED) :   : :  : :: ::   : :: : :  : :: : :$(DEF_COLOR)"
			@echo ""	

git:
			@git add .
			@git commit -m "Makefile auto commit"
			@git push

push_to_juan:
			@git add .
			@git commit -m "Makefile auto commit"
			

.PHONY:		all clean fclean re git
