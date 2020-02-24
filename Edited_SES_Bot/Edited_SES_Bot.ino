#include <Nextion.h>

#include <EEPROM.h>
#include "Arduino.h"
#include "SoftwareSerial.h"


SoftwareSerial HMISerial(10,11);
String courses [] = {"mecht","eee","civil","tie","marine","gegis","mech","abe","mining"};
String mechatronics_candidates[] = {"Solo"};
String eee_candidates[] = {"Maya","Debra","Kibathi","Wekesa"};
String civil_candidates[] = {"Ego"};
String tie_candidates[] = {"paddy"};
String mechanical_candidates [] = {"Muthini","Orori","Shivaji"};
String gegis_candidates[] = {"Cyrus","Mwathi","Arasa"};
String marine_mining_candidates = {"Ethan"};
String treasurer_candidates []= {"Vinolia","Makewa"};
String secgen_candidates[] = {"Nashon"};
String president_candidates[] = {"Hampton"};
String vicepresident_candidates[] = {"Koi"};
NexText cancels [18];
//People array is Intended for all the candidates
//trying to find simpler way to add all the arrays,or somethign along those lines to shorten the work after
String people[]={};


NexPage homepage = NexPage(0, 0, "homepage");
  NexButton bn_settings = NexButton(0, 1, "bn_settings");
  NexButton bn_results = NexButton(0, 2, "bn_results");
  NexButton bn_mail = NexButton(0, 3, "bn_mail");
  NexButton bn_vote = NexButton(0, 4, "bn_vote");
  NexButton bn_no_vote = NexButton(0, 5, "bn_no_vote");
  NexButton bn_no_vote1 = NexButton(0, 6, "bn_no_vote1");

NexPage courses = NexPage(1, 0, "courses");
 NexText text_mecht = NexText(1, 2, "text_mecht");
 NexText text_eee = NexText(1, 3, "text_eee");
 NexText text_civil = NexText(1, 4, "text_civil");
 NexText text_tie = NexText(1, 5, "text_tie");
 NexText text_marine = NexText(1, 6, "text_marine");
 NexText text_gegis = NexText(1, 7, "text_gegis");
 NexText text_mech = NexText(1, 8, "text_mech");
 NexText text_abe = NexText(1, 9, "text_abe");
 NexText text_cancel_1 = NexText(1, 10, "text_cancel_1");
 //incrementing the cancel buttons array. To be replicated after all other cancel buttons have been added
 //not sure about this yet though
 cancels += text_cancel_1;

NexPage mechatronics = NexPage(2, 0, "mechatronics");
 NexText text_cancel_2 = NexText(2, 1, "text_cancel_2");
 NexText text_solo = NexText(2, 3, "text_solo");

 
NexPage eee_ece = NexPage(3, 0, "eee_ece");
 NexText text_cancel_3 = NexText(3, 1, "text_cancel_3");
 NexText text_maya = NexText(3, 3, "text_maya");
 NexText text_debra = NexText(3, 4, "text_debra");
 NexText text_kibathi = NexText(3, 5, "text_kibathi");
 NexText text_wekesa = NexText(3, 6, "text_wekesa");

NexPage civil_eng = NexPage(4, 0, "civil_eng");
 NexText text_cancel_4 = NexText(4, 1, "text_cancel_4");
 NexText text_ego = NexText(4, 3, "text_ego");


NexPage tie = NexPage(5, 0, "tie");
 NexText text_cancel_5 = NexText(5, 1, "text_cancel_5");
 NexText text_paddy = NexText(5, 3, "text_paddy");


NexPage abe = NexPage(6, 0, "abe");
 NexText text_cancel_6 = NexText(6, 1, "text_cancel_6");
 NexText text_tracy = NexText(6, 3, "text_tracy");


NexPage mechanical = NexPage(7, 0, "mechanical");
 NexText text_cancel_7 = NexText(7, 1, "text_cancel_7");
 NexText text_muthini = NexText(7, 3, "text_muthini");
 NexText text_orori = NexText(7, 4, "text_orori");
 NexText text_shivaji = NexText(7, 5, "text_shivaji");

NexPage gegis = NexPage(8, 0, "gegis");
 NexText text_cancel_8 = NexText(8, 1, "text_cancel_8");
 NexText text_cyrus = NexText(8, 3, "text_cyrus");
 NexText text_mwathi = NexText(8, 4, "text_mwathi");
 NexText text_arasa = NexText(8, 5, "text_arasa");

