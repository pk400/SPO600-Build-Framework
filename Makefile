all:	
	echo "Nothing to do"

install:
	mkdir -p ~/.m10k/
	mkdir -p ~/bin
	cp m10k_* ~/.m10k/ -v
	cp m10k ~/bin

test:	
	cd test-data; tar cvzf ../test-gzip.tgz .
	mkdir -p ~/.m10k/
	cp m10k_* ~/.m10k/ -v
	./m10k test-gzip.tgz

