LIBASM := libftasm.a

NASMFLAGS := -f macho64

ASMFILES :=   ft_strlen.s ft_strcpy.s ft_strdup.s ft_strcmp.s ft_read.s ft_write.s

ASMSRC := $(addprefix src/, $(ASMFILES))

NASMOBJ := $(ASMFILES:%.s=obj/%.o)

all: $(LIBASM)

$(LIBASM) : $(NASMOBJ)
	ar rcs $@ $^

obj/%.o: src/%.s
	@mkdir -p obj/
	nasm $(NASMFLAGS) $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -rf $(LIBASM)

re: fclean all

test:
	gcc -Wextra -Werror -Wall main.c -L. -lftasm && ./a.out

ll:
	gcc -Wextra -Werror -Wall -g main.c -L. -lftasm && lldb ./a.out