NexPage marine_mining = NexPage(9, 0, "marine_mining");
 NexText text_cancel_9 = NexText(9, 1, "text_cancel_9");
 NexText text_ethan = NexText(9, 3, "text_ethan");

NexPage sec_gen = NexPage(10, 0, "sec_gen");
 NexText text_cancel_10 = NexText(10, 1, "text_cancel_10");
 NexText text_nashon = NexText(10, 3, "text_nashon");

NexPage treasurer = NexPage(11, 0, "treasurer");
 NexText text_cancel_11 = NexText(11, 1, "text_cancel_11");
 NexText text_vinolia = NexText(11, 3, "text_vinolia");
 NexText text_makewa = NexText(11, 4, "text_makewa");

NexPage vice_president = NexPage(12, 0, "vice_president");
 NexText text_cancel_12 = NexText(12, 1, "text_cancel_12");
 NexText text_koi = NexText(12, 3, "text_koi");

NexPage president = NexPage(13, 0, "president");
 NexText text_cancel_13 = NexText(13, 1, "text_cancel_13");
 NexText text_hampton = NexText(13, 3, "text_hampton");

NexPage thanks = NexPage(14, 0, "thanks");
 NexText text_prep = NexText(14, 2, "text_prep");

NexPage password = NexPage(15, 0, "password");
  NexButton bn_sigma = NexButton(15, 2, "bn_sigma");
  NexButton bn_gamma = NexButton(15, 3, "bn_gamma");
  NexButton bn_psi = NexButton(15, 4, "bn_psi");
  NexButton bn_phi = NexButton(15, 5, "bn_phi");
  NexButton bn_alpha = NexButton(15, 6, "bn_alpha");
  NexButton bn_epsilom = NexButton(15, 7, "bn_epsilom");
  NexButton bn_theta = NexButton(15, 8, "bn_theta");
  NexButton bn_nought = NexButton(15, 9, "bn_nought");
  NexText text_cancel_15 = NexText(15, 10, "text_cancel_15");
  NexText text_pass = NexText(15, 11, "text_pass");

NexPage results1 = NexPage(16, 0, "results1");                          //Remove Spaces
  NexText text_cancel_16 = NexText(16, 2, "text_cancel_16");
  NexText text_solo_r = NexText(16, 10, "text_solo_r");
  NexText text_maya_r = NexText(16, 14, "text_maya_r");
  NexText text_debra_r = NexText(16, 15, "text_debra_r");
  NexText text_kibathi_r = NexText(16, 16, "text_kibathi_r");
  NexText text_wekesa_r = NexText(16, 17, "text_wekesa_r");  
  NexText text_ego_r = NexText(16, 21, "text_ego");
  NexText text_paddy_r = NexText(16, 25, "text_paddy_r");
  NexButton bn_forward_16 = NexButton(16, 18, "bn_forward_16");  
  
NexPage results2 = NexPage(17, 0, "results2");
  NexText text_cancel_17 = NexText(17, 2, "text_cancel_17");
  NexText text_tracy_r = NexText(17, 9, "text_tracy_r");
  NexText text_muthini_r = NexText(17, 11, "text_muthini_r");
  NexText text_orori_r = NexText(17, 12, "text_orori_r");
  NexText text_shivaji_r = NexText(17, 13, "text_shivaji_r");
  NexText text_cyrus_r = NexText(17, 15, "text_cyrus_r");
  NexText text_mwathi_r = NexText(17, 16, "text_mwathi_r");
  NexText text_arasa_r = NexText(17, 17, "text_arasa_r");
  NexText text_ethan_r = NexText(17, 18, "text_ethan_r");
  NexButton bn_back_17 = NexButton(17, 15, "bn_back_17");
  NexButton bn_forward_17 = NexButton(17, 16, "bn_forward_17");
  
NexPage results3 = NexPage(18, 0, "results3");
  NexText text_cancel_18 = NexText(18, 2, "text_cancel_18");
  NexText text_nashon_r = NexText(18, 10, "text_nashon_r");
  NexText text_vinolia_r = NexText(18, 11, "text_vinolia_r");
  NexText text_makewa_r = NexText(18, 12, "text_makewa_r");
  NexText text_koi_r = NexText(18, 13, "text_koi_r");
  NexText text_hampton_r = NexText(18, 16, "text_hampton_r");
  NexButton bn_back_18 = NexButton(18, 15, "bn_back_18");

