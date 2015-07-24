/*
  Paper organ keyboard (v0.2)
 
  Scan keyboard matrix
  
          by (c)akitam
 */

// piches
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262

// lines
#define BLACK_KEY 8
#define WHITE_KEY 9

#define SPEAKER   13

// keyboard matrix
void setup() {
  pinMode(0, INPUT_PULLUP); // C, C#
  pinMode(1, INPUT_PULLUP); // D, D#   
  pinMode(2, INPUT_PULLUP); // E
  pinMode(3, INPUT_PULLUP); // F, F#
  pinMode(4, INPUT_PULLUP); // G, G#
  pinMode(5, INPUT_PULLUP); // A, A#    
  pinMode(6, INPUT_PULLUP); // B
  pinMode(7, INPUT_PULLUP); // High-C
  
  pinMode(WHITE_KEY, INPUT);      // white key port
  pinMode(BLACK_KEY, INPUT);      // black key port
  
  pinMode(SPEAKER, OUTPUT);       // set speaker port
}

void loop() {
  
  // for White keys
  pinMode(BLACK_KEY, INPUT);
  pinMode(WHITE_KEY, OUTPUT);
  digitalWrite(WHITE_KEY,LOW); //scan White key line
  
  if(digitalRead(0) == LOW){
    tone(SPEAKER, NOTE_C3, 10);
  }else if(digitalRead(1) == LOW){
    tone(SPEAKER, NOTE_D3, 10);
  }else if(digitalRead(2) == LOW){
    tone(SPEAKER, NOTE_E3, 10);
  }else if(digitalRead(3) == LOW){
    tone(SPEAKER, NOTE_F3, 10);
  }else if(digitalRead(4) == LOW){
    tone(SPEAKER, NOTE_G3, 10);
  }else if(digitalRead(5) == LOW){
    tone(SPEAKER, NOTE_A3, 10);
  }else if(digitalRead(6) == LOW){
    tone(SPEAKER, NOTE_B3, 10);
  }else if(digitalRead(7) == LOW){
    tone(SPEAKER, NOTE_C4, 10);
  }else {
    
    // for Black keys
    pinMode(WHITE_KEY, INPUT);
    pinMode(BLACK_KEY, OUTPUT);
    digitalWrite(BLACK_KEY, LOW); //scan Black key line
    
    if(digitalRead(0) == LOW){
      tone(SPEAKER, NOTE_CS3, 10);
    }else if(digitalRead(1) == LOW){
      tone(SPEAKER, NOTE_DS3, 10);
    }else if(digitalRead(3) == LOW){
      tone(SPEAKER, NOTE_FS3, 10);
    }else if(digitalRead(4) == LOW){
      tone(SPEAKER, NOTE_GS3, 10);
    }else if(digitalRead(5) == LOW){
      tone(SPEAKER, NOTE_AS3, 10);
    }else{
      noTone(SPEAKER); // note off
    }
  }
}
