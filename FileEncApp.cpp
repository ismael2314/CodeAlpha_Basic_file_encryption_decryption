#include <Windows.h>
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;

string cipher(string);
string decipher(string);
int key=0;
int main(int argc, char* argv[]){

	string fline="";
	
	char path[10000]="";
	char output[10000]="";
	
	cout<<"Don\'t use space when providing the path!"<<endl;
	cout<<"Path > ";cin>>path;
	cout<<"Key  > ";cin>>key;
	cout <<"1. Cipher\n2. Decipher"<<endl;
	fstream File(path);
	int num;
	cout<<"Choose > ";
	cin>>num;
	switch(num){
		case 1:
			while(getline(File,fline))
				{
					cout<<cipher(fline)<<endl;
				}
			break;
		case 2:
			while(getline(File,fline))
				{
					cout<<decipher(fline)<<endl;
				}
			break;
		default:
			cout<< "Quitting..."<<endl;
	}	
	File.close();
	return 0;	
}
// @ cipher Data
string cipher(string value){
	char smalls='a',smalle='z'; // small letter starting point
	char capitals='A',capitale='Z'; //  capital letter starting point
	
	char output[1000]="";
	for(int i=0,j=value.length()-1;i<value.length();i++,--j){
		

		if(value[i]>=smalls &&value[i]<=smalle ){
		    output[i] = static_cast<char>(((value[i]+key-smalls)%26)+smalls);			
		}else if(value[i]>=capitals &&value[i]<=capitale ){
			output[i] = static_cast<char>(((value[i]+key-capitals)%26)+capitals);
		}else{
			output[i] = static_cast<char>(value[i]);
		}	
	}

	return output;
}

string decipher(string value){
  	// function to decipher the ciphered data
  	
	char smalls='a',smalle='z'; // small letter starting point
	char capitals='A',capitale='Z'; //  capital letter starting point
	
	char output[1000]="";
	for(int i=0,j=value.length()-1;i<value.length();i++,--j){
		
		if(value[i]>=smalls &&value[i]<=smalle ){
			
			if((((value[i]-smalls)%26-key)+smalls)<smalls){
				output[i] = static_cast<char>(((value[i]-smalls)%26-key)+smalls+26);	
			}else{
				output[i] = static_cast<char>(((value[i]-smalls)%26-key)+smalls);
			}			
		}else if(value[i]>=capitals &&value[i]<=capitale ){
			
			if((((value[i]-capitals)%26-key)+capitals)<capitals){
				output[i] = static_cast<char>(((value[i]-capitals)%26-key)+capitals+26);	
			}else{
				output[i] = static_cast<char>(((value[i]-capitals)%26-key)+capitals);
			}
			
		}else{
			output[i] = static_cast<char>(value[i]);
		}
		
	}

	return output;
}