NexTouch *nex_listen_list[] =
{
  &homepage,
    &bn_settings,
    &bn_results,
    &bn_mail,
    &bn_vote,
    &bn_no_vote,
    &bn_no_vote1,
  
  &courses,
    &text_mecht,
    &text_eee,
    &text_civil,
    &text_tie,
    &text_marine,
    &text_gegis,
    &text_mech,
    &text_abe,
    &text_cancel_1,
    
  &mechatronics,
    &text_cancel_2,
    &text_solo,
      
  &eee_ece,
    &text_cancel_3,
    &text_maya,
    &text_debra,
    &text_kibathi,
    &text_wekesa,
    
  &civil_eng,
    &text_cancel_4,
    &text_ego,
      
  &tie,
    &text_cancel_5,
    &text_paddy,
    
  &abe,
    &text_cancel_6,
    &text_tracy,
    
  &mechanical,
    &text_cancel_7,
    &text_muthini,
    &text_orori,
    &text_shivaji,
    
  &gegis,
    &text_cancel_8,
    &text_cyrus,
    &text_mwathi,
    &text_arasa,
    
  &marine_mining,
    &text_cancel_9,
    &text_ethan,
    
  &sec_gen,
    &text_cancel_10,
    &text_nashon,
    
  &treasurer,
    &text_cancel_11,
    &text_vinolia,
    &text_makewa,
    
  &vice_president,
    &text_cancel_12,
    &text_koi,
    
  &president,
    &text_cancel_13,
    &text_hampton,
    
  &thanks,
    &text_prep,
    
  &password,
    &bn_sigma,
    &bn_gamma,
    &bn_psi,
    &bn_phi,
    &bn_alpha,
    &bn_epsilom,
    &bn_theta,
    &bn_nought,
    &text_cancel_15,
    &text_pass,
    
  &results1,
    &text_cancel_16,
    &text_solo_r,
    &text_maya_r,
    &text_debra_r,
    &text_kibathi_r,
    &text_wekesa_r,
    &text_paddy_r,
    &bn_forward_16,
    
  &results2,
    &text_cancel_17,
    &text_tracy_r,
    &text_muthini_r,
    &text_orori_r,
    &text_shivaji_r,
    &text_cyrus_r,
    &text_mwathi_r,
    &text_arasa_r,
    &text_ethan_r,
    &bn_back_17,
    &bn_forward_17,

    
  &results3,
    &text_cancel_18,
    &text_nashon_r,
    &text_vinolia_r,
    &text_makewa_r,
    &text_koi_r,
    &text_hampton_r,
    &bn_back_18,
    
  NULL
};

