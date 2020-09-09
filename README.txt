COMP_SCI_4280
Project: P1
BT: MICHAEL SAGO
Language C++

This project is done in the C++ programming language. This program is a scanner
for provided lexical definitions. For testing purposesthe scanner will be
tested using a testing driver that I implemented in the file tst_scanner.cpp. I
have implemented and included my test files for this project.

P1.sp2020 - This file has one single character  

P1.test1.sp2020 - This file contains different sized character strings along 
						with different sized numbers and chararcter strings with
						digits included 

P1.test2.sp2020 - This file includes similar strings and numbers as test file 1 
						but also include different operators on same line. 

P1.test3.sp2020 - This file includes similar strings, numbers, operators, 
						and comments as test file 2 but also includes comments and
						keywords

P1.test4.sp2020 - This file has all the above but also has an error or illegal
						token that should be caught

//To compile the program:
		>make scanner
//Then you have two options to run the program:
		1.
      	>./scanner [filename]
			/* 
				Testing files are included and explained above 
			*/
		2.
      	>./scanner
/*
	If using option 2 you will then be able to enter diferent strings or
	integers of your choice. I use a simulated end of file so you 
	should enter either eof or EOF on a line by itself to end your input and
	the scanner will start going through that input and indicating tokens..
*/
