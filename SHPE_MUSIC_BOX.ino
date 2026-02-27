//-------------------------------------
/*

Written by: Marlah Garcia - FEB 2026
Edited by: 

SHPE GITHUB WRKSP - Arduino music box!

Having copied this code from github, edit it so you can create a song of your own. 
If you want more of a challenge, try to add sharps / flats. (Use google to get Hz)
You can also edit the code for the song I put in so it's cleaner. 
Edit the time signature! World is your oyster. 

LIMITATIONS:
The speaker can only play one note at a time. Melodies only!

QUICK BACKGROUND:
I chose a song in 3/4 time which means there are three notes per measure and the quarter note gets the beat.
Think of the quarter note being the standard.
Standard time is 4/4, which means there are four notes per measure.

*/
//-------------------------------------

// NOTES (C-major scale)
#define LD_NOTE 147
#define LE_NOTE 165
#define LC_NOTE 262
#define D_NOTE 294
#define E_NOTE 330
#define F_NOTE 349
#define G_NOTE 392
#define A_NOTE 440
#define B_NOTE 494
#define HC_NOTE 524 // hz 

// Outputs 

int speaker = 5; // Speaker pin number

// Note durations (In 120BPM, Standard time [4/4 time])

int eighth_Note = 250;
int quarter_Note = 500;
int half_Note = 1000;
int whole_Note = 2000;

// Pin Modes -------------------------------------
void setup() {
  
  pinMode(speaker, OUTPUT); // Initializing speaker as an output

}

void loop() { // Song of Healing - Majora's Mask (2/4 time, C-major) 
 // Saria's Song

 // measure 1 -- Writing in measures for readability

  playNote(F_NOTE, eighth_Note);
  playNote(A_NOTE, eighth_Note);
  playNote(B_NOTE, quarter_Note);

 //measure 2

  playNote(F_NOTE, eighth_Note);
  playNote(A_NOTE, eighth_Note);
  playNote(B_NOTE, quarter_Note);

 //measure 3

  playNote(F_NOTE, eighth_Note);
  playNote(A_NOTE, eighth_Note);
  playNote(B_NOTE, eighth_Note);
  playNote(E_NOTE, eighth_Note);

 //measure 4

  playNote(D_NOTE, quarter_Note);
  playNote(B_NOTE, eighth_Note);
  playNote(HC_NOTE, eighth_Note); 

 //measure 5
 playNote(B_NOTE, eighth_Note);
 playNote(G_NOTE, eighth_Note);
 playNote(LE_NOTE, quarter_Note + quarter_Note); // measure 5 -> 6

 //measure 6

 delay(eighth_Note);
 playNote(LD_NOTE, eighth_Note);




}
// Function to make everyone's lives easy --->
// Pause play note and have proper pause between them 

void playNote(int note, int duration) { // note name, note length
  float gap_Percent = 0.10;               
  int gap = duration * gap_Percent;   // small pause between notes
  int play_Time = duration - gap;     // allows space between notes

  tone(speaker, note, play_Time); // command speaker, play the note, literal amount of time the note is playing for
  delay(play_Time); 

  noTone(speaker);
  delay(gap); // end note and small pause
}