void setup() 
{
  // put your setup code here, to run once:
  nexInit();
  Serial.begin(9600);
  HMISerial.begin(9600);

 Serial.print("Initializing");

//Attach to function
bn_settings.attachPop(bn_settingsPopCallback);
bn_results.attachPop(bn_resultsPopCallback);
bn_mail.attachPop(bn_mailPopCallback);
bn_vote.attachPop(bn_votePopCallback);

text_mecht.attachPop(text_mechtPopCallback);
text_eee.attachPop(text_eeePopCallback);
text_civil.attachPop(text_civilPopCallback);
text_tie.attachPop(text_tiePopCallback);
text_marine.attachPop(text_marinePopCallback);
text_gegis.attachPop(text_gegisPopCallback);
text_mech.attachPop(text_mechPopCallback);
text_abe.attachPop(text_abePopCallback);


//attaching pop to all cancel buttons
for(int i=0;i<=18;i++){
  cancels[i].attachPop(text_cancelPopCallback);
}

bn_nought.attachPop(bn_noughtPopCallback);

bn_forward_16.attachPop(bn_forward_16PopCallback);
bn_forward_17.attachPop(bn_forward_17PopCallback);
bn_back_17.attachPop(bn_back_17PopCallback);
bn_back_18.attachPop(bn_back_18PopCallback);

text_solo.attachPop(text_courseRepsPopCallback);
text_maya.attachPop(text_courseRepsPopCallback);
text_debra.attachPop(text_courseRepsPopCallback);
text_kibathi.attachPop(text_courseRepsPopCallback);
text_wekesa.attachPop(text_courseRepsPopCallback);
text_ego.attachPop(text_courseRepsPopCallback);
text_paddy.attachPop(text_courseRepsPopCallback);
text_tracy.attachPop(text_courseRepsPopCallback);
text_muthini.attachPop(text_courseRepsPopCallback);
text_orori.attachPop(text_courseRepsPopCallback);
text_shivaji.attachPop(text_courseRepsPopCallback);
text_cyrus.attachPop(text_courseRepsPopCallback);
text_mwathi.attachPop(text_courseRepsPopCallback);
text_arasa.attachPop(text_courseRepsPopCallback);
text_ethan.attachPop(text_courseRepsPopCallback);
text_nashon.attachPop(text_nashonPopCallback);
text_vinolia.attachPop(text_vinoliaPopCallback);
text_makewa.attachPop(text_makewaPopCallback);
text_koi.attachPop(text_koiPopCallback);
text_hampton.attachPop(text_hamptonPopCallback);
text_prep.attachPop(text_prepPopCallback);

pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
}
//method to be called by any of the course reps components. To ensure sec_gen page shows up next
void text_courseRepsPopCallback(void *ptr){
  
  //insert code to check component id or data incoming from nextion to arduino serial, depending on what was written in HMI code
  //below assumes that the component id matches the storage location of person's address
  
  result_addition(componentid);
  sec_gen.show();
}
//method to increment result once button is clicked
void resultAddition(int id){
   int results_p = EEPROM.read(id);
    results_p = results_p + 1;
    EEPROM.write(id,results_p);
}

void text_nashonPopCallback(void *ptr)
{
  int results_p = EEPROM.read(26);
  results_p = results_p + 1;
  EEPROM.write(26,results_p);
  treasurer.show(); 
}
void text_vinoliaPopCallback(void *ptr)
{
  int results_p = EEPROM.read(27);
  results_p = results_p + 1;
  EEPROM.write(27,results_p);
  vice_president.show(); 
}
void text_makewaPopCallback(void *ptr)
{
  int results_p = EEPROM.read(28);
  results_p = results_p + 1;
  EEPROM.write(28,results_p);
  vice_president.show(); 
}
void text_koiPopCallback(void *ptr)
{
  int results_p = EEPROM.read(29);
  results_p = results_p + 1;
  EEPROM.write(29,results_p);
  president.show(); 
}
void text_hamptonPopCallback(void *ptr)
{
  int results_p = EEPROM.read(30);
  results_p = results_p + 1;
  EEPROM.write(30,results_p);
  thanks.show(); 
  digitalWrite(13, HIGH);
}

void text_cancelPopCallback(void *ptr)
{
  Serial.print("Button Pressed");
   homepage.show();
   digitalWrite(12, HIGH);
   delay(1000);
    digitalWrite(12, LOW);
}

void bn_settingsPopCallback(void *ptr)
{
  Serial.print("Button Pressed");
   password.show();
}

void bn_resultsPopCallback(void *ptr)
{
  Serial.print("Button Pressed");
   password.show();
}
void bn_mailPopCallback(void *ptr)
{
  Serial.print("Button Pressed");
   password.show();
}
void bn_votePopCallback(void *ptr)
{
  Serial.print("Button Pressed");
   courses.show();
   digitalWrite(13, LOW);
}

void text_mechtPopCallback(void *ptr)
{
  Serial.print("Button Pressed");
  mechatronics.show();
}

void text_eeePopCallback(void *ptr)
{
  Serial.print("Button Pressed");
  eee_ece.show();
}

void text_civilPopCallback(void *ptr)
{
  Serial.print("Button Pressed");
  civil_eng.show();
}

void text_tiePopCallback(void *ptr)
{
  Serial.print("Button Pressed");
  tie.show();
}

void text_marinePopCallback(void *ptr)
{
  Serial.print("Button Pressed");
  marine_mining.show();
}

void text_gegisPopCallback(void *ptr)
{
  Serial.print("Button Pressed");
  gegis.show();
}

void text_mechPopCallback(void *ptr)
{
  Serial.print("Button Pressed");
  mechanical.show();
}

