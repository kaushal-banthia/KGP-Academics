Name: Kaushal Banthia
Roll Number: 19CS10039

Compiler: g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
Version: 8.1.0
Built on C++ Version: C++14

Command for using UnitTest.cpp: 
g++ Station.cpp Railways.cpp Date.cpp BookingClasses.cpp Booking.cpp Passenger.cpp UnitTest.cpp

Command for using ApplicationTest.cpp:
g++ Station.cpp Railways.cpp Date.cpp BookingClasses.cpp Booking.cpp Passenger.cpp ApplicationTest.cpp

Command for using MyApplication.cpp:
g++ Station.cpp Railways.cpp Date.cpp BookingClasses.cpp Booking.cpp Passenger.cpp MyApplicationTest.cpp

Files:
1. Station.h: Contains the application part needed to create and use a Station
2. Station.cpp: Contains the implementation details that are needed to create and use a Station
3. Railways.h: Contains the application part needed to create and use Railways (A Singleton Class)
4. Railways.cpp: Contains the implementation details that are needed to create and use Railways (A Singleton Class)
5. Passenger.h: Contains the application part needed to create Passenger (An Abstract Base Class)
6. Passenger.cpp: Contains the implementation details that are needed to create a Passenger (An Abstract Base Class)
7. Date.h: Contains the application part needed to create and use a Date
8. Date.cpp: Contains the implementation details that are needed to create and use a Date
9. BookingClasses.h: Contains the application part needed to create and use a Booking Class (An Abstract Base Class) having 7 concrete derived classes (Each of which are Singleton Classes)
10. BookingClasses.cpp: Contains the implementation part needed to create and use a Booking Class (An Abstract Base Class) having 7 concrete derived classes (Each of which are Singleton Classes)
11. Booking.h: Contains the application part needed to make a Booking
12. Booking.cpp: Contains the implementation part needed to make a Booking
13. UnitTest.cpp: Contains unit tests for all the Classes created. (For abstract base classes, their derived concrete classes are used for testing)
14. ApplicationTest.cpp: Contains application tests provided in the document for the complete program.
15. MyApplicationTest.cpp: Contains application tests created by me for the complete program.