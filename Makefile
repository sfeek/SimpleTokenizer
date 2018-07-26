all:
	$(CC) -Wall -Werror test_tokenizer.c tokenizer.c -O2 -o test_tokenizer

clean:
	$(RM) -rf test_tokenizer
