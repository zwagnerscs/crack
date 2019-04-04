# -*- indent-tabs-mode:t; -*-

# This rule links hashpass.o and md5.o along with the
# libssl and libcrypto libraries to make the executable.
hashpass: hashpass.o md5.o
	clang hashpass.o md5.o -o hashpass -l crypto

# Add recipe to compile md5.o from md5.c below,
# indented with a tab.
md5.o: md5.c
	clang -c -g -Wall md5.c

# Add recipe to compile hashpass.o from hashpass.c below,
# indented with a tab.
hashpass.o: hashpass.c
	clang -c -g -Wall hashpass.c

hashes: hashpass
	./hashpass rockyou100.txt hashes.txt

wordhashes: hashpass
	./hashpass words.txt wordhashes.txt

check: hashpass
	valgrind ./hashpass rockyou100.txt hashes.txt

clean:
	rm -f *.o hashpass hashes.txt
