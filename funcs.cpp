#include <iostream>
#include <string>
#include "time.h"
#include "timeslot.h"
#include "movie.h"
#include "funcs.h"


int minutesSinceMidnight(Time time){
int answer = 0;
answer = 60 * time.h;
answer = answer + time.m;



return answer;
}

int minutesUntil(Time earlier, Time later){
int difference = minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
return difference;



}

Time addMinutes(Time time0, int min){
int total_minutes = 0;
total_minutes = 60 * time0.h;
total_minutes = total_minutes + time0.m;
total_minutes = total_minutes + min;

Time answer = {0,0};

answer.m = total_minutes % 60;
answer.h = (total_minutes / 60) % 24;
return answer;

}
void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)" << std::endl;
}

void printTimeSlot(TimeSlot ts){
  std::string g;
  switch (ts.movie.genre) {
      case ACTION   : g = "ACTION"; break;
      case COMEDY   : g = "COMEDY"; break;
      case DRAMA    : g = "DRAMA";  break;
      case ROMANCE  : g = "ROMANCE"; break;
      case THRILLER : g = "THRILLER"; break;
  }
  Time answer = addMinutes(ts.startTime, ts.movie.duration);


  std::cout << ts.movie.title << " " << g << " (" << ts.movie.duration << " min) [starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by " << answer.h << ":" << answer.m << "]" << std::endl;




}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){

TimeSlot new_timeslot;

Time new_start = addMinutes(ts.startTime, ts.movie.duration);
new_timeslot.startTime = new_start;
new_timeslot.movie = nextMovie;
return(new_timeslot);

}


bool timeOverlap(TimeSlot ts1, TimeSlot ts2){

int start_of_first = minutesSinceMidnight(ts1.startTime);
int end_of_first = start_of_first + ts1.movie.duration;

int start_of_second = minutesSinceMidnight(ts2.startTime);

for (int i = start_of_first; i < end_of_first; i++){
  if (start_of_second == i){
    std::cout << "Overlap" << std::endl;
    return false;
  }
}
std::cout << "No Overlap" << std::endl;
return true;

}


//switch (ts.
