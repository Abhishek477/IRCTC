# IRCTC
IRCTC like Ticket Booking System developed in C++ using Qt framework.


## DETAILS OF PROJECT:

1. LOGIN page

  User can sign up and set his username and password that can be used for login process.

  The password is stored in encrypted form in file using an encryption algorithm which enhances the security.

  Searching of username and password for verification is done using map container which is inbuilt Red Black Tree so it makes   search faster and it also keeps in mind that there are no duplicate username created.

2. System asks for date of travelling and source and destination.
   Application search for the available trains on that particular day and displays them.

   In case there are no direct trains, Application also has the facility of displaying the indirect trains between stations.    It is done efficiently by using graph algorithms avoiding the graph cycles.

3. After selecting the trains, user need to fill the passenger details and then go to payment options to get the ticket confirmed.

4. Data is stored using files

## PREREQUISITES FOR RUNNING OF PROGRAM:

For running of program and to use the created files, you should store the project files in path D:\qt\irctc3

## DEVELOPMENT:

Project is developed in Qt Creator on Windows platform.

## PROJECT CONTRIBUTORS

[Mandeep Singh](https://github.com/msdeep14) -> mandeepsinghshekhawat95@gmail.com

[Pawan Sheoran](https://github.com/pawan231) -> psheoran231@gmail.com

