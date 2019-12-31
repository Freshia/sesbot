
#ifndef sesbot_h
#define sesbot_h


#include "Arduino.h"
#include "Nextion.h"

struct homepage_components_text{
    String name;
    NexText nexText;
};
struct coursepage_components_text{
    String name;
    NexText nexText;
};
struct candidate_components_text{
    String name;
    NexText nexText;
    int results;
};

void initialization();
homepage_components_text* initialize_homepage();
coursepage_components_text* initialize_courses_page();
candidate_components_text* initialize_course(String candidates [],int page_number, String course_name);
int course_candidate_callback(void *ptr,int candidate_result,NexPage nextpage);
#endif