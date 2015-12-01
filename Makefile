test:	
	cd test-data; tar cvzf ../test-gzip.tgz .
	mkdir -p ~/.m10k/
	cp m10k_* ~/.m10k/ -v
	./m10k test-gzip.tgz

