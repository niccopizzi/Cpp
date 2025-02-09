CPPFLAGS = -std=c++98

NAME = phonebook

SRC =	./main.cpp		\
		./Contact.cpp	\
		./PhoneBook.cpp	


all : $(NAME)

$(NAME) : 
	c++ $(CPPFLAGS) -o $(NAME) $(SRC)

clean :
	rm $(NAME)

re	: clean all

