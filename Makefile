# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 08:58:38 by zbouhami          #+#    #+#              #
#    Updated: 2023/05/09 17:02:59 by zbouhami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker

CC			= @cc #-g -fsanitize=address
FLAGS		= -Wall -Wextra -Werror -g -O
REMOVE		= @rm -rf

#	________________________________________________________________________________
#		SOURCES FILE
PATH_SRC	= ./sources/
FILES_S		= call_instructions.c	instructions.c		list_operateur.c	main.c		tools.c 	free_stacks.c\
			  sort_small_stack.c	sort_small_2.c		optimize_sort.c		parsing.c	tools_2.c	libft.c\
			  sort_long_stack.c

SRC_FILE	= $(addprefix $(PATH_SRC), $(FILES_S))

#		OBJECTS FILE CREATION
PATH_OBJ	= ./build/
FILES_O		= $(FILES_S:.c=.o)
OBJ_FILE	= $(addprefix $(PATH_OBJ), $(FILES_O))

#		HEADER
HEADER		= ./sources/push_swap.h

#	________________________________________________________________________________
#		BONUS FILE
PATH_BNS	= ./checker_bonus/
BS_FILE		= call_instru.c	checker.c	instructions.c	libft_tool.c	list_generator.c \
			  parsing.c		tools.c 	free_stacks.c\
			  get_next_line/get_next_line.c	get_next_line/get_next_line_utils.c
BNS_SRC		= $(addprefix $(PATH_BNS), $(BS_FILE))

#		OBJECT BONUS FILE
PATH_OBNS	= ./bin/
O_FILE_B	= $(BS_FILE:.c=.o)
BNS_OBJ		= $(addprefix $(PATH_OBNS), $(O_FILE_B))

#		HEADER
HEAD		= checker.h get_next_line/get_next_line.h
HEADER_BNS	= $(addprefix $(PATH_BNS), $(HEAD))

#		GET_NEXT_LINE PATH
GNL_PATH	= $(PATH_OBNS)get_next_line/

#	________________________________________________________________________________
#		COMPILATION AND CIBLE PART

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	$(CC) $(FLAGS) $(OBJ_FILE) -o $(NAME)
	clear
	$(comp_msg)
	@echo "          $(White)▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄       ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄ "
	@echo "         ▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌     ▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░░░░░░░░░░░$(White)▌"
	@echo "         ▐$(BRed)░$(White)█▀▀▀▀▀▀▀█$(BRed)░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)█▀▀▀▀▀▀▀▀▀ ▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌     ▐$(BRed)░$(White)█▀▀▀▀▀▀▀▀▀ ▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)█▀▀▀▀▀▀▀█$(BRed)░$(White)▌▐$(BRed)░$(White)█▀▀▀▀▀▀▀█$(BRed)░$(White)▌"
	@echo "         ▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌          ▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌     ▐$(BRed)░$(White)▌          ▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌"
	@echo "         ▐$(BRed)░$(White)█▄▄▄▄▄▄▄█$(BRed)░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)█▄▄▄▄▄▄▄▄▄ ▐$(BRed)░$(White)█▄▄▄▄▄▄▄█$(BRed)░$(White)▌     ▐$(BRed)░$(White)█▄▄▄▄▄▄▄▄▄ ▐$(BRed)░$(White)▌   ▄   ▐$(BRed)░$(White)▌▐$(BRed)░$(White)█▄▄▄▄▄▄▄█$(BRed)░$(White)▌▐$(BRed)░$(White)█▄▄▄▄▄▄▄█$(BRed)░$(White)▌"
	@echo "         ▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░░░░░░░░░░░$(White)▌     ▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░$(White)▌  ▐$(BRed)░$(White)▌  ▐$(BRed)░$(White)▌▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░░░░░░░░░░░$(White)▌"
	@echo "         ▐$(BRed)░$(White)█▀▀▀▀▀▀▀▀▀ ▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌ ▀▀▀▀▀▀▀▀▀█$(BRed)░$(White)▌▐$(BRed)░$(White)█▀▀▀▀▀▀▀█$(BRed)░$(White)▌      ▀▀▀▀▀▀▀▀▀█$(BRed)░$(White)▌▐$(BRed)░$(White)▌ ▐$(BRed)░$(White)▌$(BRed)░$(White)▌ ▐$(BRed)░$(White)▌▐$(BRed)░$(White)█▀▀▀▀▀▀▀█$(BRed)░$(White)▌▐$(BRed)░$(White)█▀▀▀▀▀▀▀▀▀ "
	@echo "         ▐$(BRed)░$(White)▌          ▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌          ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌               ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌ ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌          "
	@echo "         ▐$(BRed)░$(White)▌          ▐$(BRed)░$(White)█▄▄▄▄▄▄▄█$(BRed)░$(White)▌ ▄▄▄▄▄▄▄▄▄█$(BRed)░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌      ▄▄▄▄▄▄▄▄▄█$(BRed)░$(White)▌▐$(BRed)░$(White)▌$(BRed)░$(White)▌   ▐$(BRed)░$(White)▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌          "
	@echo "         ▐$(BRed)░$(White)▌          ▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌     ▐$(BRed)░░░░░░░░░░░$(White)▌▐$(BRed)░░$(White)▌     ▐$(BRed)░░$(White)▌▐$(BRed)░$(White)▌       ▐$(BRed)░$(White)▌▐$(BRed)░$(White)▌          "
	@echo "          $(White)▀            ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀       ▀▀  ▀         ▀  ▀           "
	@echo "          $(BRed)42-login -> $(Bgreen)zbouhami                                                              $(BCyan)edited by $(White)@sinshi_zakaria "