void text_abePopCallback(void *ptr)
{
  Serial.print("Button Pressed");
  abe.show();
}

char buffer_password[4]={0};
String real_password="123";

boolean array_cmp(char *a, char *b, char len_a, char len_b){
     int n;

     // if their lengths are different, return false
     if (len_a != len_b) return false;

     // test each element to be the same. if not, return false
     for (n=0;n<len_a;n++) if (a[n]!=b[n]) return false;

     //ok, if we have not returned yet, they are equal :)
     return true;
}

void bn_noughtPopCallback(void *ptr)
{
  memset(buffer_password, 0, sizeof(buffer_password));
  text_pass.getText(buffer_password, sizeof(buffer_password));

  char real_password_char[4];
  real_password.toCharArray(real_password_char, 4);

  if (array_cmp(real_password_char,buffer_password,4,4) == true)
  {
    results1.show();
    load_results();              
  }
   else
  {
        sendCommand("text_pass.txt=\"Wrong Pass\"");
        delay(500);
        sendCommand("text_pass.txt=\"\"");
  }
}

void load_results()
{
 int solo_results = EEPROM.read(11);
 int maya_results = EEPROM.read(12);
 int debra_results = EEPROM.read(13);
 int kibathi_results = EEPROM.read(14);
 int wekesa_results = EEPROM.read(15);
 int ego_results = EEPROM.read(16);
 int paddy_results = EEPROM.read(17);
 int tracy_results = EEPROM.read(18);
 int muthini_results = EEPROM.read(19);
 int orori_results = EEPROM.read(20);
 int shivaji_results = EEPROM.read(21);
 int cyrus_results = EEPROM.read(22);
 int mwathi_results = EEPROM.read(23);
 int arasa_results = EEPROM.read(24);
 int ethan_results = EEPROM.read(25);
 int nashon_results = EEPROM.read(26);
 int vinolia_results = EEPROM.read(27);
 int makewa_results = EEPROM.read(28);
 int koi_results = EEPROM.read(29);
 int hampton_results = EEPROM.read(30);
 
 text_solo_r.setText(resultsDisplay(solo_results));
 text_maya_r.setText(resultsDisplay(maya_results));
 text_debra_r.setText(resultsDisplay(debra_results));
 text_kibathi_r.setText(resultsDisplay(kibathi_results));
 text_wekesa_r.setText(resultsDisplay(wekesa_results));
 text_ego_r.setText(resultsDisplay(ego_results));
 text_paddy_r.setText(resultsDisplay(paddy_results));
 text_tracy_r.setText(resultsDisplay(tracy_results));
 text_muthini_r.setText(resultsDisplay(muthini_results));
 text_orori_r.setText(resultsDisplay(orori_results));
 text_shivaji_r.setText(resultsDisplay(shivaji_results));
 text_cyrus_r.setText(resultsDisplay(cyrus_results));
 text_mwathi_r.setText(resultsDisplay(mwathi_results)); 
 text_arasa_r.setText(resultsDisplay(arasa_results)); 
 text_ethan_r.setText(resultsDisplay(ethan_results));
 text_nashon_r.setText(resultsDisplay(nashon_results));
 text_vinolia_r.setText(resultsDisplay(vinolia_results));
 text_makewa_r.setText(resultsDisplay(makewa_results));
 text_koi_r.setText(resultsDisplay(koi_results));
 text_hampton_r.setText(resultsDisplay(hampton_results));
 
 
}
//converts results into char array which can be displayed on the Nextion
char * resultsDisplay(int count){
  String countString = String(count);
  static char charBuf[4];
  countString.toCharArray(charBuf, 4); 
  return charBuf;
}

void bn_forward_16PopCallback(void *ptr)
{
  results2.show();
  load_results();
}
void bn_forward_17PopCallback(void *ptr)
{
  results3.show();
  load_results();
}
void bn_back_17PopCallback(void *ptr)
{
  results1.show();
  load_results();
}
void bn_back_18PopCallback(void *ptr)
{
  results2.show();
  load_results();
}
void text_prepPopCallback(void *ptr)
{
  homepage.show();
}

//------------------------------------------------------------------------------------
// End of Functions
//------------------------------------------------------------------------------------

void loop() 
{
  Serial.println("Checking");
  // put your main code here, to run repeatedly:
nexLoop(nex_listen_list);
}
