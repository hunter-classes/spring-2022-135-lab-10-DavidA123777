#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "time.h"
#include "timeslot.h"
#include "movie.h"
#include "funcs.h"


TEST_CASE("Checks the minutes since midnight function"){
  CHECK(minutesSinceMidnight({3,3}) == 183);
}
TEST_CASE("Checks the Minutes until function"){
  CHECK(minutesUntil({2,2}, {5,2}) == 180);
  CHECK(minutesUntil({1,0}, {20,0}) == 1140);
}
TEST_CASE("Checks that the add minutes function works when the time goes over 24 hours"){
Time answer = addMinutes({22,40}, 300);
  CHECK(answer.h == 3);
  CHECK(answer.m == 40);
}
TEST_CASE("Checks that a new timeslot has a starting time right after the first movie ends"){
  Movie movie1 = {"Aquaman", ACTION, 144};
  Movie movie2 = {"Legally Blonde", COMEDY, 96};
  TimeSlot morning = {movie1, {9, 15}};

  TimeSlot next = scheduleAfter(morning, movie2);
  CHECK(next.startTime.h == 11);
  CHECK(next.startTime.m == 39);

}
TEST_CASE("Both timeslots overlap by exactly one minute"){
  Movie movie1 = {"Aquaman", ACTION, 144};
  Movie movie2 = {"Legally Blonde", COMEDY, 96};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {11, 38}};
  CHECK(timeOverlap(morning, daytime) == 0);
}
TEST_CASE("The second timeslot starts right as the first one ends"){
  Movie movie1 = {"Aquaman", ACTION, 144};
  Movie movie2 = {"Legally Blonde", COMEDY, 96};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {11, 39}};
  CHECK(timeOverlap(morning, daytime) == 1);
}

TEST_CASE("Both timeslots overlap "){
  Movie movie1 = {"Aquaman", ACTION, 144};
  Movie movie2 = {"Legally Blonde", COMEDY, 96};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {11, 19}};
  CHECK(timeOverlap(morning, daytime) == 0);
}

TEST_CASE("Both timeslots don't overlap "){
  Movie movie1 = {"Aquaman", ACTION, 144};
  Movie movie2 = {"Legally Blonde", COMEDY, 96};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {11, 40}};
  CHECK(timeOverlap(morning, daytime) == 1);
}