$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(HEADER)
	@mkdir -p $(PATH_OBJ)
	$(CC) $(FLAGS) -c $< -o $@

#	________________________________________________________________________________
#		COMPILATION AND CIBLE BONUS PART

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(BNS_OBJ)
		$(CC) $(FLAGS) $(BNS_OBJ) -o $(NAME_BONUS)
		$(bcomp_msg)

$(PATH_OBNS)%.o : $(PATH_BNS)%.c $(HEADER_BNS)
		@mkdir -p $(PATH_OBNS)
		@mkdir -p $(GNL_PATH)
		$(CC) $(FLAGS) -c $< -o $@

#	________________________________________________________________________________
#		TOOLS
clean :
	$(REMOVE) $(PATH_OBJ)
	$(clean_msg)
	
fclean : clean
	$(REMOVE) $(NAME)
	$(fclean_msg)
	
re : fclean all

bclean :
	$(REMOVE) $(PATH_OBNS)
	$(bclean_msg)
	
bfclean : bclean
	$(REMOVE) $(NAME_BONUS)
	$(bfclean_msg)

full_clean : fclean bfclean

full : all bonus

bre : bfclean bonus

#	________________________________________________________________________________
#		TEST PUSH SWAP 5, 100, 500
ARGS = "11 3 -135 -365 426 -399 434 -283 41 50 449 -211 -405 -297 -41 25 -441 346 -238 410 -467 19 272 -480 435 374 -89 23 -380 144 495 -470 387 -48 102 70 485 194 -109 466 -395 -91 365 335 -260 -73 67 138 92 -296 418 -318 8 -317 -23 328 96 -414 -285 -412 -136 393 -439 367 353 262 -448 -442 308 202 191 302 -53 52 -449 -167 139 306 -13 456 -496 376 -188 -370 153 -197 -34 -145 146 124 -140 -346 460 259 137 1 -62 -8 370 193 -151 -400 450 -105 -218 163 -150 -116 369 -74 404 -459 321 14 88 -340 157 -411 -117 80 493 -7 37 38 482 390 -397 261 103 -402 264 150 -132 494 79 -153 131 -160 -436 -6 -344 -213 21 -469 -394 396 143 -127 279 -435 -118 471 240 -221 -181 -230 -299 283 -249 -310 -413 -325 -212 107 62 -312 -361 457 232 286 228 -319 -169 -437 -422 423 468 -314 -161 -322 248 420 -51 417 -391 89 -384 -338 2 15 -483 343 61 389 -134 260 -471 55 -179 -131 285 -396 -173 296 -356 -355 39 378 280 -477 -385 45 68 -130 -121 -327 338 409 278 -139 119 100 416 337 -26 453 118 275 375 -67 234 363 -274 253 401 120 203 187 71 -498 486 316 257 32 395 65 443 -115 -174 12 -292 312 424 -97 -16 -224 -79 -272 -85 295 -110 -215 -171 -82 243 159 -286 237 -176 448 246 -155 111 -163 54 -256 133 -164 430 -408 85 -332 -386 325 -445 498 318 -251 90 -33 -4 136 18 219 -371 313 463 -425 -375 431 -485 -473 -207 -168 77 247 -27 500 -28 -63 76 452 -128 152 245 340 -255 -39 -248 -410 348 175 250 -68 -488 -107 -198 160 183 -234 -481 358 -61 336 474 -452 -494 -202 -288 148 413 311 53 -123 24 411 238 412 481 -144 -177 -64 -194 300 -104 -231 -183 135 -60 273 351 -184 -191 225 -36 230 -99 -426 287 16 -175 184 214 371 -454 -239 -305 414 -315 236 -472 -379 181 -52 0 -357 263 82 289 66 -232 -154 274 392 -341 -227 366 298 -418 -219 -347 -339 -446 436 -253 -447 210 46 -205 198 -490 -37 470 -214 35 57 109 164 -186 484 -54 176 440 352 170 171 -241 -101 -189 169 195 -478 34 156 244 51 -429 -149 -196 211 -250 469 -165 206 288 190 180 174 -40 379 384 -80 -301 -201 -87 -270 -460 -277 -55 -50 199 73 -100 282 425 224 132 -170 22 166 406 69 451 -192 256 -86 -416 322 356 -367 -56 -166 -300 -407 142 -106 -32 447 -372 28 -302 487 -428 217 -83 268 -465 59 258 4"

full_re : re bre

test_arg :
		@./push_swap $(ARGS) | wc -l

visual :
		@./visualizer.py $(ARGS)

checker_os :
		@./push_swap $(ARGS) | ./checker_Mac $(ARGS)

my_checker :
		@./push_swap $(ARGS) | ./checker $(ARGS)
#	________________________________________________________________________________
#		MESSAGE DEFINE
comp_msg	= @echo "$(White)Push Swap $(BGreen)Compiled ✔️$(BRed)"
clean_msg	= @echo "$(BPurple)Clean done 🧽$(BRed)"
fclean_msg	= @echo "$(BCyan)fClean done 🧼$(BRed)"
#		MSG BNS
bcomp_msg	= @echo "$(White)checker $(BGreen)Compiled ✔️$(BRed)"
bclean_msg	= @echo "$(BPurple)Bonus Clean done 🧽$(BRed)"
bfclean_msg	= @echo "$(BCyan)Bonus Full Clean done 🧼$(BRed)"

#		COLOR DEFINE
BCyan		=	\x1b[1;33m
Bgreen		=	\x1b[1;32m
White		=	\x1b[1;31m
BPurple		=	\x1b[1;35m
BRed		=	\x1b[1;37m
