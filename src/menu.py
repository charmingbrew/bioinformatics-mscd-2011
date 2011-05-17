## @file setup.py

## @brief	sets up the correct flags

## @author	Tony Do,
#			Dane Elshof,
#			Jonathan Nicholson,
#			Dan Thode

## @date	11. May 2011
 
import PieAlign

## gets all the FASTA files in the file

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

def get_algorithm():
	algorithm_choice = 0
	
	while valid_algorithm(algorithm_choice) == False:
		algorithm_choice = raw_input("Choose desired alignment algorithm: (n) Needleman-Wunsch, (s) Smith-Waterman: ")
	return algorithm_choice.lower()

def valid_algorithm(algorithm_string):
	
	if algorithm_string == 'n' or algorithm_string == 'N':
		return True
	elif algorithm_string == 's' or algorithm_string == 'S':
		return True
	else:
		return False


##	The menu choices

while True:
	filedir = raw_input("Type the input files directory or \"quit\" to exit: ")
	
	if filedir != "quit":
		filelist = build_filelist("*.fasta", filedir)
		
		algorithm = 0 if get_algorithm() == 's' else 1
		
		results = filedir + "/results"
		#PieAlign.Align(filelist, len(filelist), algorithm, results)
		
	else:
		quit()
