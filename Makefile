########################################
##
## Makefile
## LINUX compilation 
##
##############################################





#FLAGS
C++FLAG = -g -std=c++11 -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.





#Rule for .cpp files
# .SUFFIXES : .cpp.o 

.cpp.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@




#Including
INCLUDES=  -I. 


#LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#ZEROTH PROGRAM
ALL_OBJ0=TestBinPackingAlgorithms.o
PROGRAM_0=TestBinPackingAlgorithms
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

#ALL_OBJ1=TestBinPackingAlgorithms.o
#PROGRAM_1=SpellCheck
#$(PROGRAM_1): $(ALL_OBJ1)
#	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)


#run1linear: 	
		./$(PROGRAM_0) 5
		./$(PROGRAM_0) 50
		./$(PROGRAM_0) 100
		./$(PROGRAM_0) 500

#run1quadratic: 	
#		./$(PROGRAM_0) words.txt query_words.txt quadratic

#run1double: 	
#		./$(PROGRAM_0) words.txt query_words.txt double

#run2short: 	
#		./$(PROGRAM_1) document1_short.txt wordsEn.txt

#run2: 	
#		./$(PROGRAM_1) document1.txt wordsEn.txt



#Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0); rm -f $(PROGRAM_1))



(:
