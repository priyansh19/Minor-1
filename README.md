# :memo: Minor 1 (August 2019 - November 2019)

## Problem Statement :

Nowadays, In the real world the threat of attacks on your data or information is growing very rigourously. So to protect your information we need some special kind of encryption technique which has very less isk of getting exploited.

## :rainbow: Solution :

We have implemented a encryption/decryption system for files using c language by implementing the Huffman Algorithm over a secure channel using Socket Programming in C language.

## About the Code : 
This is the main (integrated) code for the entire repo.
The user is required to enter the option to choose amongst Data Security, Data Transfer or Help!
Now if the user chooses Data Security- 
The user can choose among : 1) Text Data or 2) Image Data
If the user chooses 1) Text Data:- YOU HAVE TO ENTER THE DATA TO BE PROCESSED
If the user chooses the 2) Image Data:- YOU HAVE TO ENTER THE PATH OF THE IMAGE
The data is then compressed, encrypted and stored in the file. This file has to be transfered using Socket programming
So the user now has to run the program again and choose option - (2) Data Transfer

**REMOVE THE COMMENTS FROM THE HEADER FILE AND THE CASE SWITCH WHERE SOCKET CODE IS WRITTEN**

Now, enter the port and IP where data has to be sent, (the reciever must have client code running)
the reciever(client) needs to enter the filename to be recieved. 
The data has to be then decrypted and decompressed. 



