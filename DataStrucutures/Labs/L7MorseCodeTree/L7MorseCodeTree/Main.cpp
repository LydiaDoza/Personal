/***********************************************************
* Author:					Lydia Doza
* Date Created:				1/6/2015
* Last Modification Date:	3/6/2015
* Lab Number:				7
* Filename:					L7MorseCodeTree
*
* Overview:
*	Tests my Morse code tree. The codes representing each
*	letter is input from a file: morse.txt. Takes input from
*	a file to encode (in normal ascii character to morse
*	code) and a file to decode (from morse code to ascii).
*
* Input:
*	Morse key from "morse.txt"
*	message to encode from "message.txt"
*	message to decode from "lab 7 message.txt"
*
* Output:
*	The messages are printed as a "Before" and a "After"
*	decoding/encoding
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "Exception.h"
#include "MorseTree.h"

void PrimeTree(const string & file, MorseTree & tree);
void Display(ThreadBSTNode<char>*node);
vector<string> ReadEncoded(const string & file);
string ReadToEncode(const string & file);
string Decode(const vector<string> & msg, const MorseTree & tree);
void PrintMsg(const string & msg);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	MorseTree morseTree;
	string toEncode;
	vector<string> toDecode;
	string decoded;
	string encoded;

	PrimeTree("morse.txt", morseTree);

	morseTree.TravBreadth(Display);

	toDecode = ReadEncoded("lab 7 message.txt");
	decoded = Decode(toDecode, morseTree);
	PrintMsg(decoded);

	toEncode = ReadToEncode("ToEncode.txt");

	cout << "\n\nTo Encode: " << endl;
	PrintMsg(toEncode);

	encoded = morseTree.Encode(toEncode);
	PrintMsg(encoded);

	return 0;
}

/**********************************************************************
* Purpose:
* Entry: 	ThreadBSTNode<string>*node
* Exit:		void
************************************************************************/
void Display(ThreadBSTNode<char>*node)
{
	cout << node->GetData() << " ";
}

/**********************************************************************
* Purpose:	Fills Morse tree with characters from file.
* Entry: 	const string & file, ThreadBST<string> & tree
* Exit:		threaded tree is primed with the data from file.
************************************************************************/
void PrimeTree(const string & file, MorseTree & tree)
{
	ifstream primer(file.c_str());

	if (primer.is_open())
	{
		char letter;
		string morsecode;

		while (!primer.eof())
		{
			getline(primer, morsecode);
			letter = morsecode[0]; // first char is letter
			tree.Insert(letter, &morsecode[1]);
		}
		primer.close();
	}
}

/**********************************************************************
* Purpose:	Reads encoded Morse code message
* Entry: 	const string & file, MorseTree & tree
* Exit:		void
************************************************************************/
vector<string> ReadEncoded(const string & file)
{
	ifstream encoded(file.c_str());
	string letter = "";
	vector<string> msg;

	if (encoded.is_open())
	{
		while (!encoded.eof())
		{
			getline(encoded, letter, ' ');
			msg.push_back(letter);
		}
	}
	encoded.close();
	return msg;
}

/**********************************************************************
* Purpose:	reads message from file to encode to morse code.
* Entry: 	const string & file
* Exit:		string
************************************************************************/
string ReadToEncode(const string & file)
{
	ifstream toencode(file.c_str());
	string msg;

	if (toencode.is_open())
		getline(toencode, msg);

	// make all uppercase because morse tree only has upper case letters
	for (unsigned int i(0); i < msg.length(); i++)
		msg[i] = toupper(msg[i]);

	return msg;
}

/**********************************************************************
* Purpose:
* Entry: 	vector<string> & msg, const MorseTree & tree
* Exit:		void
************************************************************************/
string Decode(const vector<string> & msg, const MorseTree & tree)
{
	string decoded;

	for (unsigned int i(0); i < msg.size(); i++)
		decoded.append(tree.Decode(msg[i]));

	return decoded;
}

/**********************************************************************
* Purpose:	prints msg
* Entry: 	const string & msg
* Exit:		void
************************************************************************/
void PrintMsg(const string & msg)
{
	cout << msg << endl;
}