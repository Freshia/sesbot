
#ifndef sesbot_h
#define sesbot_h


#include "Arduino.h"
#include "Nextion.h"

struct genericpage_components_text{
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
struct password_page_components_text{
    String name;
    NexButton nexButton;
};

void initialization();
genericpage_components_text* initialize_homepage();
coursepage_components_text* initialize_courses_page();
password_page_components_text* initialize_password_page();
candidate_components_text* initialize_role(String candidates [],int page_number, String course_name);
int course_candidate_callback(void *ptr,int candidate_result,NexPage nextpage);
#endif