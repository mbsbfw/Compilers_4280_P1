#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <sstream>
#include "scanner.h"
#include "tst_scanner.h"
#include "token.h"

using namespace std;

int line_pos;

//Driver program
int scanner(string &inout, Token &get_token){

    int state = 0;
    int nxt_state = 0;
    int nxt_char = -1;
    char ch, c2;
    string tok_str;

    get_token.line_number = line;

	cout << "line pos = " << line_pos << endl;	
    while(line_pos <= inout.length()){

        if (line_pos < inout.length()){
            ch = inout.at(line_pos);
        		if(line_pos < inout.length() - 1)
                c2 = inout.at(line_pos + 1);
					 //cout << "c2 = " << c2 << endl;
        }

		  if(line_pos == inout.length()){
				if(isalpha(ch) || isdigit(ch) || valid_operators(ch, c2)){
					ch = ' ';
				}else
					return -1;
		  }

		  //cout << "ch = " << ch << endl;
       	if(isalpha(ch) && isupper(ch)) {        //uppercase
           	nxt_char = 0;
        	}else if(isalpha(ch) && islower(ch)) {  //lowercase
            nxt_char = 1;
        	}else if(isdigit(ch)){                  //digit
            nxt_char = 2;
        	}else if(isspace(ch)){                  //space
            nxt_char = 3;
        	}else if(valid_operators(ch, c2)){      //operator
            nxt_char = 4;
        	}
        	else{
         	return -1;
        	}
	     
        nxt_state = FSA_table[state][nxt_char];

        int check = final_states(get_token, nxt_state, tok_str);

        state = check;

        if(check == 0){
            line_pos++;
            return 0;
        }

        if(nxt_state > final_S){
            tok_str = "";
        }

        if(!isspace(ch)){
            tok_str.push_back(ch);
            //cout << tok_str << endl;
        }

        line_pos++;
    }//end while


    return -1;
}

int valid_operators(char c1, char c2){

    //Convert char to string to check if valid operator
    string s = "";
    s = s + c1;

    if(c1 == ':' && c2 == '='){
		  //cout << "valid operator" << endl;
        return 1;
    }else if(c1 == '=' && c2 == '='){
        return 1;
    }

    for (int iter = 0; iter < 20; iter++){

        if(s == operators[iter]){
            //cout << "valid operator" << endl;
            return 1;
        }

    }//end for

  //Return 0 to indicate that the input character is not an operator.
  return 0;
}

int valid_keyword(string tok_str){
	
    for (int iter = 0; iter < 13; iter++){

        if(tok_str == keywords[iter]){
            //cout << "valid keywords" << endl;
            return 1;
        }
    }//end for
	  
	  return 0;
}

int final_states(Token &get_token, int nxt_state, string tok_str){

    if(nxt_state < 0){
        //print error message
        cout << "+*+*+SCANNER ERROR: Line #" << get_token.line_number <<  endl;
        cout << "Suggestion: Integers must be followed only by Integers" << endl;
        exit (10);
    }else if(nxt_state > final_S){
			
        switch(nxt_state){

            case IDENT_final_S:

                if(valid_keyword(tok_str) == 1){

                    get_token.ID = KEYW_tk;
                    get_token.tok_string = token_names[KEYW_tk];
                    get_token.tok_string.append(" " + tok_str);
                }else{
	
                    get_token.ID = ID_tk;
                    get_token.tok_string = token_names[ID_tk];
                    get_token.tok_string.append(" " + tok_str);
                }
                //cout << get_token.tok_string << endl;
                break;

            case INT_final_S:
                get_token.ID = INT_tk;
                get_token.tok_string = token_names[INT_tk];
                get_token.tok_string.append(" " + tok_str);
                //cout << get_token.tok_string << endl;
                break;

            case OPER_final_S:
                get_token.ID = OP_tk;
                get_token.tok_string = token_names[OP_tk];
                get_token.tok_string.append(" " + tok_str);
                //cout << get_token.tok_string << endl;
                break;
        }//end switch

        return 0;
    }//end else if


    return nxt_state;
}
