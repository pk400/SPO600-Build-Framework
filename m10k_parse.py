# Parse a csv file
import csv
import sys
filename = "monkeys10k.config"

try:
	# Open file
	f = open(filename, 'r')
except IOError:
	print "Can't open", filename
	sys.exit(1)
else:
	# Read file, delimited by '|'
	reader = csv.reader(f, delimiter="|")
	
	# Output
	for row in reader:
		print row

	f.close()
	sys.exit(0)
