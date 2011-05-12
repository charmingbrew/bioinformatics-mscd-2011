#!/usr/bin/env python
import PieAlign

choice = ""
AlignAlgor = ""
forward = False
Smith = 0
Needleman = 1
AlgorChoice = 0

def build_filelist(extension, path):
	import os
	import glob
	
	os.chdir(path)
	filelist = glob.glob(extension)
	cwd = os.getcwd()
	
	for f in filelist[:]:
		filelist.remove(f)
		filelist.insert(0, cwd + "/" + f)
		
	return filelist
	
def result_append(filename, path):
	return path + filename

while choice != "quit":
	print "Type \"input\" files or type \"quit\" to exit"
	print
	choice = raw_input("enter a choice: ")

	print "you've entered: ", choice
	print
	
	if choice != "quit":
		file1 = raw_input("Input file directory: ")
		filelist = build_filelist("*.fasta", file1)
	
		print
		print "you've entered: ", file1
		print
		print "contents: ", filelist
		print
		
		while forward != True:
			print "Enter desired algorithm: (\"S\" for: Smith Waterman) or (\"N\" for: Needleman Wunsch)"
			AlignAlgor = raw_input("Enter your choice: ")
			
			if AlignAlgor == "S" or AlignAlgor == "s":
				AlgorChoice = Smith
				
				print "you've entered: ", AlignAlgor
				print
				forward = True
			elif AlignAlgor == "N" or AlignAlgor == "n":
				AlgorChoice = Needleman
				
				print "you've entered: ", AlignAlgor
				print
				forward = True
			else:
				print
				print "Invalid Choice: enter a valid choice \"S\" or \"N\""
				print
		
		results = result_append("/results", file1)
		PieAlign.Align(filelist, len(filelist), AlgorChoice, results)
		
	else:
		print "...."
		print "Thanks for using me, please use me again."
		print
		quit()