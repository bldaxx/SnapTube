#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

// create a variant type called UserList that can hold a string, int, double, or bool
using UserList = variant <string, int, double, bool>;


// create a main function
int main() {

	// create variables to hold the name, email, and password of the user
	string name, email, password, videoURL, choice, command;

	vector<string> order = { "Name", "Email", "Password" };

	map<string, UserList> userProfile;

	string desktop = getenv("USERPROFILE");
	desktop += "/Desktop/";


	cout << endl << "****************************************************************************************************" << endl;

	cout << "** Checking for yt-dlp updates... Please wait." << endl;

	string updateCommand = "yt-dlp.exe -U";
	system(updateCommand.c_str());

	cout << "** Update check complete." << endl;

	cout << "****************************************************************************************************" << endl;

	cout << "** Enter Video URL: ";
	getline(cin, videoURL);

	cout << "** Choose format: [1] Video (MP4) | [2] Audio (MP3): ";
	getline(cin, choice);

	string outputFolder = "-o \"" + desktop + "%(title)s.%(ext)s\" ";

	if (choice == "2") {
		command = "yt-dlp.exe -c " + outputFolder + "-x --audio-format mp3 " + videoURL;
		cout << "** Processing Audio into 'Desktop'... Please wait." << endl;
	}
	else {
		command = "yt-dlp.exe --no-warnings --quiet --progress -c " + outputFolder + " -f \"bv[ext=mp4]+ba[ext=m4a]/b[ext=mp4]/best\" --merge-output-format mp4 " + videoURL;
		cout << "** Processing Video with Audio (High Quality)... Please wait." << endl;
		cout << "** Processing Video into 'Desktop'... Please wait." << endl;
	}

	int result = system(command.c_str());

	if (result == 0) {
		cout << endl << "** Video downloaded successfully!" << endl;
	}
	else {
		cout << endl << "** Error: Please make sure yt-dlp.exe is in the same folder." << endl;
	}

	cout << "****************************************************************************************************" << endl;

	// print stars & organization name
	cout << "****************************************************************************************************" << endl;
	cout << "************************************** HACKLORE ORGANIZATION *************************************** " << endl;
	cout << "****************************************************************************************************" << endl << endl;

	// create a loop to read the name of the user until a valid name is entered
	while (true) {
		// create input with 'cout' & getline to read the name of the user
		cout << "** Put your name: ";
		getline(cin, name);

		if (name.empty()) {
			cout << "** Name cannot be empty. Please try again." << endl;
		} else {
			// print stars
			cout << endl << "****************************************************************************************************" << endl << endl;
			break; // exit the loop if a valid name is entered
		}
	}


	while (true) {
		// create input with 'cout' & getline to read the email of the user
		cout << "** Put your email: ";
		getline(cin, email);

		if (email.empty()) {
			cout << "** Email cannot be empty. Please try again." << endl;
		}
		else {
			if (email.find('@') == string::npos || email.find('.') == string::npos) {
				cout << "** Email must contain '@' and '.' characters. Please try again." << endl;
			}
			else {
				// print stars
				cout << endl << "****************************************************************************************************" << endl << endl;
				break; // exit the loop if a valid email is entered
			}
		}
	}


	// create a loop to read the password of the user until a valid password is entered
	while (true) {
		// create input with 'cout' & getline to read the password of the user
		cout << "** Put your password: ";
		getline(cin, password);

		if (password.empty()) {
			cout << "** Password cannot be empty. Please try again." << endl;
		}
		else {
			if (password.length() < 8) {
				cout << "** Password must be at least 8 characters long. Please try again." << endl;
			}
			else {
				// print stars
				cout << endl << "****************************************************************************************************" << endl << endl;
				break; // exit the loop if a valid password is entered
			}
		}
	}

	// add the name, email, and password of the user to the vector of UserList
	userProfile["Name"] = name;
	userProfile["Email"] = email;
	userProfile["Password"] = password;

	// print welcome message with the name
	cout << "** Welcome " << name << " to hacklore organization." << endl;

	// print stars
	cout << endl << "****************************************************************************************************" << endl;

	cout << endl << "** Your information has been saved successfully." << endl;

	// print stars
	cout << endl << "****************************************************************************************************" << endl;
	cout << "** YOUR INFORMATIONS *******************************************************************************" << endl << endl;

	// print the name, email, and password of the user
	for (const string& key : order) {
		cout << "** " << key << " : ";
		std::visit([](const auto& val) { cout << val << endl; }, userProfile.at(key));
	}
	
	// print stars
	cout << endl << "****************************************************************************************************" << endl;


	return 0;
}