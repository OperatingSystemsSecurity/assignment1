CFLAGS += -shared -fpic

all: pam_random_questions install

clean:
	rm -f *.so

install: pam_random_questions.so
	sudo install -o root -g root $< /lib/security

uninstall:
	sudo rm -f /lib/security/pam_random_questions.so

%: %.c
	$(CC) $(CFLAGS) -o $@.so $<
