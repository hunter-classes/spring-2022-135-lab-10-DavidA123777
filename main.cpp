#include <iostream>
#include <string>
#include "time.h"
#include "timeslot.h"
#include "movie.h"
#include "funcs.h"

int main(){
Time time = {3, 5};
std::cout << "Task A minutes since midnight at time 03:05 is 185: " << std::endl;
std::cout << minutesSinceMidnight(time) << std::endl;
Time earlier = {2, 2};
Time later = {7, 2};
std::cout << "Task A minutes from 02:02 to 07:02 is 300 minutes = 5 hours: " << std::endl;
std::cout << minutesUntil(earlier, later) << std::endl;

Time partb = {22, 40};
int min = 300;
std::cout << "Task B add minutes to an existing time and return the Time as a variable. With a starting time of 22:40 and add 300 minutes the output is 3:40 : " << std::endl;
Time answer = addMinutes(partb, min);
std::cout << answer.h << ":" << answer.m << std::endl;


Movie movie1 = {"Aquaman", ACTION, 144};
Movie movie2 = {"Legally Blonde", COMEDY, 96};
Movie movie3 = {"The Notebook", ROMANCE, 124};
Movie movie4 = {"Escape Room", THRILLER, 100};
Movie movie5 = {"Titanic", DRAMA, 194};

std::cout << movie1.duration << std::endl;
TimeSlot morning = {movie1, {9, 15}};
TimeSlot daytime = {movie2, {11, 40}};
TimeSlot evening = {movie3, {16, 45}};
TimeSlot earliest = {movie4, {0, 0}};
TimeSlot early_morning = {movie5, {0, 0}};



std::cout << "Task C Displays start and end time for morning timeslot starting at 9:15 and ending at the duration of the movie Aquaman " << std::endl;
printTimeSlot(morning);



TimeSlot next = scheduleAfter(morning, movie2);
std::cout << "\nTask D Displays the TimeSlot created using the schedule after function and schedules the next timeslot right after the previous one (the morning timeslot)\n " << std::endl;
printTimeSlot(next);

std::cout << "\nTask E Displays if there is an overlap between two timeslots, in this case the two timeslots are separated by 0 minutes so they are just barely not overlapping and 1 is outputted as True\n " << std::endl;
std::cout << timeOverlap(morning, daytime) << std::endl;
return 0;
}
