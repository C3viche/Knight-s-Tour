CC = clang
FLAGS = -g -Wall -Werror

knights_tour_op.exe: knights_tour_op.o helper.o board.o input_validation.o
	$(CC) $(FLAGS) knights_tour_op.o helper.o board.o input_validation.o -o knights_tour_op.exe -fsanitize=address

knights_tour_op.o: knights_tour_op.c board.h helper.h input_validation.h
	$(CC) $(FLAGS) -c knights_tour_op.c

helper.o: helper.c helper.h board.h
	$(CC) $(FLAGS) -c helper.c

board.o: board.c board.h
	$(CC) $(FLAGS) -c board.c

input_validation.o: input_validation.c input_validation.h 
	$(CC) $(FLAGS) -c input_validation.c