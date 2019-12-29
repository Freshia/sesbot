
#include "sesbot.h"
#include "Nextion.h"


String courses [] = {"mecht","eee","civil","tie","marine","gegis","mech","abe","mining"};
//NexText courses_text [] = {text_mecht,text_eee,text_civil,text_tie,text_marine,text_gegis,text_mech,text_abe,text_mining};
String homepage_contents[] = {"settings","results","mail","vote","no_vote","no_vote1"};
//NexButton homepage_buttons [] = {bn_settings,bn_results,bn_mail,bn_vote,bn_no_vote,bn_no_vote1};

struct candidate{
    String name;
    String position;
    NexText nexText;
    int results;
};
struct homepage_components_text{
    String name;
    NexText nexText;
};

void initialization(){
    struct candidate *v;
    v->name = "sackey";
    String text_name = "_text";
   // v-> nexText = NexText(1, 2, text_name);
    //NexText text_mecht = NexText(1, 2, "text_mecht");
}
void initialize_homepage(){
    NexPage homepage = NexPage(0, 0, "homepage");
    int array_length = sizeof(homepage_contents)/sizeof(homepage_contents[0]);
    homepage_components_text *components_text [array_length];
    for(int  i = 0; i<=array_length;i++){
        String name_string;
        name_string += "text_";
        name_string+=homepage_contents[i];
        components_text[i] ->name = name_string;

        int n = name_string.length();
        const char char_array[n+1];
        strcpy(char_array, name_string.c_str());
        components_text[i]-> nexText= NexText(0, i+1, char_array);
    }
}
void initialize_courses_page(){
    NexPage courses_page = NexPage(1, 0, "courses");
    int array_length = sizeof(courses)/sizeof(courses[0]);
    for(int  i = 0; i<=array_length;i++){
       // courses_text[i] = NexText(0, i+2, "bn_"+courses[i]);
    }
}
